function map(a, f){
    for(var i=0; i<a.length; i++){
        a[i] = f(a[i]);
    }
    return a;
}

function filter(a, f){
    
    var b = [];
    for(var i=0; i<a.length; i++){
        if(f(a[i])){
            b.push(a[i]);
        }
    }
    return b;

}

function forEach(a, f){
    for(var i=0; i<a.length; i++){
        f(a[i]);
    }
}

var a = [1,2,3,4];

forEach( a, _ => { console.log( _ ); } );

var b = filter( a, _ => _ < 3 );
console.log(b);

var c = map( a, _ => _ * 2 );
console.log(c);
