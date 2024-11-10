const fs = require('fs');
const readline = require('readline');
const aliases = require('./keycodeAliases.json');

/**
 * TODO
 *  - [ ] rename to something that makes more sense
 *  - [x] read only the lines for 10u
 *  - [ ] replace the startsWith/endsWith usage with regex
 *  - [ ] probably move this into its own directory so I can have Yarn files, etc.
 *  - [ ] clean up/consolidate unused codes in btgrant-76.h
 *  - [x] double-check the width of all columns, especially the first
 *  - [ ] apply some kind of coherent formatting
 *  - [ ] fix aliases that don't seem to be processed correctly
 *      - [ ] KC_COMM
 *  - [ ] is it worth writing any unit tests?
 *  - [ ] text like '  (hold)' should be shifted to the left one space
 *  - [ ] remove console log statements and/or write out to a .md file
 */

const OUTPUT_FILE = 'keymap.md'

const badlyNamedThings = ['HRM']

const layers = {
    BASE: {
        name: 'Base',
    },
    NUM: {
        name: 'Number',
    },
    SYM: {
        name: 'Symbol',
    },
    NAV: {
        name: 'Navigation',
    },
    FUN: {
        name: 'Function',
    },
    MSE: {
        name: 'Mouse Keys',
    },
    ADD: {
        name: 'Additional Features',
    }
}

const buildUpLayers = () => {
    for (const layerId in layers) {
        // console.log(layerId)
        const layer = layers[layerId]

        for (const rowId of ['1', '2', '3', 'THUMB']) {
            layer[rowId] = []
        }
    }
}

buildUpLayers()

const fileStream = fs.createReadStream('../users/btgrant-76/btgrant-76.h');

const rl = readline.createInterface({
    input: fileStream,
    crlfDelay: Infinity  // Recognize all instances of CR LF ('\r\n') as a single line break
});

let stopProcessing = false;

const findLayer = varName => {
    for (const layer in layers) {
        // console.log(layer);
        if (varName.includes(layer)) {
            return layer
        }
    }
    console.log('unidentified layer!', varName) //
    return null

    // throw new Error(`Unidentified layer: ${varName}`)
    // return 'UNIDENTIFIED' // TODO throw an error?
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
    const updatedKeycodes = keycodes.flatMap(kc => {
        kc = kc.replace(',', '')

        if (aliases[kc]) {
            return aliases[kc].split(',') // FIXME this splits the alias ", <"
        }

        if (kc.startsWith('KC_')) {
            return kc.replace('KC_', '')
        }

        return kc
    })

    return updatedKeycodes
}

const RIGHT_PAD = 6
const CELL_WIDTH = 8 // the  full width of the keycode cell

const processDefine = line => {
    const splits = splitDefineLine(line)
    const varName = splits[1]
    if (varName.startsWith('___')) {
        const layerId = findLayer(varName)

        if (!layerId) {
            console.log('skipping', layerId)
            return
        }

        const splitVarName = varName.split('_').filter(w => w.length > 0)

        const rowId = splitVarName[1]
        const keycodes = processKeyCodes(splits.slice(2)).map(kc => kc.padEnd(RIGHT_PAD/*, '_'*/).padStart(CELL_WIDTH/*, '_'*/))
        console.log('layer define', layerId, rowId, keycodes)

        // TODO refactor the following lines
        const layer = layers[layerId]
        const row = layer[rowId]
        layers[layerId][rowId] = row.concat(keycodes)
    } else if (line.includes('//:')) { // define with an alias
        const keycode = splits[1]
        console.log('found alias', keycode)
        const alias = splits[splits.length - 1].replace('//:', '').replace('_', ' ')
        if (keycode.includes(',')) {

        } else {
            aliases[keycode] = alias
        }
    } else {
        // console.log('ordinary define', line);
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
        } else if ((trimmed.startsWith('/* ') && trimmed.endsWith(' */')) || trimmed.startsWith('//')) {
            // console.log('comment', trimmed)
        } else if (trimmed.startsWith('#define')) {
            processDefine(trimmed)
        } else {
            console.log('processing', trimmed)
        }
    } else {
        // console.log('stopped', trimmed)
    }
}


