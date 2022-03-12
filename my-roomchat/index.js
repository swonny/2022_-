const express = require('express')
const app = express();
const http = require('http')
const { disconnect } = require('process')
const socketio = require('socket.io')
const mysql = require('mysql');
// const bodyParser = require('body-parser');
// app.use(bodyParser.urlencoded({ extended : false }))

const client = mysql.createConnection ( {
    user : 'root',
    password : '9809',
    database : 'roomchat',
})

const port = 52273

const server = http.createServer(app)
const io = new socketio.Server(server)

app.use(express.static('public'));
app.use(express.json());

/* 회원가입 서버 */
app.post('/signup', (req, res) => {
    const query = 'INSERT INTO clients (name, userPwd, userId) VALUES (?,?,?)'
    client.query(query, [req.body.userName, req.body.password, req.body.email], 
        (err, result) => {
            if(err) {
                console.log(err);
            } else {
                console.log('회원가입 성공했습니다.');
                res.send(true);
            }
        })
})

/* 로그인 서버 */
const nameList = new Array();

app.post('/login', (req, res) => {
    console.log(req.body.userId);
    console.log(req.body.userPwd);
    const query = `SELECT * FROM clients WHERE userId LIKE '${req.body.userId}' and userPwd LIKE '${req.body.userPwd}';`
    client.query(query, (err, result) => {
        if(err || result[0] == undefined) {
            console.log('false'+result);
            res.send('false');
        } else {
            console.log('true'+result);
            nameList.push(result[0].name);
            res.send(result[0].name);
        }
    })
})

app.get('/getName', (req, res) => {
    res.send(nameList[nameList.length-1]);
})

app.get('/home', (req, res) => {
    console.log('in /home');
    console.log(nameList);
})

/* 객체 배열 테스트 */
// var obj = {};
// obj.key = new Array();
// obj.key.push('a');
// obj.key.push('b');
// const test = 'key';
// if(!obj[test]) {
//     console.log('test');
// }
// obj[test].splice(obj[test].indexOf('b'), 1);
// console.log(obj[test]);


var rooms = {};
io.on('connection', (socket) => {
    console.log('a user connected')
    
    socket.on('makeRoom', (socketInfo) => {
        socket.join(socketInfo.roomNumber);
        // 이름, 방번호 저장
        const roomNumber = socketInfo.roomNumber;
        const name = socketInfo.name;
        socket.room = roomNumber;
        socket.name = name;
        if(!rooms[roomNumber]) {
            rooms[roomNumber] = new Array();
        }
        rooms[roomNumber].push(socket.name);
        // 접속자 현황
        io.sockets.in(socketInfo.roomNumber).emit('connectToRoom', {
            message : socket.name + ' now in room ' + socketInfo.roomNumber,
            id : socket.id,
            roomInfo : rooms[socket.room]
        });
    })
    
    socket.on('disconnect', (reason) => {
        io.sockets.in(socket.room).emit('close', socket.name);
        if(rooms[socket.room]) {
            const roomNumber = socket.room;
            const name = socket.name;
            const idx = rooms[roomNumber].indexOf(1);
            rooms[roomNumber].splice(idx, 1);
            console.log(rooms[socket.room]);
        }
    });

    socket.on('send msg', (msg) => {
        io.sockets.in(socket.room).emit('send msg', {
            message : msg.message,
            name : socket.name,
            id : socket.id,
        })
    })
})

server.listen( port,'210.119.31.35', () => {
    console.log('Server running at 210.119.31.35:52273')
})
