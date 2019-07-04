#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);

char *builtin_str[] = {
	"cd",
	"help",
  	"exit"
};

int (*builtin_func[]) (char **) = {
	&lsh_cd,
	&lsh_help,
  	&lsh_exit
};

int lsh_num_builtins() {
	return sizeof(builtin_str) / sizeof(char *);
}

int lsh_cd(char **args){

	if (args[1] == NULL) {
    		fprintf(stderr, "lsh: expected argument to \"cd\"\n");
  	} else {
    		if (chdir(args[1]) != 0) {
      		perror("lsh");
    		}
  	}
  return 1;
}

int lsh_help(char **args)
{
  int i;
  printf("Escriba el nombre del programa y presione Enter\n");

  for (i = 0; i < lsh_num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Introduzca el comando man para conocer más acerca de los programas\n");
  return 1;
}

int lsh_exit(char **args)
{
  return 0;
}


char *lsh_read_line(void){ //Función que lee la linea

        char *line = NULL;
        ssize_t bufsize = 0; // Aloja esa linea en un Buffer
        getline(&line, &bufsize, stdin);

        return line;
}

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

char **lsh_split_line(char *line){ //Función que me separa la linea en argumentos

        int bufsize = LSH_TOK_BUFSIZE, position = 0;
        char **tokens = malloc(bufsize * sizeof(char*));
        char *token;

        if (!tokens){
                fprintf(stderr, "lsh: Error de alojamiento\n");
                exit(EXIT_FAILURE);
        }

        token = strtok(line, LSH_TOK_DELIM); //La delimitación entre comandos está dada por los espacios
        while (token != NULL) {
                tokens[position] = token;
                position++;

                if (position >= bufsize) {
                        bufsize += LSH_TOK_BUFSIZE;
                        tokens = realloc(tokens, bufsize * sizeof(char*));
                        if (!tokens) {
                                fprintf(stderr, "lsh: error de locación\n");
                                exit(EXIT_FAILURE);
                        }
                }

                token = strtok(NULL, LSH_TOK_DELIM);
        }

        tokens[position] = NULL;
        return tokens;
}

int lsh_execute(char **args){

	int i;

  	if (args[0] == NULL) {
    	    return 1;
  	}

	for (i = 0; i < lsh_num_builtins(); i++) {
    		if (strcmp(args[0], builtin_str[i]) == 0) {
      			return (*builtin_func[i])(args);
    		}
  	}

	return lsh_launch(args);
}

int lsh_launch(char **args) {

	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0){
		if (execvp(args[0], args) == -1) {
			perror("lsh");
		}
	exit (EXIT_FAILURE);
	} else if (pid < 0){
		perror("lsh");
	} else {
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return 1;
}

void lsh_loop(void){

	//Creo tres variables:

	//Una que lee la linea ingresada
        char *line;
	//Otra que la separa en argumentos
        char **args;
	//Una que ejecuta el loop dependiendo del estado que arroje una de las funciones de arriba
        int status;

        do {
                printf("$ ");
                line = lsh_read_line(); //Lee la linea y la guarda en esa variable
                args = lsh_split_line(line); //Separa la linea en argumentos
                status = lsh_execute(args); //Ejecuta el comando ingresado

                free(line);
                free(args);
        } while (status);
}


int main (int argc, char** argv){

// Ejecuto el loop

	lsh_loop();

	return EXIT_SUCCESS;
}
