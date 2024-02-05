/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaplin <ktaplin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:41:12 by ktaplin           #+#    #+#             */
/*   Updated: 2023/03/15 19:01:27 by ktaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_extension_img(char *str, t_game *game)
{
	int	i;

	i = 0;
	if (game->argc != 2)
		error("Error wrong number of arguments", game);
	while (str[i])
		i++;
	if (str[i - 1] != 'g' || str[i - 2] != 'n' || str[i - 3] != 'p'
		|| str[i - 4] != '.')
		error("Error wrong extension for image file", game);
}

void	check_extension(char *str, t_game *game)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c'
		|| str[i - 4] != '.')
		error("Error wrong extension for map file", game);
}

void	before_check_img(t_game *game)
{
	if (game->free_n != 0)
		check_extension_img(game->map->path_n, game);
	if (game->free_s != 0)
		check_extension_img(game->map->path_s, game);
	if (game->free_e != 0)
		check_extension_img(game->map->path_e, game);
	if (game->free_w != 0)
		check_extension_img(game->map->path_w, game);
}

void	set_value(t_game *game)
{
	game->map->y_size = 0;
	game->map->x_size = 0;
	game->ceiling_r = -1;
	game->ceiling_g = -1;
	game->ceiling_b = -1;
	game->floor_r = -1;
	game->floor_g = -1;
	game->floor_b = -1;
	game->map->y = 0;
	game->map->x = 0;
	game->free = 0;
	game->free_n = 0;
	game->free_s = 0;
	game->free_e = 0;
	game->free_w = 0;
}

int	main(int argc, char	**argv)
{
	t_game	*game;
	int		i;

	game = malloc(sizeof(t_game));
	game->map = malloc (sizeof(t_map));
	game->player = malloc (sizeof(t_player));
	game->argv = argv;
	game->argc = argc;
	set_value(game);
	check_extension(argv[1], game);
	i = parsing(game);
	before_check_img(game);
	check_rgb(game);
	map(game, i);
	
	
	printf("NO = %s\n", game->map->path_n);
	printf("SO = %s\n", game->map->path_s);
	printf("EA = %s\n", game->map->path_e);
	printf("WE = %s\n", game->map->path_w);
	printf("C %d,%d,%d\n", game->ceiling_r, game->ceiling_g, game->ceiling_b);
	printf("F %d,%d,%d\n", game->floor_r, game->floor_g, game->floor_b);
	print_map(game);
	//player_pos(game);
	// printf("pos y = %d || x = %d\n", game->player->y, game->player->x);
	ft_window(game);



	free(game->map->path_n);
	free(game->map->path_s);
	free(game->map->path_e);
	free(game->map->path_w);
	freetab(game->map->map);
	free(game->map);
	free(game->player);
	free(game);
}
