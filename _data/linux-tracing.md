---
layout: default
title: TRACING
---
# Tracing

# strace

Monitor and capture system calls

| Command                                 | Description                                                             |
| --------------------------------------- | ----------------------------------------------------------------------- |
| strace [command]                        | trace all system calls of the command                                   |
| strace -p [pid]                         | trace already running process                                           |
| strace -c -p [pid]                      | generate report of total time, calls and errors for each system call    |
| strace -T [command]                     | show time spent in the system call                                      |
| strace -e trace=[system call] [command] | Trace only specific system calls, comma separated names of system calls |
| strace -e trace=process [command]       | system calls involving process management                               |
| strace -e trace=file [command]          | system calls that take filename as argument                             |
| strace -e trace=memory [command]        | system calls involving memory mapping                                   |
| strace -e trace=network [command]       | system calls related to networking                                      |
| strace -e trace=signal [command]        | system calls related to signals                                         |
| strace -o [file.strace]                 | save trace data to file                                                 |