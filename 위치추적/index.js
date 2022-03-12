const express = require('express');
const http = require('http');
const socketio = require('socket.io');
const mysql = require('mysql');
const fs = require('fs');

const app = express();
const server = http.createServer(app);
const io = new socketio.Server(server);

const port = 52273;

const client = mysql.createConnection({
    user : 'root',
    password : '9809',
    database : 'Location'
});

app.use(express.static('public'));
app.use(express.json()); // json -> 객체 

/* 라우터 */
app.get('/tracker', (req, res) => {
    fs.readFile('tracker.html', (err, data) => {
        res.send(data);
    })
});

app.get('/observer', (req, res) => {
    fs.readFile('observer.html', (err, data) => {
        res.send(data);
    })
});

app.post('/showdata', (req, res) => {
    console.log(req.body.name + ' ' +req.body.latitude);
    const query = `INSERT INTO locations (name,longtitude,latitude) 
    VALUES ('${req.body.name}','${req.body.longitude}','${req.body.latitude}');`;
    client.query(query, (err, data) => {
        if(err) {
            console.log(err.message);
        } else {
            console.log('db 추가 성공');
            res.send(data);
        }
    })
});

/* 소켓 서버 실행 */
io.on('connection', (socket) => {
    console.log('socket server');
    socket.on('join', (info) => {
        const query = `INSERT INTO locations (name, longtitude, latitude) VALUES ('${info.name}','${info.latitude}','${info.longitude}');`;
        client.query(query, (err, data) => {
            if(err) {
                console.log(err.message);
            } else {
                console.log('db 추가 성공');   
                socket.join(info.name);
                socket.name = info.name;
                io.sockets.in(info.name).emit('receive', {
                    latitude : info.latitude,
                    longitude : info.longitude,
                    now : Date.now() // Q.
                });
            }
        })
    });

    socket.on('enter room', (room) => {
        const query = `SELECT * FROM locations WHERE name LIKE '${room}';`;
        client.query(query, (err, data) => {
            if(err) {
                console.log(err.message);
            } else {
                console.log(data[0]);
                var arr = [];
                for(var record of data) {
                    var info = {
                        latlng : new kakao.mapsLatLng(`${record.longitude}`, `${record.latitude}`)
                    }
                    arr.push(info);
                    // io.sockets.emit('show', data[0]);
                }
                console.log(arr);
            }
        })
    })
});

server.listen(port, () => {
    console.log('Server runnig at http://127.0.0.1:52273');
});