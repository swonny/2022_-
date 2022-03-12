const fs = require('fs');

const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let cnt = 0;
const cars = input[1].toString().split(' ').forEach( (car) => {
    car == input[0] ? cnt++ : false;
});

console.log(cnt);