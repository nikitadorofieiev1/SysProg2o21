#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp = fopen("test.txt", "r");
  char str[100];
  int i, j, k;
  fgets(str, 100, fp);
  puts(str);
  int n = strlen(str);
  printf("Number of occurrences of characters:\n");
  for (i = 0; i < n; i++) {
    k = 0;
    for (j = 0; j < n; j++) {
      if (str[j] == str[i]) {
        k++;
      }
    }
    printf("\t%c - %d\n", str[i], k);
    while (str[i + 1] == str[i]) {
      i++;
    }
  }
  fclose(fp);
  return 0;
}
