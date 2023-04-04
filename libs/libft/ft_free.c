/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 09:52:12 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/16 14:36:39 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_free(char **a)
{
	size_t	i;

	i = 0;
	while (a[i])
	{
		if (a[i])
			free(a[i]);
		i++;
	}
	if (a)
		free(a);
}
