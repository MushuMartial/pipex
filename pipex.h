/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:59:29 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/02 15:55:19 by tmartial         ###   ########.fr       */
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
char		**ft_split(char const *s, char c);

/* main */
void		pipex1(char *argv[], char *env[]);
void		exec1(char **env, t_data *data, t_paths *paths);
void		pipex2(char *argv[], char *env[], t_paths *paths, t_data *data);

/* utils */
int			path_init(t_paths *path, char *cmd);
char		*find_path(t_paths path);
void		free_path(t_paths *paths);
char		**find_cmd(char *argv[], int arg);
void		free_all(t_data	*data, t_paths *paths, int msg);

#endif