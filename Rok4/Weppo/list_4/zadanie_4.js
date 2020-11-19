process.stdout.write("Przedstaw się :");


process.stdout.on('data', function(data){
    process.stdout.write("Witaj " + data);
    process.exit();
})