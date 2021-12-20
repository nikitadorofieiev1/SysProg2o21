#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int user1_sig = 0;
int user2_sig = 0;


void user_signal_handler(int signalno) {
    switch (signalno) {
        case SIGUSR1:
            user1_sig++;
            break;
        case SIGUSR2:
            user2_sig++;
            break;
        default: {
            printf("%d %d\n", user1_sig, user2_sig);
            exit(0);
        }

    }
}


int main(int argc, char **argv) {

    signal(SIGUSR1, user_signal_handler);
    signal(SIGUSR2, user_signal_handler);
    signal(SIGTERM, user_signal_handler);

    while(1) {
        usleep(50000);
    }

    return 0;
}