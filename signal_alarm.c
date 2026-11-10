/*
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_alarm(int signum){
    printf("SIGALRM received! The 5 second alarm went off\n");
    exit(0);
}
int main(){
    signal(SIGALRM, handle_alarm);
    
    alarm(5);

    printf("Alarm set for 5 seconds. Waiting ...\n");

    while(1){
        sleep(1);
    }
    return 0;
}