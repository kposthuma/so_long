/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 13:29:12 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/09 17:01:20 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./so_long.h"

size_t	strofstrlen(char **chars)
{
	size_t	i;

	i = 0;
	while (chars[i])
		i++;
	return (i);
}

void	map_checker(int argc, char	*mapfile)
{
	char	**map;

	if (argc != 2 || !extension_checker(mapfile, ".ber"))
		error(NULL, NULL, "Incorrect file input\n");
	rectangular_check(mapfile);
	map = make_map(mapfile);
	map_check(map);
	flood_fill(map);
	ft_free(map);
}

bool	extension_checker(char *str1, char *str2)
{
	int	l1;
	int	l2;
	int	j;

	l1 = ft_strlen(str1);
	l2 = ft_strlen(str2);
	j = 1;
	while (j <= l2)
	{
		if (str1[l1 - j] != str2[l2 - j])
			return (false);
		j++;
	}
	return (true);
}

char	**flood_filler(char **map, size_t x, size_t y)
{
	map[x][y] = '2';
	if (map[x][y + 1] != '1' && map[x][y + 1] != '2')
		map = flood_filler(map, x, (y + 1));
	if (map[x][y - 1] != '1' && map[x][y - 1] != '2')
		map = flood_filler(map, x, (y - 1));
	if (map[x + 1][y] != '1' && map[x + 1][y] != '2')
		map = flood_filler(map, (x + 1), y);
	if (map[x - 1][y] != '1' && map[x - 1][y] != '2')
		map = flood_filler(map, (x - 1), y);
	return (map);
}

void	flood_fill(char **map)
{
	size_t	*location;

	location = find_player(map);
	flood_filler(map, location[0], location[1]);
	free(location);
	if (char_counter(map, 'E') != 0
		|| char_counter(map, 'C') != 0)
		error(map, NULL, "Exit or collectables are out of reach\n");
}
