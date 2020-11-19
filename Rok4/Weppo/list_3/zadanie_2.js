function fib(n){
    if( n  > 1 ){
        return fib(n-1) + fib(n-2);
    } else {
        return 1;
    }
}

function fib1(n){
    if( n  > 1 ){
        return fib1(n-1) + fib1(n-2);
    } else {
        return 1;
    }
}

function memo(f){

    var cache = {}

    return function(n){

        if( cache [n] === undefined ){
            var f_n = f(n);
            cache[n] = f_n;
            return f_n;
        }else {
            return cache[n];
        }

    }
}

var fib = memo(fib);


// Z memoizacją
console.time();
console.log(fib(42));
console.log(fib(41));
console.timeEnd();


// Bez memoizacji
console.time();
fib1(42);
fib1(41);

console.timeEnd();