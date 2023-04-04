/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_maps.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/15 17:34:49 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/09 14:58:40 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./so_long.h"

char	*trim_one(char *str1, char a)
{
	char	*str2;
	size_t	i;
	size_t	j;

	if (!str1)
		return (NULL);
	i = (ft_strlen(str1));
	if (str1[i - 1] != a)
		return (str1);
	str2 = ft_calloc((i), sizeof(char));
	if (!str2)
		return (NULL);
	j = 0;
	while (j < (i - 1))
	{
		str2[j] = str1[j];
		j++;
	}
	free(str1);
	return (str2);
}

char	**make_map_(char *mapfile, size_t height)
{
	char	**map;
	size_t	i;
	int		fd;

	map = ft_calloc((height + 1), sizeof(char *));
	if (!map)
		error(NULL, NULL, "Malloc error\n");
	fd = open(mapfile, O_RDONLY);
	if (fd < 0 || !map)
		error(NULL, NULL, "Failed to open file\n");
	i = 0;
	while (i < height)
	{
		map[i] = get_next_line(fd);
		map[i] = trim_one(map[i], '\n');
		if (!map[i])
			error(map, NULL, "Malloc error\n");
		i++;
	}
	return (map);
}

size_t	map_height(char *mapfile)
{
	size_t	height;
	int		fd;
	char	*line;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		error(NULL, NULL, "Failed to open file\n");
	line = get_next_line(fd);
	height = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	return (height);
}

char	**make_map(char *mapfile)
{
	size_t	height;
	char	**map;

	height = map_height(mapfile);
	map = make_map_(mapfile, height);
	return (map);
}

void	rectangular_check(char *mapfile)
{
	int		fd;
	char	*line;
	size_t	len1;
	size_t	len2;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		error(NULL, NULL, "Failed to open file\n");
	line = get_next_line(fd);
	len1 = ft_strlen(line);
	while (line)
	{
		if (line != NULL)
			len2 = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
		if (len1 != len2 && line != NULL)
			error(NULL, line, "Wrong map shape\n");
	}
	if (len1 != (len2 + 1))
		error(NULL, line, "Wrong map shape\n");
}
