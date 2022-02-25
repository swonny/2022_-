const express = require('express');
const http = require('http');
const socketio = require('socket.io');

const app = express();
const server = http.createServer(app);
const io = new socketio.Server(server);

app.use(express.static('public'));

var clients = 0;
io.on('connection', (socket) => {
    console.log('namespace(/) connected')
    clients++;
    io.emit('broadcast', {
        description : clients + 'clients connected!'
    })

    socket.on('disconnect', () => {
        console.log('disconnect (/)')
        clients--;
        io.emit('broadcast', {
            description : clients + 'clients connected!'
        })
    })

    socket.on('send message', (msg) => {
        console.log(msg);
        io.emit('send message', msg);
    })
})

io.of('/scania').on('connection', (socket) => {
    console.log('namespace(scania) connected')
    socket.on('disconnect', () => {
        console.log('disconnect (/scania)')
    })
})

server.listen(52273, (req, res) => {
    console.log('Server running ');
})
