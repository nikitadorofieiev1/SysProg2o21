#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void findChildren(const long pid, int *count){
    char buf[255];
    long ppid = 0;

    sprintf(buf, "/proc/%ld/task/%ld/children", pid, pid);

    FILE *fp = fopen(buf, "r");
    if(fp == NULL){
        return;
    }

    while (fscanf(fp, "%ld", &ppid) != EOF)
    {
        findChildren(ppid, count);
        (*count)++;
    }
    fclose(fp);
}

int main(int c, char **v) {

    if(c != 2){
        perror("set PID");
        exit(EXIT_FAILURE);
    }
    int count = 1;
    char * pEnd;

    findChildren(strtol(v[1], &pEnd, 10), &count);

    printf("%d\n", count);
    
    exit(EXIT_SUCCESS);
}