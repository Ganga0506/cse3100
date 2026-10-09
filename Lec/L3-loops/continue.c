#include <stdio.h>

int main() {
    for (int i = 1; i <= 5; i++) {
        if (i % 2 == 0) {
            continue;  // skip even numbers
        } else {
            printf("%d ", i);
        }
    }
    return 0;
}