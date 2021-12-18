/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:59:29 by tmartial          #+#    #+#             */
/*   Updated: 2021/12/18 17:31:43 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_paths {
	char	*path1;
	char	*path2;
	char	*path3;
	char	*path4;
	char	*path5;
	char	*path6;
}	t_paths;

typedef struct s_data {
	int		file;
	char	**cmd;
	char	*path_name;
}	t_data;

/* libft */
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);

/* split */
//static int	tab_len(char const *s, char c);
//static int	mal_len(char const *s, char c, int pos);
//static int	ft_free_all(char **split, int i); //free tableau de char
//static int	ad_pos(const char *s, int pos, char c);
char		**ft_split(char const *s, char c);

/* main */
int			pipex1(char *argv[], char *env[]);
void		exec1(char **env, t_data data);
char		**find_cmd(char *argv[], int arg);
int			pipex2(char *argv[], char *env[], t_paths *paths, t_data *data);

/* utils */
int			path_init(t_paths *path, char *cmd);
char		*find_path(t_paths path);

#endif