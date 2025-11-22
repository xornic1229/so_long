/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:57:11 by jaialons          #+#    #+#             */
/*   Updated: 2025/10/15 21:03:57 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		process(va_list args, char format);
int		format_char(va_list args);
int		format_str(va_list args);
int		format_ptr(va_list args);
int		format_nbr(va_list args);
int		format_unbr(va_list args);
int		format_hex(va_list args, char format);
int		ft_putchar(const char c);
int		ft_putstr(char *s);
int		ft_puthex(unsigned long nbr, char *base);
int		ft_putptr(void *ptr);
void	ft_putnbr(int n);
void	ft_putunbr(unsigned int n);
int		count_digits(int i);
int		count_udigits(unsigned int i);

#endif