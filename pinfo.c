#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
int pinfo()
{
	FILE *fp;
		char buf1[256],buf2[256];
		int pid;
		char name[256],state;
		long unsigned int size;
		char * start;
		//if(argc==1)
		//{
			sprintf(buf1,"/proc/%d/stat",getpid());					//open the stat and exe files
			sprintf(buf2,"/proc/%d/exe",getpid());
		//}
		/*else
		{
			sprintf(buf1,"/proc/%s/stat",(args[1]));
			sprintf(buf2,"/proc/%s/exe",(args[1]));
}*/
		if((fp=fopen(buf1,"r"))!=NULL)
		{
			/*scan the stat file*/
			fscanf(fp,"%d %*s %c %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %lu %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d",&pid,&state,&size);												
			fclose(fp);									
			printf("pid -- %d\nProcess Status -- %c\nmemory -- %lu\n",pid,state,size);
			readlink(buf2,name,256);
			start=getcwd(NULL,0);
			if(strstr(name,start))
			{
				char fi[3]="~";
				strcat(fi,name+strlen(start));
				printf("Executable Path -- %s\n",fi);				//print print the stuff

			}
			else 
				printf("Executable Path -- %s\n",name);
		}
		else
perror("No such process");
return 1;
}
