const { createReadStream } = require('fs');
const { createInterface } = require('readline');

// const { collectReadmeLines, updateReadme } = require('./readme');
const generateKeyboardDrawerOutput = require('./keymap_drawer');
const aliases = require('./keycode_aliases.json');
const layerDefinitions = require('./layers.json');

const ALIAS_PREFIX = '//:';
const INPUT_FILE = '../users/btgrant/btgrant.h';

/* SET UP */
const buildUpLayers = () => {
  Object.keys(layerDefinitions).forEach((layerId) => {
    const layer = layerDefinitions[layerId];
    ['1', '2', '3', 'THUMB', '4THUMB'].forEach((rowId) => {
      layer[rowId] = [];
    });
  });
};

// collectReadmeLines();
buildUpLayers();

/* READ IN */
const fileStream = createReadStream(INPUT_FILE);

const rl = createInterface({
  input: fileStream,
  crlfDelay: Infinity, // Recognize all instances of CR LF ('\r\n') as a single line break
});

const findLayer = (varName) => {
  let maybeLayer = null;
  Object.keys(layerDefinitions).forEach((layer) => {
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
    if (typeof alias === 'object') {
      return alias;
    }

    return alias.split('||');
  }

  if (updatedKc.startsWith('KC_')) {
    return updatedKc.replace('KC_', '');
  }

  return updatedKc;
});

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
    const keycodes = processKeyCodes(splits.slice(2));
    const row = layerDefinitions[layerId][rowId];
    layerDefinitions[layerId][rowId] = row.concat(keycodes);
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
    if (trimmed.startsWith('/*** six thumbs shifted ***/')) {
      stopProcessing = true;
    } else if (trimmed.startsWith('#define')) {
      processDefine(trimmed);
    }
  }
};

rl.on('line', processLine);

/* WRITE OUT */
rl.on('close', () => {
  // updateReadme();
  generateKeyboardDrawerOutput(layerDefinitions);
});
