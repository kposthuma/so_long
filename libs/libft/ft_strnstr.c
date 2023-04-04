/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:59:03 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/16 15:55:26 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	i;
	char	*a;

	if (!haystack && len == 0)
		return (0);
	a = (char *)haystack;
	x = 0;
	if (*needle == '\0')
		return (a);
	while (a[x] && x < len)
	{
		i = 0;
		while (a[x] == needle[i] && x < len)
		{
			x++;
			i++;
			if (needle[i] == '\0')
				return (&a[x - i]);
		}
		x = (x - i);
		x++;
	}
	return (NULL);
}

// #include<stdio.h>
// #include<string.h>
// int main (void)
// {
// 	printf("%s\n", strnstr(0, "needle", 0));
// 	printf("%s\n", ft_strnstr(0, "needle", 0));
// 	return(0);
// }