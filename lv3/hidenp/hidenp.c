#include <unistd.h>
void ft_putchar (char c)
{
    write (1,&c,1);
}
int ft_strlen (char *str)
{
    int i = 0;
    while(str[i])
    i++;

    return i;
}

void check_programe (char *src , char *str)
{
    int i = 0;
    int size = ft_strlen(src);
    int j = 0;
    while (str[j] && i < size)
    {
        if (str[j] == src[i])
        {
            i++;
        }
        j++;
    }

    if (i == size)
    {
        ft_putchar('1');
        ft_putchar('\n');
    }
    else 
    {
                ft_putchar('0');
                ft_putchar('\n');
    }
}

int main (int argc , char *argv[])
{
    if (argc == 3)
    {
        check_programe(argv[1],argv[2]);
    }
    else 
    {
                ft_putchar('\n');
    }
}