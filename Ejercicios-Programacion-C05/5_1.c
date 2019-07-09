#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char**argv){
   pid_t pid,pid2;
   int status;
	printf("*********Wait() para esperar el hijo***********\n");
   pid = fork();
   if (pid != 0){
     pid2 = wait(&status);
     printf("soy el padre y termine mi proceso\n");
  } else{
    printf("soy el hijo y termine mi proceso\n");
  }
sleep(2);
return 0;
}
