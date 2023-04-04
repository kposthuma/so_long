/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:01:01 by kposthum      #+#    #+#                 */
/*   Updated: 2022/10/13 14:40:56 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*a;
	char	*b;
	size_t	i;
	size_t	j;

	a = (char *)s1;
	if (!a && !set)
		return (0);
	if (ft_strlen(a) == 0)
	{
		b = (char *)ft_calloc(1, sizeof(char));
		return (b);
	}
	i = 0;
	j = ft_strlen(a) - 1;
	while (ft_strchr(set, a[i]) != 0)
		i++;
	while (ft_strchr(set, a[j]) != 0)
		j--;
	b = ft_substr(a, i, (1 + j - i));
	return (b);
}
