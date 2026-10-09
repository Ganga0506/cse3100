// 


// Online C compiler to run C program online
#include <stdio.h>

int power(int base,int exp){
    if(base==0){
        return 0;
    }
    else if(exp==0){
        return 1;
    }
    int p= power(base,--exp); 
    return base*p;
}

int main() {
    // Write C code here
    int out = power(2,3);
    printf("%d",out);

    return 0;
}