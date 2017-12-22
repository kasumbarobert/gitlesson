#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 #include <sys/types.h>
 #include <unistd.h>
#include <time.h>

int main(){
    pid_t pid = 0;
    pid_t sid = 0;
    pid =fork();
    FILE *fp=NULL;
    if(pid<0){
        printf("Fork failed \n");
        exit(1);
    }
    
    if(pid>0){
         printf("pid of the child process is %d \n",pid);
        exit(0);
    }
    umask(0);
    
    sid =setsid();
    
    if(sid < 0)
    {
        exit(1);
    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    fp =fopen("listerlogs.txt","w+");
    
    int counter =0;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    
    while(counter<20){
        tm = localtime(&t);
        strftime(s, sizeof(s), "%c", tm);
        sleep(10);
        fprintf(fp,"Counter : %d at %s\n",counter++,s);
    }
    
    fclose(fp);
    return(0);
    
}