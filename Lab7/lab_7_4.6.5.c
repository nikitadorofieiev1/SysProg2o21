#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>

#define SHM_SIZE 1000

int main(int argc, char const *argv[])
{
    /* Get to available shared memory */
    int shm1 = shmget(atoi(argv[1]), SHM_SIZE, 0666);
    int shm2 = shmget(atoi(argv[2]), SHM_SIZE, 0666);

    /* Create shared memory. With flag IPC_CREAT */
    key_t key = ftok("solution.c", 'R');
    int result = shmget(key, SHM_SIZE, 0666|IPC_CREAT);

    /* Atach to avaible sahred memory */
    int *shm_addr1 = shmat(shm1, NULL, 0);
    int *shm_addr2 = shmat(shm2, NULL, 0);
    int *shm_result = shmat(result, NULL, 0);

    
    int i=0;
    for (i = 0; i < 100; i++) {
        shm_result[i] = shm_addr1[i] + shm_addr2[i];
    }

    printf("%d\n", key);
    return 0;
}
