#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
void execfork(char **args)
{
	pid_t p;
	p=fork();
	int status;
	int i=0;
	int d;
	while(args[i]!=NULL)
	{
		d=i;
		i=i+1;
	}
	int back;
	back=0;
	if(strcmp(args[d],"&")==0)
	{
		back=1;
	}
	if(strcmp(args[d],"&")==0) {
		args[d]=NULL;
		if(p == -1) {
			perror("fork");
			exit(1);
		}
		else if(p == 0) {
			execvp(args[0], args);
		}
		else 
		{
			while((p = waitpid(-1, &status, WNOHANG)) > 0) {
				printf("[proc %d exited with code %d]\n",
						p, WEXITSTATUS(status));
			}       
		}
	}
	else
	{
		if (p == 0) {
			if (execvp(args[0], args) == -1) {
				perror("lsh");
			}
			exit(EXIT_FAILURE);
		} else if (p < 0) {
			perror("yaghya");
		} else {
			while((p = waitpid(-1, &status, WNOHANG)) > 0) {
				printf("[proc %d exited with code %d]\n",
						p, WEXITSTATUS(status));
			}       
			do {
				waitpid(p, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	return ;
}

