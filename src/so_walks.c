/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_walks.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 12:08:32 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/09 16:39:20 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./so_long.h"

void	disable_player(t_images *img)
{
	img->plf->instances[0].enabled = false;
	img->plfl->instances[0].enabled = false;
	img->plfr->instances[0].enabled = false;
	img->plb->instances[0].enabled = false;
	img->plbl->instances[0].enabled = false;
	img->plbr->instances[0].enabled = false;
	img->pll->instances[0].enabled = false;
	img->plwl->instances[0].enabled = false;
	img->plr->instances[0].enabled = false;
	img->plwr->instances[0].enabled = false;
}

void	walkup(t_gigastruct *game, int i)
{
	size_t	col;

	col = char_counter(game->chart->map, 'C');
	disable_player(game->img);
	game->img->plb->instances[0].enabled = true;
	if (move_vert(game, i))
	{	
		moving_vert(game, i);
		disable_player(game->img);
		game->img->plbl->instances[0].enabled = true;
	}
	if (col != char_counter(game->chart->map, 'C'))
		ft_printf("%u/%u collectables found!\n", game->chart->items
			- char_counter(game->chart->map, 'C'), game->chart->items);
}

void	walkdown(t_gigastruct *game, int i)
{
	size_t	col;

	col = char_counter(game->chart->map, 'C');
	disable_player(game->img);
	game->img->plf->instances[0].enabled = true;
	if (move_vert(game, i))
	{
		moving_vert(game, i);
		disable_player(game->img);
		game->img->plfr->instances[0].enabled = true;
	}
	if (col != char_counter(game->chart->map, 'C'))
		ft_printf("%u/%u collectables found!\n", game->chart->items
			- char_counter(game->chart->map, 'C'), game->chart->items);
}

void	walkleft(t_gigastruct *game, int i)
{
	size_t	col;

	col = char_counter(game->chart->map, 'C');
	disable_player(game->img);
	game->img->pll->instances[0].enabled = true;
	if (move_hor(game, i))
	{
		moving_hor(game, i);
		disable_player(game->img);
		game->img->plwl->instances[0].enabled = true;
	}
	if (col != char_counter(game->chart->map, 'C'))
		ft_printf("%u/%u collectables found!\n", game->chart->items
			- char_counter(game->chart->map, 'C'), game->chart->items);
}

void	walkright(t_gigastruct *game, int i)
{	
	size_t	col;

	col = char_counter(game->chart->map, 'C');
	disable_player(game->img);
	game->img->plr->instances[0].enabled = true;
	if (move_hor(game, i))
	{
		moving_hor(game, i);
		disable_player(game->img);
		game->img->plwr->instances[0].enabled = true;
	}
	if (col != char_counter(game->chart->map, 'C'))
		ft_printf("%u/%u collectables found!\n", game->chart->items
			- char_counter(game->chart->map, 'C'), game->chart->items);
}
