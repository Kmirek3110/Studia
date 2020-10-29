console.log( (![]+[])[+[]] + (![]+[])[+!+[]] + ([![]]+[][[]])[+!+[]+[+[]]] + (![]+[])[!+[]+!+[]] );


console.log((![]+[])[+[]]);
//literka f  
// ![] jest konwertowane na booleanowskie false  po dodaniu pustego znaku [] dostajemy stringa "false"
// po czym [+[]] jest konwertowane przez + na wartość 0 i w rezultacie dostajemy "false"[0]
console.log((![]+[])[+!+[]]);//literka a
//Początek taki sam jak w literce f 
// +! dodaje 1 do 0 więc mamy "false"[1]
console.log(([![]]+[][[]])[+!+[]+[+[]]]);//literka i
// ([![]]+[][[]]) [![]] to jest false, [][[]] undefined po czym konkatenujemy stringi
//[+!+[]+[+[]]   +!+[] = '1', [+[]] = '0', konkatenacje stringów '10'
//falseundefined['10'] => falseundefined[10] = i 
console.log((![]+[])[!+[]+!+[]]);// literka l
//false[2] wnioskujemy z poprzednich


