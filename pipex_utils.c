/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:35:34 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/03 10:23:02 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	path_init(t_paths *path, char *cmd)
{
	path->path1 = ft_strjoin("/usr/local/bin/", cmd);
	path->path2 = ft_strjoin("/usr/bin/", cmd);
	path->path3 = ft_strjoin("/bin/", cmd);
	path->path4 = ft_strjoin("/usr/sbin/", cmd);
	path->path5 = ft_strjoin("/sbin/", cmd);
	path->path6 = ft_strjoin("/usr/local/munki/", cmd);
	if (!path->path1 || !path->path2 || !path->path3
		|| !path->path4 || !path->path5 || !path->path6)
		return (1);
	return (0);
}

char	*find_path(t_paths path)
{
	if (access(path.path1, F_OK) == 0)
		return (path.path1);
	if (access(path.path2, F_OK) == 0)
		return (path.path2);
	if (access(path.path3, F_OK) == 0)
		return (path.path3);
	if (access(path.path4, F_OK) == 0)
		return (path.path4);
	if (access(path.path5, F_OK) == 0)
		return (path.path5);
	if (access(path.path6, F_OK) == 0)
		return (path.path6);
	return (NULL);
}

char	**find_cmd(char *argv[], int arg)
{
	char	**cmd;

	cmd = ft_split(argv[arg], ' ');
	return (cmd);
}

void	free_path(t_paths *paths)
{
	free(paths->path1);
	free(paths->path2);
	free(paths->path4);
	free(paths->path5);
	free(paths->path6);
}

void	free_all(t_data	*data, t_paths *paths, int msg)
{
	int	i;

	i = -1;
	if (data->cmd[0] != NULL)
	{
		while (data->cmd[++i] != NULL)
			free(data->cmd[i]);
	}
	free(data->cmd);
	if (data->path_name)
		free(data->path_name);
	free_path(paths);
	if (msg != 0)
	{
		perror(strerror(msg));
		exit(127);
	}
	return ;
}
