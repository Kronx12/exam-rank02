/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@42lyon.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:12:56 by gbaud             #+#    #+#             */
/*   Updated: 2021/01/04 19:48:09 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // remove
#include <limits.h> // remove

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
    int j;

    i = 0;
    j = ft_strlen(base);
    while (nb >= j && ++i)
        nb /= j;
    return (i + 1);
}

void ft_putnbr(int nb) {
    if (nb >= 10) {
        nb /= 
    }
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
        char *base = "0123456789";
        int min = 0;
        int val = va_arg(*v, int);
        if (val < 0 && ++min) val *= -1;
        int tmp_len = ft_nbrlen(val, base);

    } else if (a.t == 'x') {
        char *base = "0123456789abcdef";
        int val = va_arg(*v, int);
        
    } else if (a.t == 's') {
        char *val = va_arg(*v, char *);
        
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

int main(int argc, char const *argv[])
{
    ft_printf("%d\n", 12345);
    ft_printf("%d\n", -1234);
/*
    int intval = -1234;
    printf("[%.6d]\n", intval);
    printf("[%6d]\n", intval);
    printf("[%6.6d]\n", intval);
    printf("[%6.4d]\n", intval);
    printf("[%4.6d]\n", intval);
    printf("[%.5d]\n", intval);
    printf("[%5d]\n", intval);
    printf("[%5.5d]\n", intval);
    printf("[%.4d]\n", intval);
    printf("[%4d]\n", intval);
    printf("[%4.4d]\n\n", intval);
*/
/*
    int hexval = 74565;
    printf("[%.6x]\n", hexval);
    printf("[%6x]\n", hexval);
    printf("[%6.6x]\n", hexval);
    printf("[%6.4x]\n", hexval);
    printf("[%4.6x]\n", hexval);
    printf("[%.5x]\n", hexval);
    printf("[%5x]\n", hexval);
    printf("[%5.5x]\n", hexval);
    printf("[%.4x]\n", hexval);
    printf("[%4x]\n", hexval);
    printf("[%4.4x]\n", hexval);
*/
/*
    char *strval = NULL;
    printf("[%.7s]\n", strval);
    printf("[%7s]\n", strval);
    printf("[%7.7s]\n", strval);
    printf("[%7.5s]\n", strval);
    printf("[%5.7s]\n", strval);
    printf("[%.6s]\n", strval);
    printf("[%6s]\n", strval);
    printf("[%6.6s]\n", strval);
    printf("[%.5s]\n", strval);
    printf("[%5s]\n", strval);
    printf("[%5.5s]\n", strval);
*/
    return 0;
}
