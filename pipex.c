/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:25:10 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/03 10:20:50 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	if (argc == 5)
		pipex1(argv, env);
	else
		perror(strerror(22));
	return (0);
}

void	pipex1(char *argv[], char *env[])
{
	t_data	data;
	t_paths	paths;

	data.cmd = find_cmd(argv, 2);
	if (path_init(&paths, data.cmd[0]) == 1)
		free_all(&data, &paths, 12);
	data.path_name = find_path(paths);
	if (data.path_name == NULL)
		free_all(&data, &paths, 22);
	data.file = open(argv[1], O_RDONLY);
	if (access(argv[1], F_OK) != 0)
		free_all(&data, &paths, 2);
	dup2(data.file, STDIN_FILENO);
	exec1(env, &data, &paths);
	pipex2(argv, env, &paths, &data);
}

void	pipex2(char *argv[], char *env[], t_paths *paths, t_data *data)
{
	free_all(data, paths, 0);
	data->cmd = find_cmd(argv, 3);
	if (path_init(paths, data->cmd[0]) == 1)
		free_all(data, paths, 12);
	data->path_name = find_path(*paths);
	if (data->path_name == NULL)
		free_all(data, paths, 22);
	data->file = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (access(argv[1], F_OK) != 0)
		free_all(data, paths, 2);
	dup2(data->file, STDOUT_FILENO);
	execve(data->path_name, data->cmd, env);
	free_all(data, paths, 8);
}

void	exec1(char **env, t_data *data, t_paths *paths)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		if (data->file == 0)
			free_all(data, paths, 12);
		else
		{
			execve(data->path_name, data->cmd, env);
			free_all(data, paths, 8);
		}
	}
}
