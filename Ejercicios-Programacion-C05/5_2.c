#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char**argv){
	pid_t pid,pid2;
   	int status;

        printf("********* Wait() para esperar el padre ***********\n");
   	pid = fork();
   	if (pid != 0){
     		printf("Soy el padre y terminé mi proceso\n");
  	} else {
    		pid2 = wait(&status);
    		printf("Soy el hijo y terminé mi proceso\n");
  	}
	sleep(2);
	return 0;
}

