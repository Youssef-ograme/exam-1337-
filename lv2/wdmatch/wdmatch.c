#include <unistd.h>
void ft_putchar (char c)
{
	write (1,&c,1);
}
#include <stdio.h>
void ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		ft_putchar (str[i]);
	i++;
	}
}

int ft_strlen (char *str)
{
	int i = 0;
	while (str[i])
	i++;
	return i;
}

void wdmatch (char *src , char *str)
{
	int len = ft_strlen (src);
	int i = 0;
	int j = 0;
	while (str[j] && i < len)
	{
		if (str[j] == src[i])
		{
			i++;
		}
		j++;
	}

	if (i == len)
		ft_putstr(src);
	
}
int main (int argc , char *argv[])
{
	if (argc == 3)
	{
		wdmatch(argv[1], argv[2]);
	}
	ft_putchar ('\n');
}
