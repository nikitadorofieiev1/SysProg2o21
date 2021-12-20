#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("Wrong number of arguments\n");
		return 1;
	}

	const char* hostname = argv[1];

	struct hostent* host = gethostbyname(hostname);
	if (host == NULL)
	{
		printf("Error\n");
		return 1;
	}

	int index = 0;
	while (host->h_addr_list[index] != NULL)
	{
		struct in_addr* address = (struct in_addr*) host->h_addr_list[index];
		printf("%s\n", inet_ntoa(*address));
		++index;
	}

	return 0;
}
