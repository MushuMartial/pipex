/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:35:34 by tmartial          #+#    #+#             */
/*   Updated: 2021/12/15 10:36:28 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void path_init(t_paths *path, char *cmd)
{
	path->path1 = ft_strjoin("/usr/local/bin/", cmd);
	path->path2 = ft_strjoin("/usr/bin/", cmd);
	path->path3 = ft_strjoin("/bin/", cmd);
	path->path4 = ft_strjoin("/usr/sbin/", cmd);
	path->path5 = ft_strjoin("/sbin/", cmd);
	path->path6 = ft_strjoin("/usr/local/munki/", cmd);
}

char *find_path(char *cmd, t_paths path)
{
	if (access(path.path1, F_OK) == 0)
		return(path.path1);
	if (access(path.path2, F_OK) == 0)
		return(path.path2);
	if (access(path.path3, F_OK) == 0)
		return(path.path3);
	if (access(path.path4, F_OK) == 0)
		return(path.path4);
	if (access(path.path5, F_OK) == 0)
		return(path.path5);
	if (access(path.path6, F_OK) == 0)
		return(path.path6);
	return(NULL);
}