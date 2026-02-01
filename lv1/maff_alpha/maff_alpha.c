#include <unistd.h>
void ft_putchar(char c)
{
    write (1,&c,1);
}

void maff_alpha (char *str)
{
    int i = 0;
    while(str[i])
    {
        if (i % 2 == 1)
        {
            str[i] -=32;
        }
        ft_putchar(str[i]);        
        i++;
    }
}

int main ()
{
    char str[] = "abcdefghijklmnopqrstuvwxyz";
    maff_alpha(str);
}