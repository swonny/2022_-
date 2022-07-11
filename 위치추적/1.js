/*
입력
1. 전투의 개수 T
2. 간달프 군대 참여자 종족 수
호빗 - 1
인간 - 2
엘프 - 3
드워프 - 3
독수리 - 4
마법사 - 10
3. 샤우론
오크 - 1
인간 - 2
워그(늑대) - 2
고블린 - 2
우럭하이 - 3
트롤 - 5
마법사 - 10

출력
전투별 승리자

*/

const fs = require('fs');

const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n').map(Number);

// for(let i = 0; i < input[0]; i ++) {

// }

console.log(typeof(input));