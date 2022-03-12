var express = require('express');
var mysql = require('mysql');
// var bodyParser = require('body-parser')
const port = 52273

const client = mysql.createConnection({
    host: '127.0.0.1',
    user : 'root',
    password : '9809',
    database : 'company',
})

client.query('SELECT * FROM products;', (error, result, fields) => {
    if(error) {
        console.log('쿼리문장에 오류가 있습니다.');
        console.log(error.message);
    } else {
        console.log(result);
    }
})

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
    client.query('SELECT * FROM Products;', (error, data) => {
        if(error) {
            console.log('쿼리 문장에 오류가 있습니다.')
        } else {
            res.send(data);
        }
    })
})

app.get('/products/:id', (req, res) => {
    var id = req.params.id

    client.query('SELECT * FROM Products WHERE id=?;', [id] , (error, data) => {
        res.send(data)
    })
})

app.post('/products', (req, res) => {
    var name = req.body.name;
    var modelnumber = req.body.modelnumber;
    var series = req.body.series;

    client.query('INSERT INTO Products (name, modelnumber, series) VALUES (?,?,?)', [
        name,  modelnumber, series
    ], (error, data) => {
        res.send({
            message : '레코드가 추가되었습니다.',
            data : data
        })
    })
})

// app.put('/products', (req, res) => {
//     // var id = req.params.id
//     var id = req.body.id
//     var name = req.body.name
//     var modelnumber = req.body.name
//     var series = req.body.series

//     client.query('UPDATE products SET name=?, modelnumber=?, series=? WHERE id=?', [
//         name, modelnumber, series, id
//     ], (error, data) => {
//         res.send(data)
//     })
// })

app.put('/products/:id', (req, res) => {
    var id = Number(req.params.id)
    var name = req.body.name
    var modelnumber = req.body.modelnumber
    var series = req.body.series

    client.query('UPDATE products SET name=?, modelnumber=?, series=? WHERE id=?',[
        name, modelnumber, series, id
    ], (error, data) => {
        res.send('데이터를 추가했습니다.')
    })
})

app.del('/products/:id', (req, res) => {
    var id = Number(req.params.id)
    // var id = Number(req.body.id)

    client.query('DELETE FROM products WHERE id=?', [id], (error, data) => {
        res.send(`데이터를 삭제하였습니다.`)
    })
})

// app.post('/products', (req, res) => {
//     var name = req.body.name
//     var price = req.body.price

//     var item = {
//         name : name,
//         price : price
//     }

//     items.push(item)

//     res.send({
//         message : '데이터를 추가했습니다.',
//         data : item
//     })
// })


// 라우트
app.all('/data.html', (req, res) => {
    var output = '';
    output += '<!DOCTYPE html>'
    output += '<html>'
    output += '<head>'
    output += ' <title>Data HT<L</title>'
    output += '</head>'
    output += '<body>'
    items.forEach((item) => {
        output += '<div>'
        output += ' <h1>' + item.name + '</h1>'
        output += ' <h2>' + item.price + '</h2>'
        output += '</div>'
    })
    output += '</body>'
    output += '</html>'
    res.send(output);
})

app.all('/data.jason', (req, res) => {
    res.send(items);
})

app.all('/parameter', (req, res) => {
    var name = req.query.name;
    var region = req.query.region;

    res.send('<h1>' + name + ':' + region + '</h1>')
})

app.all('/parameter/:id', (req, res) => {
    var id = req.params.id;

    res.send('<h1>' + id + '</h1>')
})

app.get('/products', (req, res) => {
    res.send(items);
})

app.get('/products/:id', (req, res) => {
    var id = Number(req.params.id)

    res.send(items[id])
})

app.get('/products/:id', (req, res) => {
    var id = Number(req.params.id)

    if(isNaN(id)) {
        res.send( {
            error : '숫자를 입력하세요'
        })
    } else if(items[id]) {
        res.send(items[id])
    } else {
        res.send({
            error : '존재하지 않는 데이터입니다'
        })
    }
})

app.put('/products/:id', (req, res) => {
    var id = req.params.id;

    var name = req.body.name
    var price = req.body.price
    
    if(items[id]) {
        if(name) { items[id].name = name }
        if(price) { items[id].price = price}

        res.send({
            message: '데이터를 수정합니다.',
            data : items[id]
        })
    } else {
        res.send({
            error : '존재하지 않는 데이터입니다.'
        })
    }
})

app.delete('/products/:id', (req, res) => {
    var id = Number(req.params.id);

    if(isNaN(id)) {
        res.send({
            error : '존재하지 않는 데이터입니다'
        })
    } else if(items[id]) {
        items.splice(id, 1);

        res.send({
            message : ''
        })
    }
})

// 서버 실행
app.listen(port, (req, res) => {
    console.log(`Server running at http://127.0.0.1:${port}`)
})