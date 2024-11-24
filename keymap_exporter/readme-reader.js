const fs = require('fs');
const readline = require('readline');

const INPUT_FILE = '../readme.md';

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

const collectReadmeLines = () => {
  const fileStream = fs.createReadStream(INPUT_FILE);

  const rl = readline.createInterface({
    input: fileStream,
    crlfDelay: Infinity, // Recognize all instances of CR LF ('\r\n') as a single line break
  });

  rl.on('line', recordLine);

  rl.on('close', () => {
    console.log(`closing ${INPUT_FILE}`);
  });
  console.log('end of collectReadmeLines');
};

module.exports.collectReadmeLines = collectReadmeLines;
module.exports.recordedLines = recordedLines;
