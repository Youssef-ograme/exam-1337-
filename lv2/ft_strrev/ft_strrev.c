#include <stdio.h>
int ft_strlen (char *str)
{
	int i = 0;
	while (str[i])
	i++;
	return i;
}

char    *ft_strrev(char *str)
{
	int size = ft_strlen (str);
	int i = 0;
	while (i < size / 2)
	{
		char temp;
		temp = str[i];
		str[i] = str[size - 1 - i];
		str[size - 1 - i] = temp;
		i++;
	}
	return str;
}

int main ()
{
	char str[] = "hello";
	printf ("%s",ft_strrev(str));
}
