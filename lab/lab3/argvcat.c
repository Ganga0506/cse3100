#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* print out an error message and exit */
void my_error(char *s)
{
    perror(s);
    exit(1);
}

/* Concatnate two strings.
 * Dynamically allocate space for the result.
 * Return the address of the result.
 */
char *my_strcat(const char *s1, const char *s2)
{
    // TODO 
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *newstr = malloc(len1 + len2 + 1);

    if (newstr == NULL) {
        my_error("malloc failed");
    }

    strcpy(newstr, s1);
    strcat(newstr, s2);


    return newstr;
}

int main(int argc, char *argv[])
{
    char    *s;
    char    *old;

    s = my_strcat("", argv[0]);

    for (int i = 1; i < argc; i ++) {
        old = s;
        s = my_strcat(s, argv[i]);
        free(old);
    }

    printf("%s\n", s);
    free(s);

    return 0;
}
