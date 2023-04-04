/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_moved.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:15:17 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/09 11:42:14 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./so_long.h"

void	moving_vert2(t_gigastruct *game, int d)
{
	size_t	i;

	game->img->corl->instances[0].y -= 8 * d;
	game->img->corr->instances[0].y -= 8 * d;
	i = 0;
	while (i < strofstrlen(game->chart->map) - 1)
	{
		game->img->edgl->instances[i].y -= 8 * d;
		game->img->edgr->instances[i].y -= 8 * d;
		i++;
	}
	i = 0;
	while (i < strlen(game->chart->map[0]) - 1)
		game->img->edgt->instances[i++].y -= 8 * d;
	i = 0;
	while (i < strlen(game->chart->map[0]) + 1)
		game->img->edgb->instances[i++].y -= 8 * d;
	i = 0;
	while (i < (strofstrlen(game->chart->map) / 16 + 3)
		* (ft_strlen(game->chart->map[0]) / 16 + 3))
		game->img->outs->instances[i++].y -= 8 * d;
}

void	moving_vert(t_gigastruct *game, int d)
{
	size_t	i;

	i = 0;
	while (i < strofstrlen(game->chart->map)
		* ft_strlen(game->chart->map[0]))
		game->img->flr->instances[i++].y -= 8 * d;
	i = 0;
	while (i < game->chart->items)
	{
		game->img->itm->instances[i].y -= 8 * d;
		if (game->img->itm->instances[i].x == game->img->plf->instances[0].x
			&& game->img->itm->instances[i].y == game->img->plf->instances[0].y)
			game->img->itm->instances[i].enabled = false;
		i++;
	}
	i = 0;
	while (i < char_counter(game->chart->map, '1'))
		game->img->wll->instances[i++].y -= 8 * d;
	game->img->ldr->instances[0].y -= 8 * d;
	moving_vert2(game, d);
}

void	moving_hor2(t_gigastruct *game, int d)
{
	size_t	i;

	game->img->corl->instances[0].x -= 8 * d;
	game->img->corr->instances[0].x -= 8 * d;
	i = 0;
	while (i < strofstrlen(game->chart->map) - 2)
	{
		game->img->edgl->instances[i].x -= 8 * d;
		game->img->edgr->instances[i].x -= 8 * d;
		i++;
	}
	i = 0;
	while (i < strlen(game->chart->map[0]) - 1)
		game->img->edgt->instances[i++].x -= 8 * d;
	i = 0;
	while (i < strlen(game->chart->map[0]) + 1)
		game->img->edgb->instances[i++].x -= 8 * d;
	i = 0;
	while (i < (strofstrlen(game->chart->map) / 16 + 3)
		* (ft_strlen(game->chart->map[0]) / 16 + 3))
		game->img->outs->instances[i++].x -= 8 * d;
}

void	moving_hor(t_gigastruct *game, int d)
{
	size_t	i;

	i = 0;
	while (i < strofstrlen(game->chart->map)
		* ft_strlen(game->chart->map[0]))
		game->img->flr->instances[i++].x -= 8 * d;
	i = 0;
	while (i < game->chart->items)
	{
		game->img->itm->instances[i].x -= 8 * d;
		if (game->img->itm->instances[i].x == game->img->plf->instances[0].x
			&& game->img->itm->instances[i].y == game->img->plf->instances[0].y)
			game->img->itm->instances[i].enabled = false;
		i++;
	}
	i = 0;
	while (i < char_counter(game->chart->map, '1'))
		game->img->wll->instances[i++].x -= 8 * d;
	game->img->ldr->instances[0].x -= 8 * d;
	moving_hor2(game, d);
}
