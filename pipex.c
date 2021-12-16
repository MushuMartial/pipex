/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:25:10 by tmartial          #+#    #+#             */
/*   Updated: 2021/12/16 13:03:11 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//path PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki

int	main(int argc, char *argv[], char *env[])
{
	if (argc == 5)
		pipex(argv, env);
	else
		perror("Invalid args");
	return (0);
}

char	**find_cmd(char *argv[], int arg)
{
	char	**cmd;

	cmd = ft_split(argv[arg], ' ');
	return (cmd);
}

int	pipex(char *argv[], char *env[])
{
	int		file1;
	int		file2;
	char	**cmd;
	char	*path_name;
	t_paths	all_paths;

	cmd = find_cmd(argv, 2);
	if (cmd == NULL)
		perror("malloc error");
	if (path_init(&all_paths, cmd[0]) == 1)
		perror("malloc error");
	path_name = find_path(all_paths);
	if (path_name == NULL)
		perror("cmd doesnt exist");
	file1 = open(argv[1], O_RDONLY);
	if (access(argv[1], F_OK) != 0)
		perror("file doesnt exist");
	file2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	dup2(file1, STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	exec1(cmd, env, file1, path_name);
	cmd = find_cmd(argv, 3);
	path_init(&all_paths, cmd[0]);
	path_name = find_path(all_paths);
	if (execve(path_name, cmd, env) == -1)
		perror("execve error");
	return (0);
}

void	exec1(char **cmd, char **env, int file, char *path_name)
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
		if (file == 0)
			exit(1);
		else
		{
			if (execve(path_name, cmd, env) == -1)
				perror("execve error");
		}
	}
}
