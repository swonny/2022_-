const express = require('express')
const http = require('http')
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
        socket.join('room-' + socketInfo.roomNumber);
        socket.name = socketInfo.name;
        socket.room = socketInfo.roomNumber;
        console.log(socketInfo.room);
        io.sockets.in('room-' + socketInfo.roomNumber).emit('connectToRoom', {
            message : socket.name + ' now in room ' + socketInfo.roomNumber,
        });
    })

    socket.on('send msg', (msg) => {
        io.emit('send msg', {
            message : msg.message
        })
    })
})

server.listen(port, () => {
    console.log('Server running at http://127.0.0.1:52273')
})
