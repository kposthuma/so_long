/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:59:00 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/16 15:55:47 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*a;
	unsigned char	x;
	int				i;

	a = (char *)s;
	x = c;
	i = 0;
	while (a[i])
		i++;
	while (i >= 0)
	{
		if (a[i] == x)
			return (&a[i]);
		i--;
	}
	return (NULL);
}
