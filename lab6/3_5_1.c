#include <stdio.h>

int main() {
  FILE* fd = fopen("/proc/self/stat", "r");

  char readed_line[512];
  int idx = 4;
  while (idx > 0){
    fscanf(fd, "%s", readed_line);
    --idx;
  }
  int* ppid;
  fscanf(fd, "%d", ppid);
  fclose(fd);
  printf("%d\n", *ppid);
  return 0;
}