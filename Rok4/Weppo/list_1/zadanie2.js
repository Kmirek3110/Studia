var limit = 100000;

function dividedByEach(number){
    var listofchars = number.toString().split("");

    for(const element of listofchars){
        if(number % parseInt(element) != 0)
            return false;
    }
    return true;
}


function dividedBySum(number){
    var listofchars = number.toString().split("");
    var sum = 0;

    for(const element of listofchars){
        sum += parseInt(element);
    }
    return number%sum == 0;
}

for (number=0; number< limit; number++){
    if (dividedByEach(number) && dividedBySum(number))
        console.log(number);

}