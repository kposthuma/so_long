/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:59:18 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/16 15:53:52 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	char	*b;
	size_t	i;

	b = (char *)s1;
	i = 0;
	a = (char *)ft_calloc((ft_strlen(b) + 1), sizeof(char));
	if (!a)
		return (NULL);
	while (b[i])
	{
		a[i] = b[i];
		i++;
	}
	return (a);
}
