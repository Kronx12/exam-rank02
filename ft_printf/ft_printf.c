/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@42lyon.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:12:56 by gbaud             #+#    #+#             */
/*   Updated: 2021/01/04 00:27:26 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // remove

typedef struct  s_arg
{
                char t;
                int w;
                int p;
}               t_arg;

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_nbrlen(int nb, char *base)
{
    int i;

    i = 0;
    while (++i && nb > 9)
        nb /= ft_strlen(base);
    return (i);
}

int max(int v1, int v2, int v3)
{
    if (v1 > v2 && v1 > v3)
        return (v1);
    return (v2 > v3 ? v2 : v3);
}

int print_arg(const char *str, int *i, va_list *v)
{
    char *buffer;
    t_arg a;
    int len;
    int j;

    a.p = 0;
    a.w = 0;
    while (str[*i] >= '0' && str[*i] <= '9')
        a.p = a.p * 10 + (str[(*i)++] - '0');
    if (str[*i] == '.')
        (*i)++;
    while (str[*i] >= '0' && str[*i] <= '9')
        a.w = a.w * 10 + (str[(*i)++] - '0');
    a.t = str[*i];

    j = -1;
    len = 0;
    if (a.t == 'd') {
        buffer = malloc(1);
        buffer[0] = 0;
    } else if (a.t == 'x') {
        buffer = malloc(1);
        buffer[0] = 0;
    } else if (a.t == 's') {
        char *val = va_arg(*v, char *);
        if (!val)
            val = "(null)";
        buffer = malloc(1);
        buffer[0] = 0;

    }

    j = -1;
    while (++j < len)
        write(1, &buffer[j], 1);
    free(buffer);
    return (0);
}

int ft_printf(const char *str, ...)
{
    int i;
    int len;
    va_list v;

    va_start(v, str);

    i = -1;
    len = 0;
    while (str[++i])
        if (str[i] == '%' && ++i)
            len += print_arg(str, &i, &v);
        else
            len += write(1, &str[i], 1);
    return (len);
}