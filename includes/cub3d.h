/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaplin <ktaplin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:41:12 by ktaplin           #+#    #+#             */
/*   Updated: 2023/03/15 19:01:27 by ktaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FAILURE
#  define FAILURE -1
# endif

# ifndef SUCESS
#  define SUCCESS 1
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>

typedef struct s_map
{
	int		x;
	int		y;
	int		x_size;
	int		y_size;
	char	**map;
	char	*path_n;
	char	*path_s;
	char	*path_e;
	char	*path_w;
	char	*path_f;
	char	*path_c;
}	t_map;

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;
}	t_player;

typedef struct s_game
{
	t_map		*map;
	t_player	*player;
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			argc;
	char		**argv;
	int			floor_r;
	int			floor_g;
	int			floor_b;
	int			ceiling_r;
	int			ceiling_g;
	int			ceiling_b;
	int			free;
	int			free_n;
	int			free_s;
	int			free_e;
	int			free_w;
	int			j_rgb;
}	t_game;

char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		parsing(t_game *game);
void	error(char *str, t_game *game);
int		north(char *str, int i, int n, t_game *game);
int		south(char *str, int i, int n, t_game *game);
int		east(char *str, int i, int n, t_game *game);
int		west(char *str, int i, int n, t_game *game);
int		ft_atoi(const char *str);
int		ceiling(char *str, int i, t_game *game, int n);
int		ft_floor(char *str, int i, t_game *game, int n);
int		ft_isdigit(char c);
void	set_color_c(char *number, int cpt, t_game *game);
void	set_color_f(char *number, int cpt, t_game *game);
void	check_rgb(t_game *game);
void	map(t_game *game, int i);
void	quick_check(t_game *game);
int		check_map_sides(t_game *game, char **map_tab);
void	*freetab(char **tab);
char	*ft_strcpy(char *src, char *dest, int i);
char	*ft_strdup(char *s1);
void	print_map(t_game *game);
int		line_empty(char *str);
int		check_fc(char *str, char cf, t_game *game);

void    player_pos(t_game   *game);
void	ft_window(t_game *game);

#endif