const express = require('express')
const http = require('http')
const socketio = require('socket.io')

const port = 52273
const app = express()
app.use(express.static('public'))

const server = http.createServer(app)
const io = new socketio.Server(server)

io.on('connection', (socket) => {
    console.log('a user connected')
    socket.on('disconnect', () => {
        console.log('disconnected')
    })
})

io.on('chat message', (socket) => {

})

server.listen(port, (req, res) => {
    console.log('Server Running at http://127.0.0.1:52273')
})
