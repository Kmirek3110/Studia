module.exports = {func_a};
let b = require('./zadanie_3_mod2');

function func_a(n){
    if(n<20){
        console.log("a ------", n);
        b.func_b(n+1);
    }
}