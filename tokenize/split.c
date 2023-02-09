
#include <stdio.h>
#include <string.h>
 
int main()
{
	char str[100];
	int i, len;

	printf("Enter a string : ");
	gets(str);

	len = strlen(str);
	printf("Splitting string \"%s\" into tokens:\n\n", str);

	for (i = 0; i < len; i++)
	{
		if (str[i] == ' ' || str[i] == '$')
		{
			str[i] = '\0';
			printf("%s\n", &str[i + 1]);
		}
	}
	printf("%s\n", str);

	return 0;
}