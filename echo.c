#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
int builtecho(char **args)
{
        int i;
        char *var;
        for(i=1;args[i]!=NULL;i++)
        {
                char *st=args[i];
                if(*(st + 0)=='$')
                        var=getenv(st+1);
                else
                        var=getenv(st);
                if(!var)
                        printf("%s",args[i]);
                else
                        printf("%s",var);
        }
        printf("\n");
        return 1;
}

