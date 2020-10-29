


function fib(n){
    if(n == 1)
        return 0;
    if (n == 2)
        return 1;
    return fib(n-1) + fib(n-2);
}

function  it_fib(n){
    var first = 0;
    var second = 1;
    var current = 0 ;
    
    if(n == 1) return 0;
    if(n == 2) return 1;

    for(j = 0; j < n-2; j++){
        current = first;
        first  = second;
        second += current;   
    }

    return second;
}

console.log("Rekurencja");
for(i =1; i<=25;i++){
    console.time();
    console.log(fib(i));
    console.timeEnd();
    }

console.log("Iteracja");
for(i =1; i<=25;i++){
    console.time();
    console.log(it_fib(i));
    console.timeEnd();
}