## Learning Resources : 
- Javascript algorithms and DS:
  https://www.freecodecamp.org/learn/javascript-algorithms-and-data-structures/
- https://www.freecodecamp.org/news/23-free-websites-to-learn-javascript/
- After you have a basic knowledge and want to build something :
  https://javascript30.com/
- Best Youtube playlist on JS:
  https://www.youtube.com/watch?v=PkZNo7MFNFg
- Complete JS Guide / Documentation from beginner to advanced: 
  https://javascript.info/
- MDN : Advanced topics: 
  https://www.freecodecamp.org/news/23-free-websites-to-learn-javascript/developer.mozilla.org
- Google Course :
  https://learnjavascript.online/

## Links and Posts:
- Javascript Design Patterns :
  https://dev.to/jaimaldullat/series/25443

## Points to note: 

- Datatypes in JS :
  * undefined
  * null
  * boolean
  * string
  * symbol
  * bigint
  * number
  * object

- When JavaScript variables are declared, they have an initial value of **undefined**. 
  If you do a mathematical operation on an undefined variable your result will be **NaN** which means "Not a Number". 
  If you concatenate a string with an undefined variable, you will get a string of **undefined + whatever string you concatenated**

- One of the biggest problems with declaring variables with the var keyword is that you can easily overwrite variable declarations.A keyword called **let** was introduced in ES6, a major update to JavaScript,
  to solve the potential issue of easily overriden data declared with the var keyword. 
  Example : 
  ```
  var camper = "James";
  var camper = "David";
  ```
  is ok, while :
  ```
  let camper = "James";
  let camper = "David";
  ```
  will throw error.

-  It is common for developers to use uppercase variable identifiers for immutable values and lowercase or camelCase for mutable values

- The remainder operator is sometimes incorrectly referred to as the modulus operator. It is very similar to modulus, but does not work properly with negative numbers.

- The reason why you might want to use one type of quote over the other is if you want to use both in a string. This might happen if you want to save a conversation in a string and have the conversation in quotes. Another use for it would be saving an ```<a>``` tag with various attributes in quotes, all within a string.

- Escape Character : 
```
\'  single quote
\"  double quote
\\  backslash
\n  newline
\t  tab
\r  carriage return
\b  backspace
\f  form feed
```

- You can find the length of a String value by writing .length after the string variable or string literal.

- Variables which are declared without the let or const keywords are automatically created in the global scope

- A function can include the return statement but it does not have to. In the case that the function doesn't have a return statement, when you call it, the function processes the inner code but the returned value is undefined.

- Objects : Dot notation is what you use when you know the name of the property you're trying to access ahead of time.
  If the property of the object you are trying to access has a space in its name, you will need to use bracket notation.

This works : 
const obj = {12:"sdfgh", 16:"efgh", 18:"dfsgh"};
undefined
obj[12]
'sdfgh'
obj["12"]
'sdfgh'

- We can also delete properties from objects like this: delete ourDog.bark;
- To check if a property on a given object exists or not, you can use the .hasOwnProperty() method. someObject.hasOwnProperty(someProperty) returns true or false depending on if the property is found on the object or not.


- The parseInt() function parses a string and returns an integer. Here's an example:
```
const a = parseInt("007");
```

- Here's how you can give new variable names in the assignment:
```
const { name: userName, age: userAge } = user;
```
You may read it as "get the value of user.name and assign it to a new variable named userName" and so on. The value of userName would be the string John Doe, and the value of userAge would be the number 34.

- 
```
const [a, b,,, c] = [1, 2, 3, 4, 5, 6];
console.log(a, b, c);
```
The console will display the values of a, b, and c as 1, 2, 5.

- Same destucturing can be done in function parameters

- _ starting variables are private 