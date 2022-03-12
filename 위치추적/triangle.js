const fs = require('fs');

const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n').map(Number);

if(input[0] === 60 && input[1] === 60 && input[2] === 60) {
    console.log('Equilateral');
} else {
    const init = 0;
    const sum = input.reduce((prev, curr) => prev + curr, init);
    if(sum == 180) {
        if(input[0] === input[1] || input[1] === input[2] || input[0] == input[2]) {
            console.log('Isosceles');
        }
        else {
            console.log('Scalene');
        }
    } else {
        console.log('Error');
    }
}