/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:25:10 by tmartial          #+#    #+#             */
/*   Updated: 2021/12/15 15:46:17 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//path possibles PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki
//env[6] = path
#define STDIN  0
#define STDOUT  1
int main(int argc, char *argv[], char *env[])
{
	int fdin;
	int fdout;
	char **cmd1;
	char **cmd2;
	char *path_name;
	t_paths all_paths;
	
	if (argc == 5)
	{
		cmd1 = malloc(sizeof(char) * 2);
		cmd2 = malloc(sizeof(char) * 2);
		cmd1[0] = ft_strdup(argv[2]);
		cmd1[1] = 0;
		cmd2[0] = ft_strdup(argv[3]);
		cmd2[1] = 0;
	
		path_init(&all_paths, cmd1[0]);
		path_name = find_path(cmd1[0], all_paths);
		fdin = open(argv[1], O_RDONLY);
		fdout = open(argv[4], O_WRONLY, O_TRUNC);
		
		printf("hello");
		dup2(fdin, STDIN);
		dup2(fdout, STDOUT);
		redir(cmd1, env, fdin, path_name);
		
		path_init(&all_paths, cmd2[0]);
		path_name = find_path(cmd2[0], all_paths);
		if (execve(path_name, cmd2, env) == -1)
			perror("execve error");
	}
	else
		perror("Invalid args");
	return(0);
	
}

void	redir (char **cmd, char **env, int fdin, char *path_name)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT);
		if (fdin == STDIN)
			exit(1);
		else
		{
			if (execve(path_name, cmd, env) == -1)
				perror("execve error");
		}
	}
}

/* //if (execve(path_name, cmd1, env) == -1)
		//perror("execve error");
	
	//dup2(file2, 1);
	//dup2(file1, 0);
	//close(file1);
	// printf("%s\n",path_name);
	if (pipe(fd) == -1)
		return (1); //protection pipe
	int pid1 = fork();
	if (pid1 < 0)
		return (2); //protection fork
	
	if (pid1 == 0) //child process
	{
		if (execve("/bin/ls", &argv[2], env) == -1)
			perror("execve error");
	}
	
	waitpid(pid1, NULL, 0);*/