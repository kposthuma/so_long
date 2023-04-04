/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:01:07 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/16 15:56:55 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_size(char *b, size_t start, size_t len)
{
	size_t	j;

	j = 0;
	while (b[start++] && j < len)
		j++;
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	char	*b;
	size_t	j;

	b = (char *)s;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	j = ft_size(b, start, len);
	a = (char *)ft_calloc((j + 1), sizeof(char));
	if (!a)
		return (NULL);
	j = 0;
	while (j < len && b[start])
		a[j++] = b[start++];
	return (a);
}
