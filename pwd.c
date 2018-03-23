#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
int builtpwd(char **args)
{
        char *buf=malloc(sizeof(char)*1024);
        char *cwd;
        if((cwd=getcwd(buf,1024))!=NULL)
                printf("%s\n",cwd);
        else
                perror("Yaghya:");
        return 1;
}

