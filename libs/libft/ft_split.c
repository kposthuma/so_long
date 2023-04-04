/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:00:13 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/16 15:53:19 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_length(char *x, char c, size_t index)
{
	size_t	len;

	len = 0;
	while (x[index] != c && x[index])
	{
		index++;
		len++;
	}
	return (len);
}

static char	**fillup(char **a, char *x, char c, size_t i)
{
	size_t	j;
	size_t	index;
	size_t	len;

	j = 0;
	index = 0;
	while (j < (i - 1))
	{
		while (x[index] == c)
			index++;
		len = ft_length(x, c, index);
		a[j] = ft_substr(x, (index), len);
		if (!a[j])
			return (ft_free(a), NULL);
		index += len;
		j++;
	}
	return (a);
}

static size_t	count(char *x, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (x[i])
	{
		while (x[i] == c)
			i++;
		if (x[i] != c && x[i])
			j++;
		while (x[i] != c && x[i])
			i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	*x;
	char	**a;

	x = (char *)s;
	i = count(x, c);
	a = (char **)ft_calloc(i, sizeof(char *));
	if (!a)
		return (NULL);
	a = fillup(a, x, c, i);
	return (a);
}

// #include<stdio.h>
// int main (int argc, char **argv)
// {
// 	int i = 0;
// 	char **c = ft_split("aap noot mies", 32);
// 	while (c[i])
// 	{
// 		printf("%s\n", c[i]);
// 		i++;
// 	}
// 	return (0);
// }