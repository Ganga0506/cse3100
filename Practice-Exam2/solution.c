#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {

  int pa[2], ap[2], ab[2], ba[2], pb[2], bp[2];
  pipe(pa);
  pipe(ap);
  pipe(ab);
  pipe(ba);
  int A = fork();
  if (A == 0) {
    close(pa[1]);
    close(ap[0]);
    close(ab[0]);
    close(ba[1]);
    char v;
    read(pa[0], &v, sizeof(char));
    close(pa[0]);
    printf("Child 1 read:%c\n", v);
    v = v + 1;
    write(ab[1], &v, sizeof(char));
    close(ab[1]);
    printf("Child 1 wrote:%c\n", v);
    read(ba[0], &v, sizeof(char));
    close(ba[0]);
    printf("Child 1 read:%c\n", v);
    v = v + 1;
    write(ap[1], &v, sizeof(char));
    close(ap[1]);
    printf("Child 1 wrote:%c\n", v);
    return 0;
  }
  close(pa[0]);
  close(ap[1]);
  close(ab[1]);
  close(ba[0]);
  pipe(pb);
  pipe(bp);
  int B = fork();
  if (B == 0) {
    close(bp[0]);
		close(pa[1]);
		close(ap[0]);
    close(pb[1]);
    char v;
    read(ab[0], &v, sizeof(char));
    close(ab[0]);
    printf("Child 2 read:%c\n", v);
    v = v + 1;
    write(bp[1], &v, sizeof(char));
    close(bp[1]);
    printf("Child 2 wrote:%c\n", v);
    read(pb[0], &v, sizeof(char));
    printf("Child 2 read:%c\n", v);
    close(pb[0]);
    v = v + 1;
    write(ba[1], &v, sizeof(char));
    close(ba[1]);
    printf("Child 2 wrote:%c\n", v);
    return 0;
  }
  char v = argv[1][0];
	close(ab[0]);
	close(ba[1]);
  close(bp[1]);
  close(pb[0]);
  write(pa[1], &v, sizeof(char));
  close(pa[1]);
  printf("Parent wrote:%c\n", v);
  read(bp[0], &v, sizeof(char));
  close(bp[0]);
  printf("Parent read:%c\n", v);
  v = v + 1;
  write(pb[1], &v, sizeof(char));
  close(pb[1]);
  printf("Parent wrote:%c\n", v);
  read(ap[0], &v, sizeof(char));
  close(ap[0]);
  printf("Parent read:%c\n", v);
  waitpid(A, NULL, 0);
  waitpid(B, NULL, 0);
  return 0;
}
