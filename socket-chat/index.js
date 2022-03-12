const express = require('express')
const app = express()
const http = require('http')
const server = http.createServer(app)
const { Server } = require('socket.io')
const io = new Server(server)

app.get('/', (req, res) => {
    res.sendFile(__dirname + '/index.html')
})

io.on('connection', (socket) => {
    console.log('a user connected')
    socket.on('disconnect', () => {
        console.log('disconnected')
    })

    socket.on('chat message', (data) => {
        console.log(data)
        io.emit('chat message', (data))
    })

    
})

server.listen(52273, (req, res) => {
    console.log('Server running at http://127.0.0.1:52273')
    console.log(__dirname)
})