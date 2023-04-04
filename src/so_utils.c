/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 13:17:16 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/09 16:54:34 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./so_long.h"

void	free_and_exit(t_gigastruct *game)
{
	ft_free(game->chart->map);
	free(game->chart);
	mlx_delete_image(game->mlx, game->img->itm);
	mlx_delete_image(game->mlx, game->img->wll);
	mlx_delete_image(game->mlx, game->img->ldr);
	mlx_delete_image(game->mlx, game->img->flr);
	mlx_delete_image(game->mlx, game->img->plf);
	mlx_delete_image(game->mlx, game->img->plfl);
	mlx_delete_image(game->mlx, game->img->plfr);
	mlx_delete_image(game->mlx, game->img->plb);
	mlx_delete_image(game->mlx, game->img->plbl);
	mlx_delete_image(game->mlx, game->img->plbr);
	mlx_delete_image(game->mlx, game->img->pll);
	mlx_delete_image(game->mlx, game->img->plwl);
	mlx_delete_image(game->mlx, game->img->plr);
	mlx_delete_image(game->mlx, game->img->plwr);
	free(game->img);
	mlx_terminate(game->mlx);
	free(game);
	exit(0);
}

void	error(char **str1, char *str2, char *str3)
{
	write(2, "Error\n", 6);
	if (str1)
		ft_free(str1);
	free(str2);
	ft_putstr_fd(str3, 2);
	exit(-1);
}

size_t	*find_player(char **map)
{
	size_t	x;
	size_t	y;
	size_t	*p_loc;

	x = 0;
	p_loc = malloc(2 * sizeof(size_t));
	if (!p_loc)
		error(map, NULL, "Malloc error\n");
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				p_loc[0] = x;
				p_loc[1] = y;
				return (p_loc);
			}
			y++;
		}
		x++;
	}
	return (p_loc);
}

int32_t	calc(int32_t x, size_t y, size_t z)
{
	int32_t	cor;

	cor = (x - SIZE) / 2 + (SIZE * (y - z));
	return (cor);
}

bool	is_centered(t_gigastruct *game)
{
	size_t	i;

	i = 0;
	while (i < strofstrlen(game->chart->map) * ft_strlen(game->chart->map[0]))
	{
		if (game->img->flr->instances[i].x == game->img->plf->instances[0].x
			&& game->img->flr->instances[i].y == game->img->plf->instances[0].y)
			return (true);
		i++;
	}
	return (false);
}
// 
// void	print_map(char **map)
// {
// 	size_t	i;

// 	i = 0;
// 	while (map[i])
// 	{
// 		ft_printf("%s\n", map[i]);
// 		i++;
// 	}
// }