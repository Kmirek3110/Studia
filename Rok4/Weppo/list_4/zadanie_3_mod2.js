module.exports = {func_b};
let a = require('./zadanie_3_mod1');

function func_b(n){
    if(n<20){
        console.log("b ------",n );
        a.func_a(n+1);
    }
}