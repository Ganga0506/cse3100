// Only this line of comment is provided 

#include <stdio.h>

int main(void)
{
    double x;
    double total = 0.0;
    double average = 0.0;
    int count = 0;

    while (scanf("%lf", &x) == 1) {
        total += x;
        count++;
        average = total / count;
        printf("Total=%f Average=%f\n", total, average);
    }
    
    return 0;
}