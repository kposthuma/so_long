/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 11:04:23 by kposthum      #+#    #+#                 */
/*   Updated: 2023/01/12 10:41:40 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_ptrlen(size_t n)
{
	int	len;

	if (n == 0)
		len = 1;
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void	ft_ptrwrite(size_t n)
{
	if (n < 16)
	{
		if (n < 10)
			ft_putchar(n + 48);
		else
			ft_putchar(n - 10 + 'a');
	}
	else
	{
		ft_ptrwrite(n / 16);
		ft_ptrwrite(n % 16);
	}
}

int	ft_putptr(size_t n)
{
	int	len;

	ft_putstr("0x");
	if (!n)
		len = 2;
	else
		len = ft_ptrlen(n);
	ft_ptrwrite(n);
	return (len + 1);
}
