#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main (int argc, char *argv[]){

	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0){
		close(STDOUT_FILENO);
		printf("Cerrando el output standard\n");
	} else {
		printf("¿El padre imprime?\n");
	}


	return 0;
}
