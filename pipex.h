/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:59:29 by tmartial          #+#    #+#             */
/*   Updated: 2021/12/14 13:38:04 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
typedef struct s_paths {
	char *path1;
	char *path2; 
	char *path3;
	char *path4; 
	char *path5; 
	char *path6;
}	t_paths;

/* libft */
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void path_init(t_paths *path, char *cmd);


#endif