#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main (int argc, char *argv[]){

	char car;
	FILE *file = fopen("writing.txt", "wt");
	int rc = fork();

	if (rc < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0){
		fputs("Hola, soy el proceso child\n",file);
	} else {
		fputs("Hola, soy el proceso parent\n",file);
	}

	return 0;
}

