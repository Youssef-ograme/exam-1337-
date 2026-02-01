#include <unistd.h>
void ft_putchar (char c)
{
    write (1,&c,1);
}

void aff_first_param (char *str)
{
    int i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
    ft_putchar('\n');
}

int main (int argc , char *argv[])
{
    if (argc > 1)
    {
        aff_first_param(argv[1]);
    }
    else if (argc == 1)
    {
        ft_putchar('\n');
    }
}