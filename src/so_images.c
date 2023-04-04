/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_images.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 12:37:15 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/09 11:06:05 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./so_long.h"

void	draw_outside(t_gigastruct *game)
{	
	size_t	i;
	size_t	j;

	i = 0;
	while (i < strofstrlen(game->chart->map) / 16 + 3)
	{
		j = 0;
		while (j < ft_strlen(game->chart->map[0]) / 16 + 3)
		{
			mlx_image_to_window(game->mlx, game->img->outs,
				calc(game->mlx->width, j, game->chart->y) - 16 * 32
				+ j * 15 * 32, calc(game->mlx->width, i, game->chart->x)
				- 16 * 32 + i * 15 * 32);
			j++;
		}
		i++;
	}
}

void	draw_wall(t_gigastruct *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	mlx_image_to_window(game->mlx, game->img->corl, calc(game->mlx->width, j,
			game->chart->y), calc(game->mlx->width, i, game->chart->x));
	while (j++ < ft_strlen(game->chart->map[i]) - 2)
		mlx_image_to_window(game->mlx, game->img->edgt, calc(game->mlx->width,
				j, game->chart->y), calc(game->mlx->width, i, game->chart->x));
	mlx_image_to_window(game->mlx, game->img->corr, calc(game->mlx->width, j,
			game->chart->y), calc(game->mlx->width, i, game->chart->x));
	while (i++ < strofstrlen(game->chart->map) - 2)
		mlx_image_to_window(game->mlx, game->img->edgr, calc(game->mlx->width,
				j, game->chart->y), calc(game->mlx->width, i, game->chart->x));
	mlx_image_to_window(game->mlx, game->img->edgb, calc(game->mlx->width, j,
			game->chart->y), calc(game->mlx->width, i, game->chart->x));
	while (j--)
		mlx_image_to_window(game->mlx, game->img->edgb, calc(game->mlx->width,
				j, game->chart->y), calc(game->mlx->width, i, game->chart->x));
	j++;
	while (i-- > 1)
		mlx_image_to_window(game->mlx, game->img->edgl, calc(game->mlx->width,
				j, game->chart->y), calc(game->mlx->width, i, game->chart->x));
}

void	draw_images(t_gigastruct *game, mlx_image_t *image, char a)
{	
	size_t	i;
	size_t	j;

	i = 0;
	while (game->chart->map[i])
	{
		j = 0;
		while (game->chart->map[i][j])
		{
			if (game->chart->map[i][j] == a || a == '0')
				mlx_image_to_window(game->mlx, image,
					calc(game->mlx->width, j, game->chart->y),
					calc(game->mlx->width, i, game->chart->x));
			j++;
		}
		i++;
	}
}

void	draw_window(t_gigastruct *game)
{		
	draw_outside(game);
	draw_images(game, game->img->flr, '0');
	draw_images(game, game->img->wll, '1');
	draw_images(game, game->img->ldr, 'E');
	draw_images(game, game->img->itm, 'C');
	draw_images(game, game->img->plf, 'P');
	draw_images(game, game->img->plfl, 'P');
	draw_images(game, game->img->plfr, 'P');
	draw_images(game, game->img->plb, 'P');
	draw_images(game, game->img->plbl, 'P');
	draw_images(game, game->img->plbr, 'P');
	draw_images(game, game->img->pll, 'P');
	draw_images(game, game->img->plwl, 'P');
	draw_images(game, game->img->plr, 'P');
	draw_images(game, game->img->plwr, 'P');
	draw_wall(game);
	disable_player(game->img);
	game->img->plf->instances[0].enabled = true;
	hookloop(game);
}

int32_t	initialize(char **map)
{
	mlx_t			*mlx;
	size_t			*loc;
	t_maps			*chart;
	t_gigastruct	*game;

	mlx = mlx_init(WIDTH, HEIGHT, "POKeMON", false);
	chart = (t_maps *)ft_calloc(sizeof(t_maps), 1);
	game = (t_gigastruct *)ft_calloc(sizeof(t_gigastruct), 1);
	if (!mlx || !game || !chart)
		return (mlx_terminate(mlx), free(chart), free(game), ft_free(map),
			exit(-1), -1);
	loc = find_player(map);
	game->mlx = mlx;
	chart->map = map;
	chart->x = loc[0];
	chart->y = loc[1];
	free(loc);
	game->chart = chart;
	game->img = image_getter(game);
	game->chart->items = char_counter(game->chart->map, 'C');
	draw_window(game);
	return (free_and_exit(game), 0);
}
