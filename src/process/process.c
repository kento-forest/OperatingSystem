/* process.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = -42;
    int wstatus = -42;
    int ret = -1;

    pid = fork();
    switch(pid) {
        case -1:
            perror("fork");
            return EXIT_FAILURE;
        
        case 0:
            sleep(1);
            printf("Noooooooo!\n");
            exit(0);
        
        default:
            printf("Iamyourfather\n");
            break;
    }
    ret = waitpid(pid, &wstatus, 0);
    if (ret == -1) {
        perror("waitpid");
        return EXIT_FAILURE;
    }
    printf("Childexitstatus : %d\n", WEXITSTATUS(wstatus));

    return EXIT_SUCCESS;
}
