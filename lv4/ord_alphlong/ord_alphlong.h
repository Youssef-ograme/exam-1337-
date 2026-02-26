#include <unistd.h>
#include <stdlib.h>
void ft_putchar (char c){
    write (1,&c,1);
}
int ft_strlen (char *str){
    int i = 0 ;
    while (str[i])
        i++;
    return i;
}
char l_upper (char c){
    return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}
int ft_strcmp(char *s1, char *s2){
    int i = 0;
    while (s1[i] && s2[i]){
        char c1 = l_upper(s1[i]), c2 = l_upper(s2[i]);
        if (c1 != c2)
            return (c1 - c2);
        i++;
    }
    return (l_upper(s1[i]) - l_upper(s2[i]));
}
int check_space (char c){
    return (c == ' ' || c == '\t')? 1 : 0;
}
int len_argements (char *str1 , char *str2){
    int len1 = ft_strlen(str1),len2 = ft_strlen(str2);
    if (len1 > len2)
        return 1;
    return 0;
}
int length_arguments (char *str){
    int new_world = 1,count = 0,i = 0;
    while (str[i]){
        if (!check_space(str[i]) && new_world){
            count++;
            new_world = 0;
        }
        else if (check_space(str[i]))
            new_world = 1;
        i++;
    }
    return count;
}
char *ft_strdup(char *str){
    char *tab = malloc (ft_strlen(str) + 1);
    int i = 0;
    while (str[i]){
        tab[i] = str[i];
        i++;
    }
    tab[i] = '\0';
    return tab;
}
char **ft_split (char *str , int *count){
    char *tab = malloc (ft_strlen(str) + 1);
    char **wstr = malloc ((length_arguments(str) + 1) * sizeof(char *));
    int j = 0,i = 0;
    *count = 0;
    if (!tab || !wstr)
        return NULL;
    while (str[i]){
        if (!check_space(str[i]))
            tab[j++] = str[i];
        else if (j > 0){
            tab[j] = '\0';
            wstr[(*count)++] = ft_strdup(tab);
            j = 0;
        }
        i++;
    }
    if (j > 0){
        tab[j] = '\0';
        wstr[(*count)++] = ft_strdup(tab);
    }
    free(tab);
    wstr[(*count)] = NULL;
    return wstr;
}
void ft_swap(char **str1 , char **str2){
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}
// sort_stringes
char **sort_wstr (char *str , int *size){
    int count,j,i = 0;
    char **wstr = ft_split(str , &count);
    while (i < count - 1){
        j = i + 1;
        while (j < count){
            if (ft_strlen(wstr[i]) > ft_strlen(wstr[j]) || (ft_strlen(wstr[i]) == ft_strlen(wstr[j]) && ft_strcmp(wstr[i],wstr[j]) > 0))
                    ft_swap(&wstr[i],&wstr[j]);
            j++;
        }
        i++;
    }
    *size = count;
    return wstr;
}
void ft_putstr(char *str){
    int i = 0;
    while (str[i]){
        ft_putchar (str[i]);
        i++;
    }
}