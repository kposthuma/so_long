/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 11:58:45 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/02 13:01:50 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdlib.h>
# include<stdarg.h>

int	ft_printf(const char *iets, ...);
int	ft_decider(const char iets, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_printnbr(int n);
int	ft_putnbr_(unsigned int n);
int	ft_puthex(unsigned int n, const char A);
int	ft_hexupp(unsigned int n);
int	ft_hexlow(unsigned int n);
int	ft_putptr(size_t n);

#endif