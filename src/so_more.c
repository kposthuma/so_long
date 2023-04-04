/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_more.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 13:20:28 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/09 11:28:33 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./so_long.h"

void	and_even_more(t_gigastruct *game)
{
	if (game->img->plwl->instances[0].enabled == true)
	{
		moving_hor(game, -1);
		disable_player(game->img);
		game->img->pll->instances[0].enabled = true;
	}
	else if (game->img->pll->instances[0].enabled == true)
	{
		moving_hor(game, -1);
		disable_player(game->img);
		game->img->plwl->instances[0].enabled = true;
	}
	else if (game->img->plwr->instances[0].enabled == true)
	{
		moving_hor(game, 1);
		disable_player(game->img);
		game->img->plr->instances[0].enabled = true;
	}
	else if (game->img->plr->instances[0].enabled == true)
	{
		moving_hor(game, 1);
		disable_player(game->img);
		game->img->plwr->instances[0].enabled = true;
	}
}

void	and_some_more(t_gigastruct *game)
{
	if (game->img->plfr->instances[0].enabled == true)
	{
		moving_vert(game, 1);
		disable_player(game->img);
		game->img->plf->instances[0].enabled = true;
	}
	else if (game->img->plf->instances[0].enabled == true)
	{
		moving_vert(game, 1);
		disable_player(game->img);
		game->img->plfl->instances[0].enabled = true;
	}
	else if (game->img->plfl->instances[0].enabled == true)
	{
		moving_vert(game, 1);
		disable_player(game->img);
		game->img->plf->instances[0].enabled = true;
	}
	else
		and_even_more(game);
}

void	move_some_more(t_gigastruct *game)
{
	if (game->img->plbl->instances[0].enabled == true)
	{
		moving_vert(game, -1);
		disable_player(game->img);
		game->img->plb->instances[0].enabled = true;
	}
	else if (game->img->plb->instances[0].enabled == true)
	{		
		moving_vert(game, -1);
		disable_player(game->img);
		game->img->plbr->instances[0].enabled = true;
	}
	else if (game->img->plbr->instances[0].enabled == true)
	{
		moving_vert(game, -1);
		disable_player(game->img);
		game->img->plb->instances[0].enabled = true;
	}
	else
		and_some_more(game);
}
