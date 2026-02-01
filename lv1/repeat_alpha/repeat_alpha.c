#include <unistd.h>
void ft_putchar(char c)
{
    write (1,&c,1);
}
int check_index (char c)
{
    char l_str[] = "abcdefghijklmnopqrstuvwxyz";
    char u_str[] = "ABCDEFJHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    while (l_str[i] || u_str[i])
    {
        if (l_str[i] == c)
        {
            return i;
        }
        if (u_str[i] == c)
        {
            return i;
        }
        i++;
    }
    return 0;
}

void repeat_alpha (char *str)
{
    int i = 0;
    int val ;
    while (str[i])
    {
        val = check_index(str[i]);
        int j = 0 ;
        while (j <= val)
        {
            ft_putchar(str[i]);
            j++;
        }
        i++;
    }
    ft_putchar('\n');
}

int main (int argc , char *argv[])
{
    // if (argc == 1)
    // {
    //     ft_putchar('\n');
    // }
    if (argc == 2)
    {
        repeat_alpha(argv[1]);
    }
    else 
    {
        ft_putchar('\n');
    }
}