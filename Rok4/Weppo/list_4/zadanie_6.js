var readline = require('readline');
var fs = require('fs');

var myInterface = readline.createInterface({
    input: fs.createReadStream('inputfile.txt')
});

var data = {};


myInterface.on('line',function(line){
    //bierzemy ip
    var ip = line.split(" ")[1];
    
    if(data[ip] !== undefined)
        data[ip]++;
    else
        data[ip] = 1;

})

myInterface.on('close', function(){
    //sortujemy elementy i wypisujemy 3 z najwięszką wartością
    var items = Object.keys(data).map(function(key) {
        return [key, data[key]];
      });

    items.sort(function(first, second) {
        return second[1] - first[1];
    });
    for(item of items.slice(0, 3)){
        console.log(item[0]);
    }
});


