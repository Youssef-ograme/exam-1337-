#include <unistd.h>
void ft_putchar(char c)
{
    write (1,&c,1);
}

int check_char (char c)
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
void ft_rot_13 (char *str)
{
   int i = 0;
   int val;
   while (str[i])
   {
        val = check_char(str[i]);
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            if (val >= 13)
            {
                str[i] -= 13;
            }
            else if (val <= 13)
            {
                str[i] += 13;
            }
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (val >= 13)
            {
                str[i] -= 13;
            }
            else if (val <= 13)
            {
                str[i] += 13;
            }
        }
        ft_putchar(str[i]);
        i++;
   }
   ft_putchar('\n');
}
int main ()
{
    char str[] = "My horse is Amazing.";
    ft_rot_13(str);
}