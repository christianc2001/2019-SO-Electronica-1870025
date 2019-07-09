#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid = fork();
    if (pid == 0) 
    {
        char * const car1[] = {"ls", NULL};
        char * const car2[] = {NULL};
        //execl("/bin/ls", "ls", NULL);
        //execle("/bin/ls", "ls", NULL, car2);
        //execlp("ls", "ls", NULL);
        //execv("/bin/ls", car1);
        //execvp("ls", car1);
        //execvpe("ls", car1, car2);

        //se descomenta la linea que se desea usar
    }
    else if (pid > 0)
    {
        wait(NULL);
    }
}
