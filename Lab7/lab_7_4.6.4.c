//
// Created by mar on 29.03.19.
//


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig)
{
    exit(0);
}

int main() {

	pid_t p = setsid();
	chdir("/");
	printf("%d\n", getpid());
	fclose(stdin);
	fclose(stdout);
	fclose(stderr);
	signal(SIGURG, handler);
	sleep(10);
	return 0;
}
