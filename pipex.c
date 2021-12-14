/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:25:10 by tmartial          #+#    #+#             */
/*   Updated: 2021/12/14 14:07:13 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//path possibles PATH=/usr/local/bin:/usr/bin:/usr/bin:/usr/sbin:/sbin:/usr/local/munki
//env[6] = path

int main(int argc, char *argv[], char *env[])
{
	int file1;
	int file2;
	int fd[2];
	char *cmd1 = ft_strdup(argv[2]);
	char *cmd2 = ft_strdup(argv[3]);
	t_paths path;
	
	char *cmd = malloc(sizeof(char) * 3);
	cmd[0] = 'l';
	cmd[1] = 's';
	cmd[2] = '\0'; 
	path_init(&path, cmd1);
	//file1 = open("a.txt", O_RDONLY);
	//file2 = open("b.txt", O_RDONLY);
	

	if (execve("/bin/ls", &cmd, env) == -1)
		perror("execve error");
	/*if (pipe(fd) == -1)
		return (1); //protection pipe
	int pid1 = fork();
	if (pid1 < 0)
		return (2); //protection fork*/
	
	/*if (pid1 == 0) //child process
	{
		if (execve("/bin/ls", &argv[2], env) == -1)
			perror("execve error");
	}*/
	
	//waitpid(pid1, NULL, 0);
	/*if (argc == 5)
	{
		if (execve(argv[2], &cmd1, env) == -1)
			perror("execve error");
	}
	else
		perror("invalid args");*/
	return (0);
}

/*char *find_path()
{

}*/

/*int main(int argc, char *argv[], char *env[])
{
  pid_t         pid;
  int           fd[2];

  if (argc < 2)
    return 1;

  if (pipe(fd) == -1)
    {
      perror("pipe");
      return 1;
    }

  if ((pid = fork()) == -1)
    {
      perror("fork");
      return 1;
    }
  else if (pid == 0)
    {
      close(pipe_fd[0]);
      if (dup2(pipe_fd[1], 1) == -1)
      perror("dup2");
      else if (execve(argv[1], argv + 1, env) == -1)
      perror("execve");
      return 1;
    }
  else
    {
      char      buffer[1024];
      int       ret;
      int       status;

      close(pipe_fd[1]);

      while ((ret = read(pipe_fd[0], buffer, 1023)) != 0)
      {
        printf("%d\n", ret);
        buffer[ret] = 0;
        printf("%s\n", buffer);
      }
    }

  return 0;
}*/
/*int main(void)
{
  pid_t          pid;

  pid = fork();
  if (pid == -1) //fork rate
    {
      perror("fork");
      return 1;
    }
  else if (pid == 0) //ds fork
    printf("Je suis le fils, et mon pid = %d\n", getpid());
  else //pas ds fork
    printf("Je suis le pere, et mon pid = %d. Le pid de mon fils = %d\n", getpid(), pid);

  printf("pid = %d\n", pid);
  return 0;
} */