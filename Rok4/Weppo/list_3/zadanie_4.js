function createFs(n) { // tworzy tablicę n funkcji
    //Jak zamienimy var fs = [] na let fs = [] to będzie działać "poprawnie"
    var fs = []; // i-ta funkcja z tablicy ma zwrócić i 
    for ( let i=0; i<n; i++ ) {
        fs[i] =
            function() {
                return i;
            };
    };
    return fs;
}


// Funcka create Fs z dodatkowym zagniezdzeniem "eliminuje" zakres vara i działa poprawnie
function createFsnest(n) { 
    var fs = []; 
    for (var i = 0; i < n; i++) {
        fs[i] = (function() {
            var j; 
            j = i; 
            return function() { return j; };
        })();
    };
    return fs;
}

var myfs = createFs(10);
console.log( myfs[0]() ); // zerowa funkcja miała zwrócić 0
console.log( myfs[2]() ); // druga miała zwrócić 2
console.log( myfs[7]() );




var myfs1 = createFsnest(10);

console.log(myfs1[0]()); 
console.log(myfs1[2]()); 
console.log(myfs1[7]());