/*
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigusr1(int sig, siginfo_t *info, void *context){
    printf("Received SIGUSR1 from process ID: %d\n", info->si_pid);
}

int main(){
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_sigusr1;
    sigemptyset(&sa.sa_mask);


    sigaction(SIGUSR1, &sa, NULL);

    printf("My PID is %d. Waiting for SIGUSR1...\n", getpid());

    while (1){
        pause();
    }
    return 0;
}