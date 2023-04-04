/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:59:15 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/09 12:52:37 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	x;

	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	if (dstsize < i)
		x = ft_strlen(src) + dstsize;
	else
		x = ft_strlen(src) + i;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[j])
		{
			dst[i] = src[j];
			i++;
			j++;
		}
	}
	dst[i] = 0;
	return (x);
}

// #include<stdio.h>
// #include<string.h>
// int main (void)
// {
// 	printf("%s\n", strlcat(0, "source", 0));
// 	printf("%s\n", ft_strlcat(0, "source", 0));
// 	return(0);
// }