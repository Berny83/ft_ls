#include "includes/ls.h"
#include <stdio.h>

int		ftt_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	printf("%c %c\n", *s1, *s2);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int		main(void)
{
	int	i = 0;
	char s1[] = ".git";
	char s2[] = ".git"; 
	i = ftt_strcmp(s1, s2);
	printf("%i\n", i);
	return(0);
}