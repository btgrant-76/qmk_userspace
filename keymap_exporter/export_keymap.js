const fs = require('fs');
const readline = require('readline');

const aliases = require('./keycode_aliases.json');
const layers = require('./layers.json');

/**
 * TODO
 *  - [ ] apply some kind of coherent formatting
 *  - [ ] clean up/consolidate unused codes in btgrant-76.h
 *  - [x] fix aliases that don't seem to be processed correctly
 *      - [x] KC_COMM
 *  - [x] text like '  (hold)' should be shifted to the left one space
 *  - [x] rename to something that makes more sense
 *  - [x] read only the lines for 10u
 *  - [x] probably move this into its own directory so I can have Yarn files, etc.
 *  - [x] double-check the width of all columns, especially the first
 *  - [x] remove console log statements and/or write out to a .md file
 *  - [~] is it worth writing any unit tests?
 *  - [~] replace the startsWith/endsWith usage with regex
 */

const CENTER = true
const INPUT_FILE = '../users/btgrant-76/btgrant-76.h'
const OUTPUT_FILE = 'export.md'
const CELL_WIDTH = 10 // 8 // the full width of the keycode cell
const RIGHT_PAD = CELL_WIDTH - 2 // 7 // 6

const buildUpLayers = () => {
    for (const layerId in layers) {
        const layer = layers[layerId]

        for (const rowId of ['1', '2', '3', 'THUMB']) {
            layer[rowId] = []
        }
    }
}

buildUpLayers()

const fileStream = fs.createReadStream(INPUT_FILE);

const rl = readline.createInterface({
    input: fileStream,
    crlfDelay: Infinity  // Recognize all instances of CR LF ('\r\n') as a single line break
});

let stopProcessing = false;

const findLayer = varName => {
    for (const layer in layers) {
        if (varName.includes(layer)) {
            return layer
        }
    }
    const message = `Unidentified layer: ${varName}`
    console.log(message)
    throw new Error(message)
}

const splitDefineLine = line => {
    const splits = line.split(' ').filter(w => w.length > 0)
    const commentIndex = splits.indexOf('//')

    if (commentIndex !== -1) {
        return splits.slice(0, commentIndex)
    }

    return splits
}

const processKeyCodes = keycodes => {
    return keycodes.flatMap(kc => {
        kc = kc.replace(',', '')
        const alias = aliases[kc]
        if (alias) {
            return alias.split('||')
        }

        if (kc.startsWith('KC_')) {
            return kc.replace('KC_', '')
        }

        return kc
    })
}

const placeKeycodeInCell = kc => {
    if (CENTER) {
        /* roughly center the keycode in the cell */
        const remainder = CELL_WIDTH - kc.length
        const odd = (remainder % 2) > 0
        // console.log(kc, kc.length, remainder, odd)

        let pad = 0
        if (odd) {
            pad = (remainder - 1) / 2
        } else {
            pad = remainder / 2
        }

        return kc
            .padStart(CELL_WIDTH - pad)
            .padEnd(CELL_WIDTH)
    } else {
        /* roughly place the keycode in the cell with relatively uniform padding on the left edge */
        if (kc.length === RIGHT_PAD) {
            // console.log(kc)
            return kc.padEnd(RIGHT_PAD + 1/*, '_'*/).padStart(CELL_WIDTH/*, '_'*/)
        }
        return kc.padEnd(RIGHT_PAD/*, '_'*/).padStart(CELL_WIDTH/*, '_'*/)
    }
}

const processDefine = line => {
    const splits = splitDefineLine(line)
    const varName = splits[1]
    if (varName.startsWith('___')) {
        const layerId = findLayer(varName)
        if (!layerId) {
            return
        }

        const splitVarName = varName.split('_').filter(w => w.length > 0)
        const rowId = splitVarName[1]
        const keycodes = processKeyCodes(splits.slice(2)).map(placeKeycodeInCell)
        const row = layers[layerId][rowId]
        layers[layerId][rowId] = row.concat(keycodes)
    } else if (line.includes('//:')) { // #define with an alias
        const keycode = splits[1]
        const alias = splits[splits.length - 1].replace('//:', '').replace('_', ' ')
        if (keycode.includes(',')) {
            // TODO what?
        } else {
            aliases[keycode] = alias
        }
    }
}

const processLine = rawLine => {
    const trimmed = rawLine.trim();
    if (trimmed.length === 0) {
        return
    }
    if (!stopProcessing) {
        if (trimmed.startsWith('/** 12u **/')) {
            stopProcessing = true
        // } else if ((trimmed.startsWith('/* ') && trimmed.endsWith(' */')) || trimmed.startsWith('//')) {
        //     // console.log('comment', trimmed)
        } else if (trimmed.startsWith('#define')) {
            processDefine(trimmed)
        }
    }
}

rl.on('line', (line) => {
    processLine(line)
});

const wrapRow = (row, joiner, leader = '|', trailer = '|', rLeader = null, rTrailer = null) => {
    const halfRow = row.length / 2
    const firstHalf = row.slice(0, halfRow)
    const secondHalf = row.slice(-1 * halfRow)
    return `${leader}${firstHalf.join(joiner)}${trailer}  ${rLeader ? rLeader : leader }${secondHalf.join(joiner)}${rTrailer ? rTrailer : trailer}`
}

const generateDivider = cellCount => Array(cellCount).fill(''.padStart(CELL_WIDTH, '-'))

const write = (os, output) => {
    os.write(output)
    os.write('\n')
}

rl.on('close', () => {
    const outputStream = fs.createWriteStream(OUTPUT_FILE);

    for (const layer in layers) {
        const l = layers[layer]

        const sectionTitle = `#### ${l.name} (\`${layer}\`)\n`
        write(outputStream, sectionTitle)
        write(outputStream, '```text')
        const lOne = l[1]
        const lTwo = l[2]
        const lThree = l[3]
        const lThumb = l['THUMB']

        const leftThumbPadding = Array(2).fill(''.padStart(CELL_WIDTH, ' '))

        const divider = generateDivider(10)

        const longDivider = Array(10).fill(''.padStart(CELL_WIDTH, '-'))
        write(outputStream, wrapRow(longDivider, '+', '/', '\\'))
        write(outputStream, wrapRow(lOne, '|')) // , '|', '/', '\\'))
        write(outputStream, wrapRow(divider, '+'))
        write(outputStream, wrapRow(lTwo, '|'))
        write(outputStream, wrapRow(divider, '+'))
        write(outputStream, wrapRow(lThree, '|'))
        write(outputStream, wrapRow(longDivider, '+', '\\', '|', '|', '/'))
        write(outputStream, `${leftThumbPadding.join(' ')} ${wrapRow(lThumb, '|')}`)
        write(outputStream, `${leftThumbPadding.join(' ')} ${wrapRow(generateDivider(6), '+', '\\', '/')}`)
        write(outputStream, '```\n')
    }
    console.log('File reading completed.');
});
