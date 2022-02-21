var express = require('express');

var app = express();
app.use(express.static('public'));



app.listen(52273, function(request, response) {
    console.log('Server running at http://127.0.0.1:52273')
})