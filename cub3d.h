/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <sroggens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:04:47 by sroggens          #+#    #+#             */
/*   Updated: 2023/06/18 00:47:28 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <signal.h>
# include <stddef.h>
# include <termios.h>
# include <sys/ioctl.h>

typedef struct s_parsing
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
	int		fd;
	int		erroronthemap;
	int		atoitest;
	char	**tab;
	char	**namecheck;
	int		count;
	char	*maptmp;
	char	**tabmaptmp;
	char	**tmp;
	char	**tmpcheck;
	char	**colorcheck;
	char	*notab;
	char	*sotab;
	char	*wetab;
	char	*eatab;
	char	*ftab;
	char	*ctab;
}			t_parsing;

typedef struct s_txt
{
	void	*no;
	void	*so;
	void	*ea;
	void	*we;
	int		*a_no;
	int		*a_so;
	int		*a_ea;
	int		*a_we;
	int		*a_fnl;
	int		img_w;
	int		img_h;
	int		bpp_2;
	int		len;
	int		end;
	int		txt_x;
	int		txt_y;
}	t_txt;

typedef struct s_rgb
{
	double	floor_r;
	double	floor_g;
	double	floor_b;
	double	ceil_r;
	double	ceil_g;
	double	ceil_b;
}				t_rgb;

typedef struct s_game
{
	t_parsing	parsing;
	t_txt		txt;
	t_rgb		rgb;
	char		player;
	char		**map;
}				t_game;

//===================GNL=====================
//[			**get_next_line_utils.c		    ]
//===========================================
int		ft_strlen(const char *str);
char	*strdupgnl(char *buffer);
int		comparegnl(char *box);
char	*strjoingnl(char *box, char *buffer);
//===================GNL=====================
//[			**get_next_line.c		    	]
//===========================================
char	*writeligne(char *box);
char	*newbox(char *box);
char	*gnlbis(int fd, char *box);
char	*get_next_line(int fd);
//===================Utils===================
//[				**ft_atoi.c         	   	]
//===========================================
int		ft_atoi(const char *str);
//===================Utils===================
//[				**ft_isdigit.c       	   	]
//===========================================
int		ft_isdigit(int c);
//===================Utils===================
//[				**ft_split.c	    	   	]
//===========================================
char	**ft_split(char *s, char c);
//===================Utils===================
//[				**ft_putstr_fd.c	    	]
//===========================================
void	ft_putstr_fd(char *s, int fd);
//===================Utils===================
//[				**ft_strcmp.c	    	   	]
//===========================================
int		ft_strcmp(const char *s1, const char *s2);
//===================Utils===================
//[				**ft_strdup.c	    	   	]
//===========================================
char	*ft_strdup(const char *src);
char	*ft_strdupwen(const char *src);
//===================Utils===================
//[				**ft_strjoin.c	    	   	]
//===========================================
char	*ft_strjoin(char *s1, char *s2);
//===================Utils===================
//[				**ft_colorcheck.c      	   	]
//===========================================
int		colorcheck(char *str);
//===================Error===================
//[				**errormess.c	     	   	]
//===========================================
int		errormess(int nb);
//===================Error===================
//[				**errormessmap.c	     	]
//===========================================
int		errormessmap(int nb, t_game *game);
//===================Parsing=================
//[				**setarg.c	     	   		]
//===========================================
int		addvaluetorighttab(char **str, t_game *game);
int		checkandfillrgbvalue(char *str, t_game *game, char s);
int		setvalueforcolorbis(t_game *game, char s, int i);
void	freetabcf(t_game *game, char s);
//===================Parsing=================
//[				**setargbis.c	     	   	]
//===========================================
int		checkparsing(char **av, int ac, t_game *game);
int		takethefile(char **av, t_game *game);
int		takethefilebis(t_game *game, char **av);
int		prepbeforemap(t_game *game);
int		setvaluepremap(t_game *game);
//===================Parsing=================
//[				**setargbistwo.c	     	]
//===========================================
int		checkifitexist(char *str);
int		addeano(char **str, t_game *game, int fd);
int		addsowe(char **str, t_game *game, int fd);
int		addfc(char **str, t_game *game);
void	setgamevalue(t_game *game);
//===================Parsing=================
//[				**mapprep.c	     			]
//===========================================
int		prepamap(t_game *game);
int		checkerforforbidden(char c, t_game *game);
int		checkforbiddencharonmap(t_game *game);
int		checkifclose(t_game *game, int i, int j);
//===================Parsing=================
//[				**namecheck.c     	   		]
//===========================================
int		namecheck(char **av, t_game *game);
int		freenamecheck(t_game *game);
#endif
