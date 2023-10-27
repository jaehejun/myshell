#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

void handle_EOF(int sig)
{
	(void)sig;
    if (rl_end == 0) {  // If line is empty
        printf("\nexit\n");
        exit(0);
	}
}

int main(void)
{
    char *input;
    char prompt[] = "bash$ ";

    // Set up signal handler for EOF (Ctrl+D)
    signal(SIGQUIT, handle_EOF);

    while(1) {
        input = readline(prompt);

        if(input != NULL) {
            add_history(input);
            free(input);
        }
    }

    return 0;
}
