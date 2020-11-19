function Tree(val, left, right){
    this.left = left;
    this.right = right;
    this.val = val;
}

// Tree.prototype[Symbol.iterator]=function*(){
//     yield this.val;
//     if(this.left) yield* this.left;
//     if(this.right) yield* this.right;
// }

Tree.prototype[Symbol.iterator]=function*(){
    var queue = [this];
    while (queue.length) {
        var item = queue.splice(0,1);
         // jeśli bym  na początku sprawdzał lewe poddrzewo miałbym wynik sprzeczy z trescia zadania
        if(item[0].right){
            queue.push(item[0].right)
        }
        if(item[0].left){
            queue.push(item[0].left)
        }  
        yield item[0].val
    }
}


var root = new Tree( 1,
    new Tree( 2, new Tree( 3 ) ), new Tree( 4 ));

for(var e of root){
    console.log(e);
}
