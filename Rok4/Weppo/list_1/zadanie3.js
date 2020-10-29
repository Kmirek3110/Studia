var limit = 100000;

function prime(i){
    
    for(j = 2 ; j<i; j++){
        if (i%j == 0) return false; 
    }
    return true;
}


for(i = 2; i<limit; i++){
    if(prime(i)) console.log(i);
}