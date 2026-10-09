#include <stdio.h>

int main() {
  char s[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
  char t[5] = "Hello";
	char a[]="Hello";

	printf("%s\n",s);
	printf("%s\n",t); // t
  printf("%ld\n", sizeof(s));
  printf("%ld\n", sizeof(t));
  printf("%ld\n", sizeof(a));

  return 0;
}
