/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:25:10 by tmartial          #+#    #+#             */
/*   Updated: 2021/12/28 13:41:13 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//path PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki
//2 = No such file or directory; 10 = No child processes; 
//12 = Cannot allocate memory; 22 = Invalid argument;
//32 = Broken pipe; 8 = Exec format error
int	main(int argc, char *argv[], char *env[])
{
	if (argc == 5)
		pipex1(argv, env);
	else
		perror(strerror(22));
	system("leaks pipex");
	return (0);
}

void	free_path(t_paths *paths)
{
	free(paths->path1);
	free(paths->path2);
	write(1,"g\n",2);
	//free(paths->path3);
	write(1,"g\n",2);
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
	if (msg != 0)
		free(data->cmd);
	if (data->path_name)
		free(data->path_name);
	free_path(paths);
	if (msg != 0)
	{
		perror(strerror(msg));
		//exit(0);
	}
	return;
}

char	**find_cmd(char *argv[], int arg)
{
	char	**cmd;

	cmd = ft_split(argv[arg], ' ');
	return (cmd);
}

int	pipex1(char *argv[], char *env[])
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
	{	
		free_all(&data, &paths, 37);
		printf("hdfhdfhfdh\n");
		return (0);
	}
	dup2(data.file, STDIN_FILENO);
	exec1(env, &data, &paths);
	//free_all(&data, &paths, 12);
	pipex2(argv, env, &paths, &data);
	return (0);
}

int	pipex2(char *argv[], char *env[], t_paths *paths, t_data *data)
{
	data->file = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	dup2(data->file, STDOUT_FILENO);
	data->cmd = find_cmd(argv, 3);
	path_init(paths, data->cmd[0]);
	data->path_name = find_path(*paths);
	if (execve(data->path_name, data->cmd, env) == -1)
		free_all(data, paths, 8);
	return (0);
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
			if (execve(data->path_name, data->cmd, env) == -1)
				free_all(data, paths, 8);
		}
	}
}
