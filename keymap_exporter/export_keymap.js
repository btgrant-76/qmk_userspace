const fs = require('fs');
const readline = require('readline');

const { collectReadmeLines, recordedLines } = require('./readme-reader');
const aliases = require('./keycode_aliases.json');
const layers = require('./layers.json');

const ALIAS_PREFIX = '//:';
const CENTER = true;
const INPUT_FILE = '../users/btgrant-76/btgrant-76.h';
const OUTPUT_FILE = '../readme.md';
const CELL_WIDTH = 8; // the full width of the keycode cell
const RIGHT_PAD = CELL_WIDTH - 2;

/* SET UP */
collectReadmeLines();

const buildUpLayers = () => {
  Object.keys(layers).forEach((layerId) => {
    const layer = layers[layerId];

    ['1', '2', '3', 'THUMB'].forEach((rowId) => {
      layer[rowId] = [];
    });
  });
};

buildUpLayers();

/* READ IN */
const fileStream = fs.createReadStream(INPUT_FILE);

const rl = readline.createInterface({
  input: fileStream,
  crlfDelay: Infinity, // Recognize all instances of CR LF ('\r\n') as a single line break
});

const findLayer = (varName) => {
  let maybeLayer = null;
  Object.keys(layers).forEach((layer) => {
    if (varName.includes(layer)) {
      maybeLayer = layer;
    }
  });

  if (maybeLayer) {
    return maybeLayer;
  }
  const message = `Unidentified layer: ${varName}`;
  throw new Error(message);
};

const splitDefineLine = (line) => {
  const splits = line.split(' ').filter((w) => w.length > 0);
  const commentIndex = splits.indexOf('//');

  if (commentIndex !== -1) {
    return splits.slice(0, commentIndex);
  }

  return splits;
};

const processKeyCodes = (keycodes) => keycodes.flatMap((kc) => {
  const updatedKc = kc.replace(',', '');
  const alias = aliases[updatedKc];
  if (alias) {
    return alias.split('||');
  }

  if (updatedKc.startsWith('KC_')) {
    return updatedKc.replace('KC_', '');
  }

  return updatedKc;
});

const placeKeycodeInCell = (kc) => {
  if (CENTER) {
    /* roughly center the keycode in the cell */
    const remainder = CELL_WIDTH - kc.length;
    const odd = (remainder % 2) > 0;

    let pad = 0;
    if (odd) {
      pad = (remainder - 1) / 2;
    } else {
      pad = remainder / 2;
    }

    return kc
      .padStart(CELL_WIDTH - pad)
      .padEnd(CELL_WIDTH);
  }

  /* roughly place the keycode in the cell with relatively uniform padding on the left edge */
  if (kc.length === RIGHT_PAD) {
    return kc.padEnd(RIGHT_PAD + 1).padStart(CELL_WIDTH);
  }
  return kc.padEnd(RIGHT_PAD).padStart(CELL_WIDTH);
};

const processDefine = (line) => {
  const splits = splitDefineLine(line);
  const varName = splits[1];
  if (varName.startsWith('___')) {
    const layerId = findLayer(varName);
    if (!layerId) {
      return;
    }

    const splitVarName = varName.split('_').filter((w) => w.length > 0);
    const rowId = splitVarName[1];
    const keycodes = processKeyCodes(splits.slice(2)).map(placeKeycodeInCell);
    const row = layers[layerId][rowId];
    layers[layerId][rowId] = row.concat(keycodes);
  } else if (line.includes(ALIAS_PREFIX)) { // #define with an alias
    const keycode = splits[1];
    const alias = splits[splits.length - 1].replace(ALIAS_PREFIX, '').replace('_', ' ');
    if (keycode.includes(',')) {
      // TODO what?
    } else {
      aliases[keycode] = alias;
    }
  }
};

let stopProcessing = false;

const processLine = (rawLine) => {
  const trimmed = rawLine.trim();
  if (trimmed.length === 0) {
    return;
  }
  if (!stopProcessing) {
    if (trimmed.startsWith('/** 12u **/')) {
      stopProcessing = true;
    } else if (trimmed.startsWith('#define')) {
      processDefine(trimmed);
    }
  }
};

rl.on('line', processLine);

/* WRITE OUT */
const wrapRow = (row, joiner, leader = '|', trailer = '|', rLeader = null, rTrailer = null) => {
  const halfRow = row.length / 2;
  const firstHalf = row.slice(0, halfRow);
  const secondHalf = row.slice(-1 * halfRow);
  return `${leader}${firstHalf.join(joiner)}${trailer}  ${rLeader || leader}${secondHalf.join(joiner)}${rTrailer || trailer}`;
};

const generateDivider = (cellCount) => Array(cellCount).fill(''.padStart(CELL_WIDTH, '-'));

const write = (os, output) => {
  os.write(output);
  os.write('\n');
};

rl.on('close', () => {
  const outputStream = fs.createWriteStream(OUTPUT_FILE);

  recordedLines.forEach((line) => {
    write(outputStream, line);
  });

  Object.keys(layers).forEach((layer) => {
    const l = layers[layer];

    const sectionTitle = `#### ${l.name} (\`${layer}\`)\n`;
    write(outputStream, sectionTitle);
    write(outputStream, '```text');
    const lOne = l[1];
    const lTwo = l[2];
    const lThree = l[3];
    const lThumb = l.THUMB;

    const leftThumbPadding = Array(2).fill(''.padStart(CELL_WIDTH, ' '));

    const divider = generateDivider(10);

    const longDivider = Array(10).fill(''.padStart(CELL_WIDTH, '-'));
    write(outputStream, wrapRow(longDivider, '+', '/', '\\'));
    write(outputStream, wrapRow(lOne, '|')); // , '|', '/', '\\'))
    write(outputStream, wrapRow(divider, '+'));
    write(outputStream, wrapRow(lTwo, '|'));
    write(outputStream, wrapRow(divider, '+'));
    write(outputStream, wrapRow(lThree, '|'));
    write(outputStream, wrapRow(longDivider, '+', '\\', '|', '|', '/'));
    write(outputStream, `${leftThumbPadding.join(' ')} ${wrapRow(lThumb, '|')}`);
    write(outputStream, `${leftThumbPadding.join(' ')} ${wrapRow(generateDivider(6), '+', '\\', '/')}`);
    write(outputStream, '```\n');
  });
  console.log('File reading completed.');
});
