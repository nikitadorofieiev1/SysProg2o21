#include <stdio.h>
#include <dirent.h>
#include <string.h>

void ppid_finder(int pid){
    printf("%d\n", pid);
    
    if(pid == 1 || pid == 0)
        return;
        
    DIR* dirptr = opendir("/proc");
    struct dirent * entry;
    int tpid = 0;
    char buff[256];
    
    while( entry = readdir(dirptr) )
        if(sscanf(entry->d_name, "%d", &tpid) && (tpid == pid) ){
            sprintf(buff, "/%s/%d/%s", "proc", tpid, "status");
            break;
        }
    closedir(dirptr);
    
    FILE * fl_ptr = fopen(buff, "r");
    char *pb;
    
    while(fgets(buff, 256, fl_ptr))
         if(strstr(buff, "PPid")){
              for(pb = buff; *pb != '\0'; ++pb)
                if(isdigit(*pb))
                    break;
             sscanf(pb, "%d", &tpid);
             fclose(fl_ptr);
             break;
         }
    ppid_finder(tpid);
}

int main(int c, char **v){
    ppid_finder(atoi(v[1]));
    return 0;
}