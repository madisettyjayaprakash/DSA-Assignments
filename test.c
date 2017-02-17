#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define x 55##77
int main(){
char *a,*y;
y=(char*)malloc(3*sizeof(char));
a=(char*)malloc(3*sizeof(char));
printf("%u %u",a,y);	
scanf("%s",y);
strcpy(a,y);
printf("%s",a);


return 0;
}












/*
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
        int     fd[2], nbytes;
        pid_t   childpid;
        char    string[] = "Hello, world! hey by\n",string1[] = "hey by\n";
        char    readbuffer[80];

        pipe(fd);
        
        if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }

        if(childpid == 0)
        {
              
                close(fd[0]);

                
               
                write(fd[1], string1, (strlen(string1)+1));
                exit(0);
        }
        else
        {
               
                close(fd[1]);

               
                nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
                
                printf("Received string: %s", readbuffer);
        }
        
        return(0);
}



#include <stdio.h>
#include <unistd.h>
int main()
{
   int i,pid;
   printf("Enter the pid to know the details\n");
   scanf("%d",&pid);
   i=sysconf(_SC_CLK_TCK); //returns no of clock ticks per sec
   printf("No of clock ticks is %d per sec\n",i);
   i=syscall(326,pid);
   printf("System call returned %d\n",i);
   return 0;
}
 */
