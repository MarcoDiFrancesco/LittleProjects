// Var means 
let number = "hello";
console.log(number.length);
console.log(number[0]);

function mergeWords(first, second) {
  return "" + first + " " + second;
}
console.log(mergeWords('hello', `world`));

// Arrays
let myArray = [1, 5];
let myNestedArray = [["first", "second"], ["third", "forth"]];
console.log("Array: " + myArray[0] + myArray[1] + myArray[2]);
console.log("NestedArray: " + myNestedArray[0][1] + " " + myNestedArray[1][0])

myArray = [2,7,4];
console.log(myArray);
myArray.pop();
console.log(myArray);
// Output: (3) [2, 7, 4]
//         (2) [2, 7]

myArray = [2,7,4];
console.log(myArray);
myArray.shift();
console.log(myArray);
// Output: (3) [2, 7, 4]
//         (2) [2, 7]
