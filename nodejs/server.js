// var express = require('express')

// var app = express()
// app.use(express.static('public'))
// app.use(express.urlencoded({ extended : false }))
// const port = 52273

// app.listen(port, (req, res) => {
//     console.log('Server running at http://127.0.0.1:52273')
// })

var temp1 = new Array(5);

for(let i = 0; i < 5; i ++) {
    var temp2 = new Array(10);
    for(let j = 0; j < 10; j ++) {
        temp2.push(j);
    }
    temp1.push(temp2);
}

console.log(temp1);