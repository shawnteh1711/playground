#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 

#define NO_OF_CHARS 256 

/* Returns false if str has duplicate characters within same string. */
bool areAllCharactersUnique(char* str) 
{ 
	
	if (strlen(str) > NO_OF_CHARS) 
		return false; 

	bool ch[NO_OF_CHARS] = { false }; 

	for (int i = 0; str[i] != '\0'; i++) { 
		if (ch[str[i]] == true) 
			return false; 

		ch[str[i]] = true; 
	} 

	return true; 
} 

/*Driver program to test above function */
int main() 
{ 
	char str[] = "aacd"; 

	if (areAllCharactersUnique(str)) 
		printf("The String %s has all unique characters\n", str); 
	else
		printf("The String %s has duplicate characters\n", str); 

	return 0; 
}