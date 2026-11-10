/*
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigusr1_data(int sig, siginfo_t *info, void *context){
    printf("Received SIGUSR1 from PID %d with value: %d\n", info->si_pid, info->si_value.sival_int);
}

int main(){
    struct sigaction sa;
    sa.sa_flag = SA_SIGINFO;
    sa.sa_flagaction = handle_sigusr1_data;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);

    printf("Received PID: %d. Waiting for signal with data...", getpid());

    while(1){
        pause();
    }
    return 0;
}