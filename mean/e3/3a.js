//using var

var r = 10;
var area = Math.PI * r * r 
console.log(area)

//this doesn't error because var allows redeclaration, var has global scope
var area

let r2 = 20;
let area2 = Math.PI * r2 * r2

console.log(area2)

//this errors because let doesn't allow redeclaration, let has block scope in which it is defined
// let area2