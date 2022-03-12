const express = require('express');
const http = require('http');
const socketio = require('socket.io');
const mysql = require('mysql');

const client = mysql.createConnection({
    user : 'root',
    password : '9809',
    database : 'theater'
});

const app = express();
const bodyParser = require('body-parser');
const { type } = require('os');

const server = http.createServer(app);
const io = new socketio.Server(server);

const port = 52273;

app.use(express.static('public'));
app.use(express.json());

/* 초기 DB 추가를 위한 코드 */
// let connection = 0;
// let isEmpty = 1;
// if(connection == 0) {
//     for(let row = 0; row < 9; row ++) {
//         for(let col = 0; col < 14; col ++) {
//             if(col == 2 || col == 11) {
//                 isEmpty = 0;
//             } else if(row == 0 && col >= 5 && col <= 9) {
//                 isEmpty = 0;
//             } else {
//                 isEmpty = 1;
//             }
//             client.query('INSERT INTO seats (line, seat, isEmpty) VALUES (?,?,?)',[
//                 row, col, isEmpty
//             ], (error, result, fields)=> {
//                 if(error) {
//                     console.log('잘못된 쿼리입니다.');
//                 } else {
//                     console.log(result);
//                     console.log(fields);
//                 }
//             })
//         }
//     }
// }

// var seats = [
//     [1,1,0,1,1,0,0,0,0,1,1,0,1,1],
//     [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
//     [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
//     [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
//     [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
//     [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
//     [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
//     [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
//     [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
//     [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
//     [1,1,0,1,1,1,1,1,1,1,1,0,1,1]
// ]


// var temp2 = new Array(14);
// client.query('select * from seats', (err, result) => {
//     if(err) {
//         console.log('잘못된 쿼리입니다.')
//     } else {
//         // for(let row = 0; row < 11;row ++) {
//         //     var temp2 = new Array(14);
//         //     for(let col = 0; col < 14; col ++) {
//         //         temp2.push(data)
//         //     }
//         //     seats.push(temp2);
//         // }
//         res.send(result);
//     }
// })

/* mysql */
// client.query('select * from seats', (error, result, fields) => {
//     if(error) {
//         console.log('쿼리 문장에 에러가 있습니다.')
//     } else {
//         console.log(result);
//     }
// })

app.post('/select', (req, res) => {
    console.log(req.body);
    const row = Number(req.body.row);
    const col = Number(req.body.col);
    client.query(`select isEmpty from seats where line = ${row} and seat = ${col};`, 
    (error, result) => {
        if (error) {
            console.log('잘못된 쿼리입니다.');
        } else {
            data = result[0].isEmpty;
            console.log(data);
            if(data == 1) {
                const isEmpty = 2;
                
                client.query(`UPDATE seats SET isEmpty = ${isEmpty} where line = ${row} and seat = ${col};`, 
                (err, result, fields) => {
                    if(err) {
                        console.log(err);
                    } else {
                        console.log(result);
                    }
                })
                res.send({
                    status : 1,
                })
            } else if (data == 2) {
                res.send ({
                    status : 2,
                })
                console.log('test console');
            } 
        }
    })
})

io.on('connection', (socket) => {
    socket.on('select', (data) => {
        // seats[data.row][data.col] = 2;
        io.sockets.emit('newSelected', {
            row : data.row,
            col : data.col
        })
    })
})

var seats = new Array(11);
app.get('/status', (req, res) => {
    client.query('select * from seats', (err, result) => {
        if(err) {
            console.log('잘못된 쿼리입니다.')
        } else {
            // for(let row = 0; row < 11;row ++) {
            //     var temp2 = new Array(14);
            //     for(let col = 0; col < 14; col ++) {
            //         temp2.push(data)
            //     }
            //     seats.push(temp2);
            // }
            res.send(result);
        }
    })
});

server.listen(port, (req, res) => {
    console.log('Server running at http://127.0.0.1:52273');
});