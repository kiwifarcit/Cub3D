#include "../includes/cub3d.h"

void	put_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 64)
	{
		while(j < 64)
		{
			mlx_put_pixel(game->img, game->map->x * 64 + i + 1, game->map->y * 64 + j + 1, 0XFFFF00FF);
			j++;
		}
		i++;
		j = 0;
	}
}

void    player_pos(t_game   *game)
{
    game->map->y = 0;
    game->map->x = 0;
    game->player->y = 0;
    game->player->x = 0;

    while (game->map->y < game->map->y_size)
    {
        while (game->map->x < (int)ft_strlen(game->map->map[game->map->y]))
        {
			if (game->map->map[game->map->y][game->map->x] == '1')
				put_wall(game);
			if (game->map->map[game->map->y][game->map->x] == 'N')
			{
				game->player->y = game->map->y;
				game->player->x = game->map->x;
			}
			game->map->x++;
		}
		game->map->y++;
		game->map->x = 0;
	}
}

void	ft_hook(void* param)
{
	t_game	*game;

	game = param;
	// player_pos(game);
 	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			mlx_put_pixel(game->img, game->player->x * 64 + i, game->player->y * 64 + j, 0X00000000);
	
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		{
			game->player->x -= 0.1 * -cos(game->player->angle);
			game->player->y -= 0.1 * -sin(game->player->angle);
		}
		if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		{
			game->player->x += 0.1 * -cos(game->player->angle);
			game->player->y += 0.1 * -sin(game->player->angle);
		}
		if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		{
			game->player->x -= 0.1 * -sin(game->player->angle);
			game->player->y -= 0.1 * cos(game->player->angle);
		}
		if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		{
			game->player->x += 0.1 * -sin(game->player->angle);
			game->player->y += 0.1 * cos(game->player->angle);
		}
		if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		{
			// game->player->angle -= M_PI_2 / 16;
			// if (game->player->angle < 0)
			// 	game->player->angle = 2 * M_PI;
			game->player->angle += M_PI / 32;
			if (game->player->angle > 2 * M_PI)
				game->player->angle -= 2 * M_PI;
		}
		if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		{
			// game->player->angle += M_PI_2 / 6;
			// if (game->player->angle > 2 * M_PI)
			// 	game->player->angle = 0;
			game->player->angle -= M_PI / 32;
			if (game->player->angle < 0)
				game->player->angle += 2 * M_PI;
		}
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			mlx_put_pixel(game->img, game->player->x * 64 + i, game->player->y * 64 + j, 0XFF0000FF);
	mlx_image_to_window(game->mlx,game->img, 0,0);
}

void ft_window(t_game *game)
{
	game->mlx = mlx_init(game->map->x_size * 64, game->map->y_size * 64, "Cub3D", 1);
	game->img = mlx_new_image(game->mlx, game->map->x_size * 64, game->map->y_size * 64);
	game->player->angle = 1.5*M_PI;
	player_pos(game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}