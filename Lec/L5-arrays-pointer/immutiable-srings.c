// //CANT CHAANGE 

// // #include <ctype.h>
// // char *makeBig(char *s) {
// //     s[0] = toupper(s[0]);
// //     return s;
// // }

// // int main() {
// //     makeBig("a cat");
// // }

// //CAN CHANGE 
// #include <stdio.h>
// #include <ctype.h>

// char *makeBig(char *s) {
//     s[0] = toupper(s[0]);
//     return s;
// }

// int main() {
//     char str[] = "a cat";  // writable array
//     printf("%s\n", makeBig(str)); // prints "A cat"
// }