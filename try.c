/*
void	exec (char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = str_split(cmd, ' ');
	if (str_ichr(args[0], '/') > -1)
		path = args[0];
	else
		path = getPath(args[0], env);
	execve(path, args, env);
	exit(127);
}

void	redir (char *cmd, char **env, int fdin)
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
			exec(cmd, env);
	}
}

int	main (int ac, char **av, char **env)
{
	int	fdin;
	int	fdout;

	if (ac == 5)
	{
		fdin = openfile(av[1], INFILE);
		fdout = openfile(av[4], OUTFILE);
		dup2(fdin, STDIN);
		dup2(fdout, STDOUT);
		redir(av[2], env, fdin);
		exec(av[3], env);
	}
	else
		write(STDERR, "Invalid number of arguments.\n", 29);
	return (1);
}*/