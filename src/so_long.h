/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 13:29:35 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/09 16:54:39 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include"../libs/libft/libft.h"
# include"../libs/get_next_line/get_next_line.h"
# include"../libs/MLX42/include/MLX42/MLX42_Int.h"
# include<fcntl.h>
# include<math.h>

# define WIDTH 1024
# define HEIGHT 1024
# define SIZE 32

typedef struct s_images
{
	mlx_image_t	*itm;
	mlx_image_t	*wll;
	mlx_image_t	*ldr;
	mlx_image_t	*flr;
	mlx_image_t	*plf;
	mlx_image_t	*plb;
	mlx_image_t	*pll;
	mlx_image_t	*plr;
	mlx_image_t	*plwl;
	mlx_image_t	*plwr;
	mlx_image_t	*plbl;
	mlx_image_t	*plbr;
	mlx_image_t	*plfl;
	mlx_image_t	*plfr;
	mlx_image_t	*edgt;
	mlx_image_t	*edgb;
	mlx_image_t	*edgl;
	mlx_image_t	*edgr;
	mlx_image_t	*corl;
	mlx_image_t	*corr;
	mlx_image_t	*outs;
}	t_images;

typedef struct s_maps
{
	char	**map;
	size_t	x;
	size_t	y;
	size_t	items;
}	t_maps;

typedef struct s_gigastruct
{
	t_images		*img;
	t_maps			*chart;
	mlx_t			*mlx;
	unsigned int	move;
	int				out;
}	t_gigastruct;

// so_long.c
bool		extension_checker(char *str1, char *str2);
void		map_checker(int argc, char	*mapfile);
size_t		strofstrlen(char **chars);
void		flood_fill(char **map);
char		**flood_filler(char **map, size_t x, size_t y);
// so_maps.c
char		*trim_one(char *str1, char a);
char		**make_map_(char *mapfile, size_t height);
size_t		map_height(char *mapfile);
char		**make_map(char *mapfile);
void		rectangular_check(char *mapfile);
// so_parse.c
void		char_comp(char **map, char a, char b);
void		wall_check(char **map);
void		onlythese(char **map);
size_t		char_counter(char **map, char a);
void		map_check(char **map);
// so_hooks.c
void		so_keyhook(mlx_key_data_t keydata, void *param);
void		hookloop(t_gigastruct *game);
bool		move_vert(t_gigastruct *game, int dir);
bool		move_hor(t_gigastruct *game, int dir);
// so_moved.c
void		moving_vert(t_gigastruct *game, int i);
void		moving_vert2(t_gigastruct *game, int i);
void		moving_hor(t_gigastruct *game, int i);
void		moving_hor2(t_gigastruct *game, int i);
// so_more.c
void		move_some_more(t_gigastruct *game);
// so_walks.c
void		disable_player(t_images *img);
void		walkup(t_gigastruct *game, int i);
void		walkdown(t_gigastruct *game, int i);
void		walkleft(t_gigastruct *game, int i);
void		walkright(t_gigastruct *game, int i);
// so_images.c
void		draw_images(t_gigastruct *game, mlx_image_t *image,	char a);
void		draw_window(t_gigastruct *game);
t_images	*image_getter(t_gigastruct *game);
int32_t		initialize(char **map);
// so_tetures.c
mlx_image_t	*image_maker(char *png_file, mlx_t *mlx);
void		world_images(t_gigastruct *game, t_images *images);
void		player_images(t_gigastruct *game, t_images *images);
// so_utils.c
void		free_and_exit(t_gigastruct *game);
int32_t		calc(int32_t x, size_t y, size_t z);
void		error(char **str1, char *str2, char *str3);
size_t		*find_player(char **map);
bool		is_centered(t_gigastruct *game);
// void		print_map(char **map);
#endif