var http = require('http')
var fs = require('fs')
var socketio = require('socket.io')

http.createServer((req, res) => {
    fs.readFile('index.html', (error, data) => {
        res.writeHead(200, { 'Content-Type' : 'text/html'})
        res.end(data)
    })
}).listen(52273, (req, res) => {
    console.log('Server running at http://127.0.0.1:52273')
})