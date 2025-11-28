const { createWriteStream } = require('fs');
const yaml = require('js-yaml');

const OUTPUT_FILE = './keymap-drawer-';

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

const generateKDLayers = (layers, rowKeys) => {
  const keymapLayers = {};
  Object.keys(layers).forEach((layerId) => { // TODO can this be refactored to use map or similar?
    const curLayer = layers[layerId];
    keymapLayers[layerId] = rowKeys.map((rowKey) => curLayer[rowKey].map(toKeyboardDrawerKey));
  });

  return keymapLayers;
};

module.exports = (layerDefinitions) => {
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
      layers: generateKDLayers(layerDefinitions, config.rowKeys),
    };
    const outputStream = createWriteStream(`${OUTPUT_FILE}${config.name}.yaml`);
    outputStream.write(yaml.dump(keymap));
  });
};
