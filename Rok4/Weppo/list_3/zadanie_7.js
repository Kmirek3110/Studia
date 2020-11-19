function fib() {
    var _prevstate = 0;
    var _state = 1;
    return {
        next : function() { 
            var tmp = _state;
            _state += _prevstate;
            _prevstate = tmp; 
            return {
                value : _state,
                done :1 > 2,
             }
        }
    }
}

function *fib() {
   var _prevstate = 0;
   var _state = 1;
   var tmp;

    while(true){
        tmp = _state;
        _state += _prevstate;
        _prevstate = tmp; 
        yield _state;
    }
}

var _it = fib();
var counter = 0
for ( var _result; _result = _it.next(), !_result.done; ) {
    console.log( _result.value );
    counter += 1;
    if(counter > 10)
        break
}

//Da się iterować forOf dla generatora czyli fib* z yieldem 

// for ( var i of fib() ) {
//     console.log( i );
// }