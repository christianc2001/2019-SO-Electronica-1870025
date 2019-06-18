#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

	char car;
	int posCursor;
	FILE *file = fopen(argv[1],"r");

	fseek(file, 0, SEEK_END);
	posCursor = ftell(file);
	if (posCursor == 0)
		return 0;

	for (posCursor -= 1; posCursor >= 0; --posCursor){

		fseek(file,posCursor, SEEK_SET);
		car = fgetc(file);
		printf("%c",car);

	}

	return 0;

}
