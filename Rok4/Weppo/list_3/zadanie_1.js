var dog = {
    age : 12,
    last_checkup: undefined,

    get dog_info(){
        return [this.age, this.last_checkup];
    },

    set checkup(date){
        this.last_checkup = date;
    },

    bark(){
        console.log(" Bark bark !!")
    },
    
}


// Metoda wywyłana
dog.bark();

//Dodanie nowego pola
dog.breed = "Terrier";

//Uzycie settera
dog.checkup = "2020-10-31";

console.log(dog.breed);

console.log(dog.dog_info);

//definicja settera i getteta z defineproperty
Object.defineProperty(dog, "breedUp", { get : function() { return this.breed.toUpperCase();}})
Object.defineProperty(dog, "dif_breed", { set : function(arg){ this.breed = arg;}})


//Inny rodzaj definicji metod
dog.weird_noice = function(){
        console.log("Meow meow");
}


console.log(dog.breedUp);

console.log(dog.age);
dog.dif_breed = "Husky";

console.log(dog.breedUp)

dog.weird_noice();

// Nie da się zdefiniować settera i gettera w normalny sposob