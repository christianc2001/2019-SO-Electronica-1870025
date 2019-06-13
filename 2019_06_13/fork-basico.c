#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char** argv){
	pid_t pid;
	printf("Hola\n");
	pid = fork();
	printf("Hola a todos\n");
	if (pid != 0){
		printf("Soy el padre, mi id es %d y el de mi hijo es %d\n",getpid(),pid);
	} else {
		printf("Soy el hijo, mi id %d y mi variable pid es %d\n",getpid(),pid);
	}




	return 0;
}
