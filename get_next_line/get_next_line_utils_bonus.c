#include "get_next_line.h"

size_t ft_strlen_gnl(const char *s)
{
    size_t i;
    if (!s)
        return 0;
    i = 0;
    while (s[i])
        i++;
    return i;
}

char *ft_strchr_gnl(const char *s, int c)
{
    size_t i;
    if (!s)
        return NULL;
    i = 0;
    while (s[i])
    {
        if (s[i] == (char)c)
            return (char *)&s[i];
        i++;
    }
    if (s[i] == (char)c)
        return (char *)&s[i];
    return NULL;
}

char *ft_strjoin_gnl(char *s1, char *s2)
{
    size_t i;
    size_t j;
    char *str;

    if (!s1)
    {
        s1 = (char *)malloc(1);
        if (!s1)
            return NULL;
        s1[0] = '\0';
    }
    if (!s2)
        return NULL;
    str = (char *)malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
    if (!str)
        return NULL;
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
        str[i++] = s2[j++];
    str[i] = '\0';
    free(s1);
    return str;
}

int found_newline(char *s)
{
    int i;
    if (!s)
        return 0;
    i = 0;
    while (s[i])
    {
        if (s[i] == '\n')
            return 1;
        i++;
    }
    return 0;
}
