/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_textures.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 13:07:05 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/09 11:05:59 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./so_long.h"

mlx_image_t	*image_maker(char *png_file, mlx_t *mlx)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(png_file);
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

void	world_images(t_gigastruct *game, t_images *images)
{
	images->itm = image_maker("./textures/Collectable.png", game->mlx);
	images->wll = image_maker("./textures/Wall.png", game->mlx);
	images->ldr = image_maker("./textures/Exit.png", game->mlx);
	images->flr = image_maker("./textures/Background.png", game->mlx);
	images->edgt = image_maker("./textures/Edge_top.png", game->mlx);
	images->edgb = image_maker("./textures/Edge_bottom.png", game->mlx);
	images->edgl = image_maker("./textures/Edge_left.png", game->mlx);
	images->edgr = image_maker("./textures/Edge_right.png", game->mlx);
	images->corl = image_maker("./textures/Edge_topleft.png", game->mlx);
	images->corr = image_maker("./textures/Edge_topright.png", game->mlx);
	images->outs = image_maker("./textures/Outside.png", game->mlx);
}

void	player_images(t_gigastruct *game, t_images *images)
{
	images->plf = image_maker("./textures/Player_front.png", game->mlx);
	images->plfl = image_maker("./textures/Player_front_left.png", game->mlx);
	images->plfr = image_maker("./textures/Player_front_right.png", game->mlx);
	images->plb = image_maker("./textures/Player_back.png", game->mlx);
	images->plbl = image_maker("./textures/Player_back_left.png", game->mlx);
	images->plbr = image_maker("./textures/Player_back_right.png", game->mlx);
	images->pll = image_maker("./textures/Player_left.png", game->mlx);
	images->plwl = image_maker("./textures/Player_walk_left.png", game->mlx);
	images->plr = image_maker("./textures/Player_right.png", game->mlx);
	images->plwr = image_maker("./textures/Player_walk_right.png", game->mlx);
}

t_images	*image_getter(t_gigastruct *game)
{	
	t_images	*images;

	images = (t_images *)ft_calloc(sizeof(t_images), 1);
	if (!images)
		return (ft_free(game->chart->map), free(game->chart),
			mlx_terminate(game->mlx), free(game), exit(-1), NULL);
	world_images(game, images);
	player_images(game, images);
	return (images);
}
