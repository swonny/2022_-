var express = require('express');
var bodyParser = require('body-parser');

var app = express();
app.use(express.static('public'));
app.use(bodyParser.urlencoded ({ extended : false }))

var items = [{
    name : '우유',
    price : 1000
}, {
    name : '홍차',
    price : 2000
}, {
    name : '커피',
    price : 3000
}]

app.get('/products', (request, response) => {
    response.send(items);
})

app.post('/products', (request, response) => {
    var name = request.body.name;
    var price = request.body.price;

    var item = {
        name : name,
        price : price
    }

    items.push(item);

    response.send({
        message : '데이터를 추가했습니다.',
        data : item
    })
})

app.listen(52273, function(request, response) {
    console.log('Server running at http://127.0.0.1:52273');
})