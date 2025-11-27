const fs = require('fs');
const readline = require('readline');
const yaml = require('js-yaml');

const { collectReadmeLines, recordedLines } = require('./readme-reader');
const aliases = require('./keycode_aliases.json');
const layers = require('./layers.json');

const ALIAS_PREFIX = '//:';
const CENTER = true;
const INPUT_FILE = '../users/btgrant/btgrant.h';
const OUTPUT_FILE = '../readme.md';
const KD_OUTPUT_FILE = './keymap-drawer-';
const CELL_WIDTH = 8; // the full width of the keycode cell
const RIGHT_PAD = CELL_WIDTH - 2;

/* SET UP */
collectReadmeLines();

const buildUpLayers = () => {
  Object.keys(layers).forEach((layerId) => {
    const layer = layers[layerId];

    ['1', '2', '3', 'THUMB', '4THUMB'].forEach((rowId) => {
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

const toKeyboardDrawerKey = (key) => {
  const trimmed = key.trim();
  if (trimmed.includes('/')) {
    const splits = trimmed.split('/');
    if (splits.length === 2) {
      return { h: splits[1], t: splits[0] };
    }
  }

  if (trimmed === '(hold)') {
    return { type: 'held' };
  }
  return trimmed;
};

// FIXME resolve this error re:  layers
const generateKDLayers = (layers, rowKeys) => {
  const keymapLayers = {};
  Object.keys(layers).forEach((layerId) => {
    const curLayer = layers[layerId];
    // console.log(layerId);
    const stuff = rowKeys.map((rowKey) => // FIXME flatMap?
      // console.log(`rowKey: ${rowKey} for layer ${layerId}`);
      // console.log(curLayer[rowKey]);
      // keymapLayers[layerId] = curLayer[rowKey];
      curLayer[rowKey].map(toKeyboardDrawerKey));

    keymapLayers[layerId] = stuff;

    // console.log(`STUFF for ${layerId}`, stuff, stuff.length);
  });

  // console.log('keymapLayers', keymapLayers);

  return keymapLayers;
};

const generateKeyboardDrawerOutput = (o) => {
  /* const theLoad = {
    layout: {
      // qmk_keyboard: 'corne_rotated',
      // layout_name: 'LAYOUT_split_3x5_3',
      qmk_keyboard: 'forager',
      layout_name: 'LAYOUT',
      //  this requires an extra key between T and Y for the encoder
      // qmk_keyboard: 'tominabox1/le_chiffre/rev2',
      // layout_name: 'LAYOUT',
    },
  }; */

  const outputConfigs = [
    {
      layout: {
        qmk_keyboard: 'corne_rotated',
        layout_name: 'LAYOUT_split_3x5_3',
      },
      rowKeys: [1, 2, 3, 'THUMB'],
      name: '3x5x3',
    },
    {
      layout: {
        qmk_keyboard: 'forager',
        layout_name: 'default_layout',
      },
      rowKeys: [1, 2, 3, '4THUMB'],
      name: '3x5x2',
    },
  ];

  outputConfigs.forEach((config) => {
    const keymap = {
      layout: config.layout,
      layers: generateKDLayers(layers, config.rowKeys),
    };
    const outputStream = fs.createWriteStream(`${KD_OUTPUT_FILE}${config.name}.yaml`);
    // console.log(yaml.dump(theLoad));
    outputStream.write(yaml.dump(keymap));
  });

  /* const outputLayers = {};

  Object.keys(layers).forEach((layer) => { // TODO map instead of forEach?
    const curLayer = layers[layer];

    const rowOne = curLayer[1];
    const rowTwo = curLayer[2];
    const rowThree = curLayer[3];
    // const thumbs = curLayer.THUMB;
    // const fourThumbs = curLayer['4THUMB'];
    const thumbs = curLayer['4THUMB'];

    const rows = [
      rowOne.map(toKeyboardDrawerKey),
      rowTwo.map(toKeyboardDrawerKey),
      rowThree.map(toKeyboardDrawerKey),
      thumbs.map(toKeyboardDrawerKey),
    ];

    outputLayers[layer] = rows;
  });

  theLoad.layers = outputLayers;

  const outputStream = fs.createWriteStream(KD_OUTPUT_FILE);
  // console.log(yaml.dump(theLoad));
  outputStream.write(yaml.dump(theLoad)); */
};

rl.on('close', () => {
  const outputStream = fs.createWriteStream(OUTPUT_FILE);

  /* Markdown processing:  begin */
  // TODO probably refactor all of the Markdown-specific parts
  recordedLines.forEach((line) => {
    write(outputStream, line);
  });

  Object.keys(layers).forEach((layer) => {
    const curLayer = layers[layer];

    const sectionTitle = `#### ${curLayer.name} (\`${layer}\`)\n`;
    write(outputStream, sectionTitle);
    write(outputStream, '```text');
    const rowOne = curLayer[1];
    const rowTwo = curLayer[2];
    const rowThree = curLayer[3];
    const thumbs = curLayer.THUMB;
    const fourThumbs = curLayer['4THUMB'];

    const divider = generateDivider(10);

    const longDivider = Array(10).fill(''.padStart(CELL_WIDTH, '-'));
    write(outputStream, wrapRow(longDivider, '+', '/', '\\'));
    write(outputStream, wrapRow(rowOne, '|')); // , '|', '/', '\\'))
    write(outputStream, wrapRow(divider, '+'));
    write(outputStream, wrapRow(rowTwo, '|'));
    write(outputStream, wrapRow(divider, '+'));
    write(outputStream, wrapRow(rowThree, '|'));
    write(outputStream, wrapRow(longDivider, '+', '\\', '|', '|', '/'));

    // 6 thumbs
    const leftThumbPadding = Array((rowOne.length - thumbs.length) / 2).fill(''.padStart(CELL_WIDTH, ' '));
    write(outputStream, `${leftThumbPadding.join(' ')} ${wrapRow(thumbs, '|')}`);
    write(outputStream, `${leftThumbPadding.join(' ')} ${wrapRow(generateDivider(thumbs.length), '+', '\\', '/')}`);

    // 4 thumbs
    write(outputStream, '\n# Four-thumb variation');

    const fourThumbPadding = Array((rowOne.length - fourThumbs.length) / 2).fill(''.padStart(CELL_WIDTH, ' '));
    write(outputStream, `${fourThumbPadding.join(' ')} ${wrapRow(generateDivider(fourThumbs.length), '+', '/', '\\')}`);
    write(outputStream, `${fourThumbPadding.join(' ')} ${wrapRow(fourThumbs, '|')}`);
    write(outputStream, `${fourThumbPadding.join(' ')} ${wrapRow(generateDivider(fourThumbs.length), '+', '\\', '/')}`);

    write(outputStream, '```\n');
    /* Markdown processing:  end */
  });
  // console.log('File reading completed.');

  generateKeyboardDrawerOutput();
});
