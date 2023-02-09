
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isPermutationOf(const char *s1, const char *s2)
{
	if (s1 == s2)
		return (TRUE);
	return (FALSE);
}


void	test(int expected, int actual, const char *testName)
{
	if (expected == actual)
	{
		printf("\n%s PASSED.", testName);
	}
	else
	{
		printf("\n%s FAILED. expected: %d actual: %d", testName, expected, actual);
	}
	
}

int main(void)
{
	test(TRUE, isPermutationOf("abc", "a"), "a");
	test(TRUE, isPermutationOf("abc", "abc"), "abc");
	return (0);
}
