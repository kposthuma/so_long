/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printwrite.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 12:15:35 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/02 13:01:43 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"), 6);
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

int	ft_putnbr_(unsigned int n)
{
	int				len;
	unsigned int	t;

	len = 0;
	t = n;
	if (n == 0)
		len = 1;
	while (t)
	{
		t = t / 10;
		len++;
	}	
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr_(n / 10);
		ft_putnbr_(n % 10);
	}
	return (len);
}

int	ft_printnbr(int n)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		return (ft_putnbr_((unsigned int)n) + 1);
	}
	else
		return (ft_putnbr_((unsigned int)n));
}
