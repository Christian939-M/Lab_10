/**
 * Author: Christian Montoya
 * Date: 11/14/2026
 * @file recv_signal.c
 * @brief Receives SIGUSR1 with an integer payload using sigaction.
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/**
 * @brief Signal handler that reads sival_int payload from siginfo_t
 */
void handle_sigusr1_data(int sig, siginfo_t *info, void *context) {
    printf("Received SIGUSR1 from PID %d with value: %d\n", 
           info->si_pid, info->si_value.sival_int);
}

int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_sigusr1_data;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);

    // Print startup message and force flush buffer
    printf("Receiver started. PID: %d. Waiting for signal...\n", getpid());
    fflush(stdout);

    while(1) {
        pause();
    }

    return 0;
}