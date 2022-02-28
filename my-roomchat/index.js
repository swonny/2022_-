const express = require('express')
const http = require('http')
const { disconnect } = require('process')
const socketio = require('socket.io')

const port = 52273

const app = express()
const server = http.createServer(app)
const io = new socketio.Server(server)

app.use(express.static('public'))

var roomNumber = '';

io.on('connection', (socket) => {
    console.log('a user connected')
    // 방배정 및 이름 저장
    socket.on('makeRoom', (socketInfo) => {
        socket.join(socketInfo.roomNumber);
        // 이름, 방번호 저장
        socket.name = socketInfo.name;
        socket.room = socketInfo.roomNumber;

        // 접속자 현황
        io.sockets.in(socketInfo.roomNumber).emit('connectToRoom', {
            message : socket.name + ' now in room ' + socketInfo.roomNumber,
            id : socket.id
        });
    })

    socket.on('disconnect', (reason) => {
        io.sockets.in(socket.room).emit('close', socket.id);
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
    console.log('Server running at http://127.0.0.1:52273')
})
