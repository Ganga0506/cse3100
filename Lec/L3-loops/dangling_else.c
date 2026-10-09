#include<stdio.h>

int main(){
int x = 1, y = -1;

if(x > 0){
    if (y > 0){
        printf("A\n");
    }
    else{
        printf("B\n");  // goes with `if (y > 0)`
    }
}
}