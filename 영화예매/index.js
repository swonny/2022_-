const express = require('express');
const http = require('http');
const socketio = require('socket.io');
const app = express();
const bodyParser = require('body-parser');

const server = http.createServer(app);
const io = new socketio.Server(server);

const port = 52273;

app.use(express.static('public'));
// app.use(express.urlencoded({
//     extended: false,
//     // type: 'application/json',
// }));
// app.use(bodyParser.json());
app.use(express.json());

var seats = [
    [1,1,0,1,1,0,0,0,0,1,1,0,1,1],
    [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
    [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
    [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
    [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
    [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
    [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
    [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
    [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
    [1,1,0,1,1,1,1,1,1,1,1,0,1,1],
    [1,1,0,1,1,1,1,1,1,1,1,0,1,1]
]

app.post('/select', (req, res) => {
    console.log(req.body);
    const row = Number(req.body.row);
    const col = Number(req.body.col);
    var result = seats[row][col];
    var msg = '';
    if(result == 1) {
        seats[row][col] = 2;
        res.send({
            status : 1,
        })
    } else if (result == 2) {
        res.send ({
            status : 2,
        })
    } 
})

io.on('connection', (socket) => {
    socket.on('select', (data) => {
        seats[data.row][data.col] = 2;
        io.sockets.emit('newSelected', {
            row : data.row,
            col : data.col
        })
    })
})

app.get('/status', (req, res) => {
    res.send({
        status : seats
    });
})

server.listen(port, (req, res) => {
    console.log('Server running at http://127.0.0.1:52273');
})