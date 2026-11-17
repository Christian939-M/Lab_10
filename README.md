# Lab 10: Signals - CPE-2600

Author: Christian A. Montoya  
Course: CPE-2600: Systems Programming (Fall 2026)  

---

## Overview
This repository contains programs exploring POSIX signals for inter-process communication, custom signal handlers, alarms, segmentation fault handling, and sending data with signals using `sigaction` and `sigqueue`.

## Programs Included
signal_handler.c - Registers a custom handler for `SIGINT` to catch `Ctrl+C` and print a message instead of terminating.
signal_alarm.c - Uses the `alarm()` system call to schedule a 5-second timer and handle `SIGALRM`.
signal_segfault.c - Demonstrates catching `SIGSEGV` caused by dereferencing a `NULL` pointer.
signal_sigaction.c - Uses `sigaction` with `SA_SIGINFO` to capture metadata (such as the sender's PID) when `SIGUSR1` is received.
recv_signal.c - Receiver program that waits for `SIGUSR1` and extracts an integer payload.
send_signal.c - Sender program that uses `sigqueue` to transmit a random integer value along with `SIGUSR1` to a target PID.

## How to Compile and Run

Compile the programs using `gcc`:
gcc -o recv_signal recv_signal.c
gcc -o send_signal send_signal.c