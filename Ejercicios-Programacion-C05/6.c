#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char**argv){
	pid_t pid,pid2;
   	int status;

        printf("********* Waitpid() para esperar el hijo ***********\n");
   	pid = fork();
   	if (pid != 0){
     		pid2 = waitpid(pid,&status,0);
     		printf("Soy el padre y terminé mi proceso\n");
  	} else {
    		printf("Soy el hijo y terminé mi proceso\n");
  	}
	sleep(2);
	return 0;
}

