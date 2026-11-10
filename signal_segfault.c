/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault and catches it with a signal handler
 */
/**
 * Modified by: Christian A. Montoya
 * Brief summary of modifications: Added a SIGSEGV signal handler to catch the segmentation fault caused by dereferencing a NULL pointer and print a receipt message.
 */
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

/**
 * @brief Signal handler for SIGSEGV - prints a message when a segmentation fault occurs
 */
void handle_segfault(int signum) {
    printf("Segmentation fault received!\n");
    // Note: If we just return here, execution loops back to the faulting instruction.
    // To prevent an infinite loop, we can exit explicitly:
    exit(1);
}

int main (int argc, char* argv[]) {
    // Register the signal handler for SIGSEGV
    signal(SIGSEGV, handle_segfault);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer (triggers SIGSEGV)
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}