#include <unistd.h>
void ft_putchar(char c)
{
    write (1,&c,1);
}

int ft_strlen (char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

void maff_revalpha (char *str)
{
    int i = ft_strlen(str) -1;
    while (str[i])
    {
        if (i % 2 == 0)
        {
            str[i] -= 32;
        }
        ft_putchar(str[i]);
        i--;
    }
    ft_putchar('\n');
}
int main ()
{
        char str[] = "abcdefghijklmnopqrstuvwxyz";
        maff_revalpha(str);
}