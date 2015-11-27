//Created by Anubhav Sarkar on 11/26/15
/*eslint no-unused-params:0*/

//Load modules to start the application
/*eslint-env node */
var port = (process.env.VCAP_APP_PORT || 3000);
var host = (process.env.VCAP_APP_HOST || 'localhost');
var http = require('http');
var fs = require('fs');


//Incorporate the HTML form into our web page
function displayForm(res) {
    fs.readFile('form.html', function (err, data) {
        res.writeHead(200, {
            'Content-Type': 'text/html',
                'Content-Length': data.length
        });
        res.write(data);
        res.end();
    });
} 

//Create the server
 var server = http.createServer(function (req, res) {
	displayForm(res);
});
server.listen(port,host);
