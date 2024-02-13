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

## FOCUS factors:
- Promises
- 

## Links and Posts:
- Javascript Design Patterns :
  https://dev.to/jaimaldullat/series/25443
- Promises: 
  https://www.freecodecamp.org/news/javascript-promise-tutorial-how-to-resolve-or-reject-promises-in-js/

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

- Suppose you have a file and you wish to import all of its contents into the current file. This can be done with the import * as syntax. Here's an example where the contents of a file named math_functions.js are imported into a file in the same directory:
```
import * as myMathModule from "./math_functions.js";
```

- Usually you will use this syntax if only one value is being exported from a file. It is also used to create a fallback value for a file or module. export default is used to declare a fallback value for a module or file, you can only have one value be a default export in each module or file. Additionally, you cannot use export default with var, let, or const

- When you import a default export, you have the flexibility to choose any name for the import. This can be helpful if the module's name is long or if you want to use a different name locally.

- A promise in JavaScript is exactly what it sounds like - you use it to make a promise to do something, usually asynchronously. When the task completes, you either fulfill your promise or fail to do so. Promise is a constructor function, so you need to use the new keyword to create one. It takes a function, as its argument, with two parameters - resolve and reject. These are methods used to determine the outcome of the promise. The syntax looks like this:
```
const myPromise = new Promise((resolve, reject) => {

});
```

- .then function of a promise which takes in a callback function is called when the resolve method is called and the value passed as parameter to resolve method is the same value passed to the resolve method. 
https://chat.openai.com/share/3436380b-3a2c-4427-84d4-2537421cfe90
Similarly, catch is the method used when your promise has been rejected. It is executed immediately after a promise's reject method is called. Here’s the syntax:
```
myPromise.catch(error => {
  
});
```
================= REGEX ===========================================================================
- Regex in JS look like : /text/
This can be tested on a string using ```test()``` function called on regex. Ex : ```regex.test(text)```

- TO evaluate multiple expressions in a regex use | operator. 
```regex = /exp1|exp2/```

- To match the strings with ignoring case use the i flag after the regex.
  /regex/i

- Analogous to test() , ```match()``` is called on the string. and passed the regex value. Match returns a list of strings that match the regex value. 

- The wildcard character . will match any one character. The wildcard is also called dot and period. You can use the wildcard character just like any other character in the regex. For example, if you wanted to match hug, huh, hut, and hum, you can use the regex /hu./ to match all four words.

- [] define character classes in regex

- To find a character occurs one or more times use + operator like ```/a+/``` . For checking the same but 0 or more times use * as: ```/a*/```

- In regular expressions, a greedy match finds the longest possible part of a string that fits the regex pattern and returns it as a match. The alternative is called a lazy match, which finds the smallest possible part of the string that satisfies the regex pattern. However, you can use the ? character to change it to lazy matching. "titanic" matched against the adjusted regex of /t[a-z]*?i/ returns ["ti"].

- Outside of character set a caret character ^ searches if the first word in the string is matching. Similarly, You can search the end of strings using the dollar sign character $ at the end of the regex.

- The closest character class in JavaScript to match the alphabet is \w. This shortcut is equal to [A-Za-z0-9_]. This character class matches upper and lowercase letters plus numbers. Note, this character class also includes the underscore character (_).

- You can search for the opposite of the \w with \W. Note, the opposite pattern uses a capital letter. This shortcut is the same as [^A-Za-z0-9_].

- You can search for whitespace using \s, which is a lowercase s. This pattern not only matches whitespace, but also carriage return, tab, form feed, and new line characters. You can think of it as similar to the character class [ \r\t\f\n\v]

- You can specify the possible existence of an element with a question mark, ?. This checks for zero or one of the preceding element. You can think of this symbol as saying the previous element is optional.

- To specify a certain number of patterns, just have that one number between the curly brackets.
  
- Lookaheads are patterns that tell JavaScript to look-ahead in your string to check for patterns further along. This can be useful when you want to search for multiple patterns over the same string.

- Lookaheads are patterns that tell JavaScript to look-ahead in your string to check for patterns further along. This can be useful when you want to search for multiple patterns over the same string. There are two kinds of lookaheads: positive lookahead and negative lookahead.

- A positive lookahead will look to make sure the element in the search pattern is there, but won't actually match it. A positive lookahead is used as (?=...) where the ... is the required part that is not matched.

- A negative lookahead will look to make sure the element in the search pattern is not there. A negative lookahead is used as (?!...) where the ... is the pattern that you do not want to be there. The rest of the pattern is returned if the negative lookahead part is not present.

- To specify that the entire string should match the regex we can use ^..regex..$ contruction. So it means that the string starts with the regex and ends with the regex

- You can search and replace text in a string using .replace() on a string. The inputs for .replace() is first the regex pattern you want to search for. The second parameter is the string to replace the match or a function to do something.


- You can also access capture groups in the replacement string with dollar signs ($).
  ```
  "Code Camp".replace(/(\w+)\s(\w+)/, '$2 $1');
  ```
  The replace call would return the string Camp Code.


===================== FUNCTIONAL PROGRAMMING ========================

- Functional programming is about:
  - Isolated functions - there is no dependence on the state of the program, which includes global variables that are subject to change
  - Pure functions - the same input always gives the same output
  - Functions with limited side effects - any changes, or mutations, to the state of the program outside the function are carefully controlled

- filter is used to filter values from an array, map is a perfect function used to map the values to a certain value. SLice(beg, end) is used to slice the array and return a array in between. 
 The callback function accepts 4 arguments : item, index, array itself.
-  intitialValue is A value to which accumulator is initialized the first time the callback is called. If initialValue is specified, callbackFn starts executing with the first value in the array as currentValue. If initialValue is not specified, accumulator is initialized to the first value in the array, and callbackFn starts executing with the second value in the array as currentValue. In this case, if the array is empty (so that there's no first value to return as accumulator), an error is thrown.
