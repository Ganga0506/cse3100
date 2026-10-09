#include <stdio.h>
#include <stdarg.h>   // needed for variadic functions

int sum(int n, ...) {
    va_list args;    // declare variable argument list
    va_start(args, n); // initialize, n is last fixed parameter

    int total = 0;
    for(int i = 0; i < n; i++) {
        int x = va_arg(args, int); // get next int argument
        total += x;
    }

    va_end(args);    // clean up
    return total;
}

int main() {
    printf("%d\n", sum(3, 1, 2, 3));  // 1+2+3 = 6
    printf("%d\n", sum(5, 10, 20, 30, 40, 50)); // sum = 150
    return 0;
}