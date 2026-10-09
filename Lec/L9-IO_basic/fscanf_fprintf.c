#include <stdio.h>

int main() {
    FILE *fin = fopen("numbers.txt", "r");
    FILE *fout = fopen("squares.txt", "w");

    if (!fin || !fout) {
        perror("Error opening file");
        return 1;
    }

    int num;
    // Read numbers until end of file
    while (fscanf(fin, "%d", &num) == 1) {
        fprintf(fout, "%d squared = %d\n", num, num*num);
    }

    fclose(fin);
    fclose(fout);

    printf("Squares written to squares.txt\n");
    return 0;
}