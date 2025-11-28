const fs = require('fs');
const readline = require('readline');

const layers = require('./layers.json');

const CELL_WIDTH = 8; // the full width of the keycode cell
const CENTER = true;
const README_FILE = '../readme.md';
const RIGHT_PAD = CELL_WIDTH - 2;

const recordedLines = [];
let shouldRecordLine = true;

function recordLine(line) {
  if (shouldRecordLine) {
    if (line.startsWith('#### Base (`BASE`)')) {
      shouldRecordLine = false;
    } else {
      recordedLines.push(line);
    }
  }
}

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

const wrapRow = (row, joiner, leader = '|', trailer = '|', rLeader = null, rTrailer = null) => {
  const halfRow = row.length / 2;
  const firstHalf = row.slice(0, halfRow).map(placeKeycodeInCell);
  const secondHalf = row.slice(-1 * halfRow).map(placeKeycodeInCell);
  return `${leader}${firstHalf.join(joiner)}${trailer}  ${rLeader || leader}${secondHalf.join(joiner)}${rTrailer || trailer}`;
};

const collectReadmeLines = () => {
  const fileStream = fs.createReadStream(README_FILE);

  const rl = readline.createInterface({
    input: fileStream,
    crlfDelay: Infinity, // Recognize all instances of CR LF ('\r\n') as a single line break
  });

  rl.on('line', recordLine);

  rl.on('close', () => {
    console.log(`closing ${README_FILE}`);
  });
  console.log('end of collectReadmeLines');
};

const generateDivider = (cellCount) => Array(cellCount).fill(''.padStart(CELL_WIDTH, '-'));

const write = (os, output) => {
  os.write(output);
  os.write('\n');
};

const updateReadme = () => {
  const outputStream = fs.createWriteStream(README_FILE);

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
};

module.exports.collectReadmeLines = collectReadmeLines;
module.exports.recordedLines = recordedLines;
module.exports.updateReadme = updateReadme;
