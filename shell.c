#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include"prin.h"
#include"echo.h"
#include"execfork.h"
#include"pwd.h"
#include"divide.h"
#include"pinfo.h"
int builtcd(char **args);
int builtexit(char **args);
char *built[]={"cd","pwd","hello","exit","pinfo"};
int (*func[]) (char ** args)={&builtcd,&builtpwd,&builtecho,&builtexit,&pinfo};
char printarr[200];
char first[200];
char home[200];
int builtcd(char **args)
{
	if(args[1]==NULL||(strcmp(args[1],"~")==0))
	{		strcpy(printarr,first);
		chdir(home);
	}
	else
	{
		if(chdir(args[1])==0)
		{	
			if(strcmp(args[1],"..")==0)
			{
				char copy[200];
				int size=100,i=0;
				char *p;
				char **pp=malloc(sizeof(char*)*size);
				p=strtok(printarr,"/");
				while(p!=NULL)
				{
					pp[i]=p;
					p=strtok(NULL,"/");
					i++;
				}
				pp[i]=NULL;
				int j;
				int l;
				p=pp[0];
				strcpy(copy,p);
				l=strlen(copy);
				copy[l]='/';
				for(j=l+1;j<100;j++)
					copy[j]='\0';
				for(j=1;j<i-2;j++)
				{
					p=pp[j];
					strcat(copy,p);
					l=strlen(copy);
					copy[l]='/';
					copy[l+1]='\0';
			//		prin(copy);
				}
				//	copy[l+1]='>';
				strcat(copy,pp[i-1]);
				strcpy(printarr,copy);
				free(pp);
			}
			else
			{
				char *buf=malloc(sizeof(char)*1024);
				char *cwd;
				cwd=getcwd(buf,1024);	
				int size=100,i=0,flag=0;
				char *p;
				char **pp=malloc(sizeof(char*)*size);
				p=strtok(cwd,"/");
				int l;
				l=strlen(printarr);
				printarr[l-1]='\0';
				while(p!=NULL)
				{
					if(flag==1)
					{	
						pp[i]=p;
				strcat(printarr,pp[i]);
				l=strlen(printarr);
				printarr[l]='/';
						i++;
						//		int l;
					}
					if(strcmp(p,"201502203_Assignment2")==0)
						flag=1;
					p=strtok(NULL,"/");
					//prin(printarr);
				}
				pp[i]=NULL;
				printarr[l+1]='>';
				free(buf);
				free(pp);
			}
		}
		else
			perror("sh:");
	}
	return 1;
}
int builtexit(char **args)
{
	return 0;
}
int execute(char **args)
{
	if(args[0]==NULL)
		return 1;
	int i;
	for(i=0;i<5;i++)
	{
		if(strcmp(args[0],built[i])==0)
			return (*func[i])(args);
	}
	execfork(args);
	return 1;
}
int  readcomm()
{
	int size=100,i=0;
	char *buf=malloc(sizeof(char)*size);
	char **args;
	int k=1;
	while(1)
	{
		int c;
		c=getchar();
		if(c=='\n' ||EOF==c)
		{
			buf[i]='\0';
			args=divide(buf);
			k=execute(args);
			char *buf=malloc(sizeof(char)*size);
			if(k==0)
				return 0;
			else
				return 1;
		}
		else
		{	
			if(c==';')
			{ 
				buf[i]='\0';
				args=divide(buf);
				k=execute(args);
				char *buf=malloc(sizeof(char)*size);
				i=0;
				if(k==0)
					return 0;
				else
					continue;
			}
			else
				buf[i]=c;
		}
		i++;
		if(i>=size)
		{
			size+=size;
			buf=realloc(buf,size);
			if(!buf)
			{
				fprintf(stderr,"allocation error\n");
				exit(EXIT_FAILURE);
			}


		}
	}
	return 1;
}
int main(int argc, char * argv[])
{
	strcpy(printarr,"<Yaghyaa@UBUNNTU:~/>");
	strcpy(first,"<Yaghyaa@UBUNNTU:~/>");
	char *buf=malloc(sizeof(char)*1024);
	char *cwd;
	cwd=getcwd(buf,1024);	
	strcpy(home,cwd);
	while(1)
	{
		prin(printarr);
		int k=1;
		k=readcomm();
		if(k==0)
			break;
	}
	return 0;
}

