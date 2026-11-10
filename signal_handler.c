/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and returns without exiting
 */
/**
 * Modified by: Christian A. Montoya
 * Brief summary of modifications: Removed exit(1) from the signal handler so the process does not terminate upon receiving SIGINT.
 */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and returns
 */
void handle_signal(int signum) {
    printf("Received a signal\n");
}

int main() {
    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }
    return 0;
}