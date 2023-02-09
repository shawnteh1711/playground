#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 

// function to check if environment variable already exists 
int check_env_var(char *name) 
{ 
	// getting env list 
	extern char **environ; 
	char **env = environ; 

	// iterate over the variables and check 
	// if the required variable already exists 
	// while (*env) 
	// { 
		// comparing the input variable 
		// with the environment variable 
	// 	if (strncmp(name, *env, strlen(name)) == 0) 
	// 		return 1; 
	// 	env++; 
	// }
	if (getenv(name) == NULL)
		perror("getenv");
	return 0; 
} 

// function to add new environment variable 
void add_env_var(char *name, char *value) 
{ 
	// checking if the environment variable already exists 
	if (getenv(name) == NULL) 
	{ 
		// if exists, change the value of existing variable 
		if (setenv(name, value, 1) != 0) 
			perror("setenv"); 
	} 
	else
	{ 
		// if not exists, add it to the environment list
		char str[100];
		strcpy(str, name);
		strcat(str, "=");
		strcat(str, value);
		if (putenv(str) != 0) 
			perror("putenv"); 
	} 
} 

// driver code 
int main() 
{ 
	// creating variable name
	char name[] = "NAME"; 

	// creating variable value 
	char value[] = "geeksforgeeks"; 

	// function to add new environment variable 
	add_env_var(name, value); 

	// printing the value of 'NAME' 
	printf("%s=%s\n", name, getenv(name)); 

	return 0; 
}