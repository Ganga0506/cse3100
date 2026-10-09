#include<stdio.h>
#define SQUARE(x) (x*x)

int main() {
    int a = 5;
    printf("%d\n", SQUARE(a++)); // expands to (a++ * a++)
    return 0;
} //may be 30 instead of 25 ( like it would for functions ) since it calls a++ twice


// #include <stdio.h>
// #define MULG(x,y) ((x)*(y))
// #define MULB(x,y) (x*y)
// int main()
// {
// int x = MULG(99+1,2);
// int y = MULB(99+1,2);
// printf("x is %d\n"
// ,x);
// printf("y is %d\n"
// ,y);
// return 0;
// }

// src (master) $ cc macros.c ; ./a.out
// x is 200
// y is 101 
