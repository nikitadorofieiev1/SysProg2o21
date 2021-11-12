#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char str[100];
	printf("Enter string: ");
	fgets(str, 100, stdin);
	FILE *fp = fopen("test.txt", "w");
	int i, j, e, k = 0;
	char *str1 = (char*) malloc (strlen(str)-1);	
	for (i = 0; i < strlen(str); i++)
	{
		e = str[i];
		if ((e >= 65 && e <= 90) || (e >= 97 && e <= 122))
		{
			str1[k] = str[i];
			k++;

		}
	}
	puts(str1);
	for (i = 0; i < strlen(str1) - 1; i++)
	{
		for (j = 0; j < strlen(str1)-i-1; j++)
		{
			if (str1[j] > str1[j+1])
			{
				char tmp = str1[j];
				str1[j] = str1[j+1];
				str1[j+1] = tmp;
			}
		}
	}
	puts(str1);
	fputs(str1, fp);
	fclose(fp);
	free(str1);
	return 0;
}
