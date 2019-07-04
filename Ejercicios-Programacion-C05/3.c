#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]){

	int rc = fork();

        if (rc < 0) {
        // fork failed
                fprintf(stderr, "fork failed\n");
                exit(1);
        } else if (rc == 0) {
        // child
                printf("Hello\n");

        } else {
        // parent goes down this path (main)
                sleep(1);
		printf("Goodbye\n");

        }







	return 0;
}
