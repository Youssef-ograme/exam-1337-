#include "ord_alphlong.h"
// sort_lines
void link_programe (char *str){
    int size;
    char **wstr = sort_wstr(str , &size);
    int i = 0 , stok = ft_strlen(wstr[0]);
    while (i < size)
    {
        if (ft_strlen(wstr[i]) != stok){
            ft_putchar ('\n');
            stok = ft_strlen(wstr[i]);
        }
        ft_putstr(wstr[i]);
        if (i + 1 < size && ft_strlen(wstr[i + 1]) == stok)
        {
            ft_putchar (' ');
        }
        i++;
    }
    i = 0;
    while (i < size){
        free(wstr[i]);
        i++;
    }
    free(wstr);
}

int main (int argc , char *argv[])
{
    if (argc == 2)
    {
        link_programe(argv[1]);
    }
    ft_putchar ('\n');
}