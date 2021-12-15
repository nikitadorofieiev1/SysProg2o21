#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

int main()
{
	DIR * path = opendir("/proc/");
	struct dirent *file;
	int count = 0;
	while ((file = readdir(path)) != NULL)
	{
		if (isdigit(file->d_name[0]))
		{
			char str[20];
			strcpy(str, "/proc/");
			strcat(str, file->d_name);
			DIR *pt = opendir(str);
			struct dirent *f;
			while ((f = readdir(pt)) != NULL)
			{
				if (strcmp(f->d_name, "comm") == 0)
				{
					strcat(str, "/");
					strcat(str, f->d_name);
					FILE *fp = fopen(str, "r");
					if (feof(fp))
					{
						printf("Error\n");
					}
					char buffer[100];
					fgets(buffer, 100, fp);
					if (strcmp(buffer, "systemd\n") == 0)
					{
						count++;
					}
					fclose(fp);
				}
			}
			closedir(pt);
		}
	}
	printf("%d\n", count);
	closedir(path);
	return 0;
}