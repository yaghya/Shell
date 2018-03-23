#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
char **divide(char *comLINE)
{       
        int size=100,i=0;
        char *p;
        char **pp=malloc(sizeof(char*)*size);
        if(!pp)
        {
                fprintf(stderr,"allocation error\n");
                exit(EXIT_FAILURE);
        }
        p=strtok(comLINE," \t\r\a\n");
        //int a=1;
        while(p!=NULL)
        {
                pp[i]=p;
                i++;
                if(i>=size)
                {
                        size+=size;
                        pp=realloc(pp,sizeof(char)*size);

                        /* if(!pp)
                           {
                           fprintf(stderr,"allocation error\n");
                           exit(EXIT_FAILURE);
                           }*/
                }
                p=strtok(NULL," \t\r\a\n");
        }
        pp[i]=NULL;
	//pp[i+1]=NULL;
        //printf("done divide\n");
        return pp;

}

