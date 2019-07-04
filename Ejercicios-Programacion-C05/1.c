#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

	int x = 100;
	int rc = fork();

 	if (rc < 0) {
 	// fork failed
 		fprintf(stderr, "fork failed\n");
		exit(1);
 	} else if (rc == 0) {
 	// child
		printf("La variable x tiene el valor de: %d\n",x);
		x = 50;
		printf("Si la cambio en child x es: %d\n",x);
	} else {
 	// parent goes down this path (main)
		printf("La variable x tiene el valor de: %d\n",x);
		x = 1000;
		printf("Si la cambio en parent x es: %d\n",x);

	}

 	return 0;
}
