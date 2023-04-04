/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 16:45:14 by kposthum      #+#    #+#                 */
/*   Updated: 2023/03/09 11:06:10 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./so_long.h"

int	main(int argc, char **argv)
{
	char	**map;

	map_checker(argc, argv[1]);
	map = make_map(argv[1]);
	initialize(map);
	ft_free(map);
	return (0);
}
