const fs = require('fs');

const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('/').map(Number);
// for(let i = 0; i < input.length; i ++) {
//     input[i] = parseInt(input[i]);
// }

const msg = (input[0] + input[2]) < input[1] || input[1] == 0 ? 'hasu' : 'gosu';
console.log(msg);
