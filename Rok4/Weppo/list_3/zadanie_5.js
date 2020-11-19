function sum(...a){

    var counter = 0;
    
    for(var i=0; i < a.length; i++){
        counter += a[i];
    }
    return counter;
}


console.log(sum(1,2,3));