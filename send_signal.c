/**
 * Author: Christian Montoya
 * Date: 11/14/2026
 * @file send_signal.c
 * @brief Sends a random integer along with SIGUSR1 using sigqueue.
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <target_pid>\n", argv[0]);
        return 1;
    }

    pid_t target_pid = atoi(argv[1]);

    srand(time(NULL));
    int rand_num = rand() % 100; // Random number between 0 and 99

    union sigval value;
    value.sival_int = rand_num;

    printf("Sending SIGUSR1 to PID %d with random value: %d\n", target_pid, rand_num);

    if (sigqueue(target_pid, SIGUSR1, value) == -1) {
        perror("sigqueue failed");
        return 1;
    }

    return 0;
}