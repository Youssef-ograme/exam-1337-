#include <unistd.h>
void ft_putchar (char c)
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

void test (char *str)
{
    int i = 0;
    int val;
    while (str[i])
    {
        val = check_index (str[i]);
        
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (val == 25)
            {
                str[i] = 'a';
            }
            else
            {
                str[i] += 1;
            }            
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            if (val == 25)
            {
                str[i] = 'A';
            }
            else 
            {
                str[i] += 1;
            }
        }
        ft_putchar (str[i]);
        i++;
    }
}

int main ()
{
    char str[] = "AkjhZ zLKIJz , 23y ";
    test(str);
}