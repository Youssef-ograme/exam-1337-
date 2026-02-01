#include <unistd.h>
void ft_putchar(char c)
{
    write (1,&c,1);
}

void ft_ulstr (char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
        ft_putchar(str[i]);
        i++;
    }
    ft_putchar('\n');
}

int main (int argc , char *argv[])
{
    // ./a.out hello brother 
    if (argc != 2)
    {
        ft_putchar('\n');
    }
    else if (argc == 2)
    {
        ft_ulstr(argv[1]);
    }
}