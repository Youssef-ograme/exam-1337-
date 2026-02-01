#include <unistd.h>
void ft_putchar (char c)
{
    write (1,&c,1);
}

void check_str (char *str)
{
    int i = 0;
    int j ;
    while (str[i])
    {
        j = i + 1;
        while (str[j])
        {
            if (str[j] == str[i])
            {
                ft_putchar (str[i]);
            }
            j++;
        }
        i++;
    }
}


int main ()
{
    char str[] = "hello";
    check_str(str);
}