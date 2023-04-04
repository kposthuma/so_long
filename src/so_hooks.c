/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_hooks.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:29:42 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/09 16:59:06 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./so_long.h"

bool	exit_check(t_gigastruct *game)
{
	if (char_counter(game->chart->map, 'C') == 0
		&& game->img->plf->instances[0].x == game->img->ldr->instances[0].x
		&& game->img->plf->instances[0].y == game->img->ldr->instances[0].y)
	{
		ft_printf("Congratulatons!\nYou have successfully completed the game!\n");
		return (true);
	}
	return (false);
}

bool	move_vert(t_gigastruct *game, int dir)
{
	size_t	*loc;

	loc = find_player(game->chart->map);
	if (game->chart->map[loc[0] + dir][loc[1]] == '1')
		return (free(loc), false);
	else if (game->chart->map[loc[0] + dir][loc[1]] == 'E')
	{
		game->chart->map[loc[0] + dir][loc[1]] = 'P';
		game->chart->map[loc[0]][loc[1]] = '0';
		game->out += 1;
	}
	else if (game->out == 0)
	{
		game->chart->map[loc[0] + dir][loc[1]] = 'P';
		game->chart->map[loc[0]][loc[1]] = '0';
	}		
	else if (game->out == 1)
	{
		game->chart->map[loc[0] + dir][loc[1]] = 'P';
		game->chart->map[loc[0]][loc[1]] = 'E';
		game->out -= 1;
	}
	game->chart->x += dir;
	return (free(loc), true);
}

bool	move_hor(t_gigastruct *game, int dir)
{
	size_t	*loc;

	loc = find_player(game->chart->map);
	if (game->chart->map[loc[0]][loc[1] + dir] == '1')
		return (free(loc), false);
	else if (game->chart->map[loc[0]][loc[1] + dir] == 'E')
	{
		game->chart->map[loc[0]][loc[1] + dir] = 'P';
		game->chart->map[loc[0]][loc[1]] = '0';
		game->out += 1;
	}
	else if (game->out == 0)
	{
		game->chart->map[loc[0]][loc[1] + dir] = 'P';
		game->chart->map[loc[0]][loc[1]] = '0';
	}		
	else if (game->out == 1)
	{
		game->chart->map[loc[0]][loc[1] + dir] = 'P';
		game->chart->map[loc[0]][loc[1]] = 'E';
		game->out -= 1;
	}
	game->chart->y += dir;
	return (free(loc), true);
}

void	so_keyhook(mlx_key_data_t keydata, void *param)
{	
	t_gigastruct	*game;

	game = (t_gigastruct *)param;
	if (!is_centered(game))
	{	
		move_some_more(game);
		if (is_centered(game))
			ft_printf("moves: %u\n", game->move++);
	}
	else if ((keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& keydata.key == MLX_KEY_UP)
		walkup(game, -1);
	else if ((keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& keydata.key == MLX_KEY_DOWN)
		walkdown(game, 1);
	else if ((keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& keydata.key == MLX_KEY_LEFT)
		walkleft(game, -1);
	else if ((keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& keydata.key == MLX_KEY_RIGHT)
		walkright(game, 1);
	if (keydata.key == MLX_KEY_ESCAPE)
		free_and_exit(game);
	if (exit_check(game))
		free_and_exit(game);
}

void	hookloop(t_gigastruct *game)
{
	game->move = 1;
	game->out = 0;
	mlx_key_hook(game->mlx, &so_keyhook, (void *)game);
	mlx_loop(game->mlx);
	free_and_exit(game);
}
