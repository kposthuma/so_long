/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:59:20 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/16 15:53:33 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*a;
	unsigned char	x;
	size_t			i;
	size_t			j;

	a = (char *)s;
	x = c;
	i = 0;
	j = ft_strlen(a) + 1;
	while (i < j)
	{
		if (a[i] == x)
			return (&a[i]);
		i++;
	}
	return (NULL);
}