rl.on('line', (line) => {
    // if (line.startsWith('/** 12u **/'))
    // console.log(line);
    processLine(line)
});

// TODO update to starting/leading characters like '/', '\' and '|'
const wrapRow = (row, joiner, leader = '|', trailer = '|', rLeader = null, rTrailer = null) => {
    // console.log('wrap row length', row.length)
    const halfRow = row.length / 2
    const firstHalf = row.slice(0, halfRow)
    const secondHalf = row.slice(-1 * halfRow)
    // return `|${row.join('|')}|`
    return `${leader}${firstHalf.join(joiner)}${trailer}  ${rLeader ? rLeader : leader }${secondHalf.join(joiner)}${rTrailer ? rTrailer : trailer}`
}

// const generateDivider = cellCount => `|${Array(cellCount).fill(''.padStart(CELL_WIDTH, '-')).join('+')}|`
const generateDivider = cellCount => Array(cellCount).fill(''.padStart(CELL_WIDTH, '-'))

rl.on('close', () => {
    console.log('finished', aliases)

    // TODO split all these down the middle

    const outputStream = fs.createWriteStream(OUTPUT_FILE); // TODO stop console.logging and write to this!

    for (const layer in layers) {
        const l = layers[layer]

        const sectionTitle = `#### ${l.name} (\`${layer}\`)\n`
        // console.log(sectionTitle)
        outputStream.write(sectionTitle)
        outputStream.write('\n')
        // console.log('```text')
        outputStream.write('```text\n')
        const lOne = l[1]
        const lTwo = l[2]
        const lThree = l[3]
        const lThumb = l['THUMB']

        const leftThumbPadding = Array(2).fill(''.padStart(CELL_WIDTH, ' '))

        const divider = generateDivider(10) // TODO parameterize this so it can be used for the thumb row, too
        // console.log(divider)

        const longDivider = Array(10).fill(''.padStart(CELL_WIDTH, '-'))
        // console.log(wrapRow(Array(10).fill(''.padStart(CELL_WIDTH, '-')), '+', '/', '\\'))
        // console.log(wrapRow(longDivider, '+', '/', '\\'))
        // console.log(wrapRow(lOne, '|')) // , '|', '/', '\\'))
        // console.log(wrapRow(divider, '+'))
        // console.log(wrapRow(lTwo, '|'))
        // console.log(wrapRow(divider, '+'))
        outputStream.write(wrapRow(longDivider, '+', '/', '\\'))
        outputStream.write('\n')
        outputStream.write(wrapRow(lOne, '|')) // , '|', '/', '\\'))
        outputStream.write('\n')
        outputStream.write(wrapRow(divider, '+'))
        outputStream.write('\n')
        outputStream.write(wrapRow(lTwo, '|'))
        outputStream.write('\n')
        outputStream.write(wrapRow(divider, '+'))
        outputStream.write('\n')
        // console.log(divider)
        // console.log(wrapRow(lThree, '|'))
        outputStream.write(wrapRow(lThree, '|'))
        outputStream.write('\n')
        // console.log(divider)
        // console.log(wrapRow(longDivider, '+', '\\', '|', '|', '/'))
        // console.log(`${leftThumbPadding.join(' ')} ${wrapRow(lThumb, '|')}`)
        // console.log(`${leftThumbPadding.join(' ')} ${wrapRow(generateDivider(6), '+', '\\', '/')}`)
        // console.log('```\n')
        outputStream.write(wrapRow(longDivider, '+', '\\', '|', '|', '/'))
        outputStream.write('\n')
        outputStream.write(`${leftThumbPadding.join(' ')} ${wrapRow(lThumb, '|')}`)
        outputStream.write('\n')
        outputStream.write(`${leftThumbPadding.join(' ')} ${wrapRow(generateDivider(6), '+', '\\', '/')}`)
        outputStream.write('\n')
        outputStream.write('```\n')
        outputStream.write('\n')
    }



    console.log('File reading completed.');
});
