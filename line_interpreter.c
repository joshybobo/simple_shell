#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


#define MAX_COMMAND_LENGTH 1024
#define PROMPT "#cisfun$ "

void execute_command(const char *command)
{
	pid_t child_pid;

	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);

	}

	if (child_pid == 0)
	{

	if (execlp(command, command, (char *)NULL) == -1)
	{

	perror("exec");
	exit(EXIT_FAILURE);

	}
}
	else
	{

	do {
	waitpid(child_pid, &status, WUNTRACED);

	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}



	}
	int main(void)
{

	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
	printf("%s", PROMPT);

	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
	if (feof(stdin))
	(
	printf("\n"));
	exit(EXIT_SUCCESS);

	}
	else

	{

	perror("fgets");
	exit(EXIT_FAILURE);

	}

	}

	command[strcspn(command, "\n")] = '\0';

	if (strcmp(command, "exit") == 0)

	{
	exit(EXIT_SUCCESS);

	}

	return (0);




}
