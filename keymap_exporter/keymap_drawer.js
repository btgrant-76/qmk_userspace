const { createWriteStream } = require('fs');
const yaml = require('js-yaml');

const OUTPUT_FILE = './keymap-drawer-';

/*
 TODO can all of the aliases in btgrant.h be moved to keycode_aliases.json?
 TODO at some point the Keymap Drawer use of glyphs is going to make the aliases
  JSON file completely unusable by readme.js. Rename it so it's aligned with this file.
 */

const toKeyboardDrawerKey = (key) => {
  if (typeof key === 'object') {
    return key;
  }

  if (key.includes('/')) {
    if (key.includes('_/_')) {
      return key.replace('_/_', '/');
    }

    const splits = key.split('/');
    if (splits.length === 2) {
      if (splits[0].length === 0 || splits[1].length === 0) {
        return key;
      }
      return { h: splits[1], t: splits[0] };
    } if (splits.length === 3) {
      return { h: splits[2], t: '/' };
    }
  }

  if (key === '(hold)') {
    return { type: 'held' };
  }
  return key;
};

const generateKDLayers = (layers, rowKeys) => {
  const keymapLayers = {};

  Object.keys(layers).forEach((layerId) => {
    const curLayer = layers[layerId];
    keymapLayers[`${curLayer.name} (${layerId})`] = rowKeys.map((rowKey) => curLayer[rowKey].map(toKeyboardDrawerKey));
  });

  return keymapLayers;
};

module.exports = (layerDefinitions) => {
  const drawConfig = {
    dark_mode: 'auto',
    footer_text: 'Drawn by Keymap Drawer',
    shrink_wide_legends: 6,
  };
  const outputConfigs = [
    {
      layout: {
        qmk_keyboard: 'corne_rotated',
        layout_name: 'LAYOUT_split_3x5_3',
      },
      drawConfig,
      rowKeys: [1, 2, 3, 'THUMB'],
      name: '3x5x3',
    },
    {
      layout: {
        qmk_keyboard: 'forager',
        layout_name: 'default_layout',
      },
      drawConfig,
      combos: [
        { p: [30, 31], k: 'FUN', layers: ['Base (BASE)'] },
        { p: [32, 33], k: 'SYM', layers: ['Base (BASE)'] },
      ],
      rowKeys: [1, 2, 3, '4THUMB'],
      name: '3x5x2',
    },
  ];

  outputConfigs.forEach((config) => {
    const keymap = {
      layout: config.layout,
      draw_config: config.drawConfig,
      layers: generateKDLayers(layerDefinitions, config.rowKeys),
      combos: config.combos || [],
    };
    const outputStream = createWriteStream(`${OUTPUT_FILE}${config.name}.yaml`);
    outputStream.write(yaml.dump(keymap));
  });
};
