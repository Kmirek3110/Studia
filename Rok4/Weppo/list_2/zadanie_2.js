let first_point = {
    a : 42,
    b : "różnice",
    toString: function(){
        return '2'
    }
};
console.log(first_point.a);
console.log(first_point['b']);

//Różnice pomiędzy . oraz [] 
// Używając [] mamy więcej możliwośći nazwy kluczów np "klucz ze spacją"

let second_point = {
    2: 14
};

//Wszystko konwertowane jest na stringa
console.log(second_point[12]);
//kiedy przeciązyłem funkcję toString obiektu first_point na to by zwracała 2 to dostalismy wartosc 14
console.log(second_point[first_point]);
// Można nadpisywać funckję toString obiektów

var tablica = ["jeden", "dwa", "trzy", "pięć"];

console.log(tablica["dwa"]);
//Dostajemy undefined
console.log(tablica[first_point]);
//Wszystko jest konwertonwane na number first_point.toString() został skonwertowany na z "2" na number 2 

// tablica.test = "testowanie";
// console.log(tablica);//Dodalismy do tablicy słownik jedno elementowy test: 'testowanie'
// console.log(tablica['test']);

console.log(tablica.length);
//Ustawilismy length na większa i wszystko ładnie przeszło
tablica.length = 5;
console.log(tablica);
console.log(tablica.length);
//Ustawiamy na mniejszą 
tablica.length = 3;
console.log(tablica);
console.log(tablica.length);
tablica.length = 5;
console.log(tablica);
console.log(tablica.length);

//Gdy zwiększamy wartość dodajemy odpowiednią ilość pustych elementów na końcu
//Adekwatnie do zwiększania, zmiejszanie usuwą odpowiednią ilość elementów
// tablica.length = -1;
// console.log(tablica);