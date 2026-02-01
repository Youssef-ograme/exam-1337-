#include <unistd.h>
void ft_putchar (char c)
{
    write (1,&c,1);
}

void ft_countdown (void)
{
    char c = '9';
    while (c >= '0')
    {
        ft_putchar(c);
        c--;
    }
    ft_putchar('\n');
}

int main ()
{
    ft_countdown();
}