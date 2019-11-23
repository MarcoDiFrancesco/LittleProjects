`var` are variables that can be used in all the program
`let` are used in the scope where you declear that
`const` variable that can never change

the variables can be:
- `undefined`
- `null`
- `boolean`
- `string`
- `symbol`
- `number`
- `object`

For example:
``` JS
var myVar = "myVar"
myVar = 8
let myLet = "myLet"
const myConst = "myConst"
```
Check **lenght** of a string `string.lenght`.
Check last letter of a string `string[string.lenght-1]`.

Functions:
``` JS
function mergeWords(first, second) {
  return "" + first + " " + second;
}
console.log(mergeWords('hello', `world`));
```

Arrays:
``` JS
let myArray = [1, 5];
console.log("Array: " + myArray[0] + myArray[1] + myArray[2]);
// Output: Array: 15undefined

let myNestedArray = [["first", "second"], ["third", "forth"]];
console.log("NestedArray: " + myNestedArray[0][1] + " " + myNestedArray[1][0])
// Output: NestedArray: second third
```
Pop from array: removes last element
``` js
myArray = [2,7,4];
console.log(myArray);
myArray.pop();
console.log(myArray);
// Output: (3) [2, 7, 4]
//         (2) [2, 7]
```
Shift an array: removes first element
``` js
myArray = [2,7,4];
console.log(myArray);
myArray.shift();
console.log(myArray);
// Output: (3) [2, 7, 4]
//         (2) [7, 4]
```

