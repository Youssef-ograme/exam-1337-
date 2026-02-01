#include <unistd.h>
void ft_putchar (char c)
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

int check_str (char c , char *str)
{
        int j = 0;
        while (str[j])
        {
            if (str[j] == c)
            {
                return 1;
            }
            j++;
        }
    
    return 0;
}

int check_check (char *str , char c , int size)
{
    int i = 0;
    while (i < size)
    {
            if (str[i] == c)
            {
                return 1;
            }
        i++;
    }
    return 0;
}
void ft_inter (char *arg1 , char *arg2)
{
    int i = 0;
    int val;
    int n ;
    while (arg1[i])
    {
        n = check_check (arg1 , arg1[i] , i);
        val = check_str(arg1[i],arg2);
        if ((val == 1) && (n != 1))
        {        
            ft_putchar (arg1[i]);
        }
        i++;
    }
}

int main ()
{
    char arg1[] = "ddf6vewg64f";
    char arg2[] = "gtwthgdwthdwfteewhrtag6h4ffdhsd";
    ft_inter(arg1,arg2);
}