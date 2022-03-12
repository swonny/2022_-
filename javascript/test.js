const express = require('express')
const http = require('http')
const socketio = require('socket.io')

const port = 52273
const app = express()
app.use(express.static('public'))

const server = http.createServer(app)
const io = socketio.Server(server)

io.on('connection', () => {
    console.log('a user connected')
})

server.listen(port, () => {
    console.log('Server Running at http://127.0.0.1:52273')
})
