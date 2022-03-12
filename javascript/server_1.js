var express = require('express');
const port = 52273

// 웹 서버 생성
var app = express();
app.use(express.static('public'));
app.use(express.urlencoded({ extended : false }))

// 변수 선언
var items = [{
    name : '우유',
    price : 1000
}, {
    name : '홍차',
    price : 2000
}, {
    name : '커피',
    price : 3000
}];

// 라우트
app.get('/products', (req, res) => {
    res.send(items);
})

app.get('/products/:id', (req, res) => {
    var id = Number(req.params.id)

    res.send(items[id]);
})

app.all('/data.json', (req, res) => {
    res.send(items);
})

// 서버 실행
app.listen(port, (req, res) => {
    console.log(`Server running at http://127.0.0.1:${port}`)
})