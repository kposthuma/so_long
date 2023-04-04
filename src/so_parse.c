/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_parse.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 17:42:10 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/09 11:06:00 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./so_long.h"

void	char_comp(char **map, char a, char b)
{
	if (a != b)
		error(map, NULL, "Map not enclosed\n");
}

void	wall_check(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	while (map[i][++j])
		char_comp(map, map[i][j], '1');
	j --;
	while (map[i])
		char_comp(map, map[i++][j], '1');
	i--;
	while (j)
		char_comp(map, map[i][j--], '1');
	while (i)
		char_comp(map, map[i--][j], '1');
}

void	onlythese(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
				&& map[i][j] != 'P' && map[i][j] != 'E')
				error(map, NULL, "Forbidden element present\n");
			j++;
		}
		i++;
	}
}

size_t	char_counter(char **map, char a)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == a)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	map_check(char **map)
{
	onlythese(map);
	if (char_counter(map, 'P') != 1 || char_counter(map, 'E') != 1
		|| char_counter(map, 'C') < 1)
		error(map, NULL, "Wrong element count\n");
	wall_check(map);
}
