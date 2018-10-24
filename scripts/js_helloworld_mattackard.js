// LANGUAGE: Javascript
// ENV: Node.js
// AUTHOR: Matt Ackard
// GITHUB: https://github.com/mattackard

let char = [32, 33, 44, 68, 69, 72, 76, 79, 82, 87];	//character codes for all character in HELLO, WORLD!

let order = [5,4,6,6,7,2,0,9,7,8,6,3,1];		//numbers directed to indexes of char, 
							//sequenced to build the message

let message = [];

order.forEach((num) => {
	message.push(String.fromCharCode(char[num]));
});

console.log(message.join(''));
