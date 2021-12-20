//
// Created by Arseny Ivanov on 2018-03-29.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if(argc < 2) { exit(0); };

    char command[100];
    snprintf(command, 100, "./%s %s", argv[1], argv[2]);
    FILE *fp = popen(command, "r");

    int counter = 0;
    int c;

    if (fp != NULL) {
        while((c = fgetc(fp)) != EOF)
            if (c == '0') counter++;
    }

    pclose(fp);
    printf("%d\n", counter);

    return 0;
}
