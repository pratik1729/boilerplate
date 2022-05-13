---
layout: default
title: BASH
---
# BASH

# Loops

## For loop

[//]: # ("code table")

| Basic for                        | C-like for                            | Ranges                  |
| -------------------------------- | ------------------------------------- | ----------------------- |
| ```bash                          | ```bash                               | ```bash                 |
| for i in [ls ⎮ /dir1/dir2/*]; do | for i in ((i = 0 ; i < 10 ; i++)); do | for i in {5..50..5}; do |
| echo $i                          | echo $i                               | echo $i                 |
| done                             | done                                  | done                    |
| ```                              | ```                                   | ```                     |

## While loop

[//]: # ("code table")

| while          | While infinite oneline        |
| -------------- | ----------------------------- |
| ```bash        | ```bash                       |
| while true; do | while true; kill -9 420; done |
| ```            | ```                           |

# Conditionals

[//]: # ("code table")

| Compare strings                   | Check if string is empty(-z) or not(-n) | Compare numerics             |
| --------------------------------- | --------------------------------------- | ---------------------------- |
| ```bash                           | ```bash                                 | ```bash                      |
| if [[ "$str1" == "$str2" ]]; then | if [[ -z "$string" ]]; then             | if (( $n < $m )); then       |
| ```                               | echo "empty"                            | echo "$n is smaller than $m" |
|                                   | elif [[ -n "$string" ]]; then           | fi                           |
|                                   | echo "not empty"                        | ```                          |
|                                   | else                                    |                              |
|                                   | echo "This is to show if structure"     |                              |
|                                   | fi                                      |                              |
|                                   | ```                                     |                              |

# Arrays

## Basic operations

[//]: # ("code table")

| Define arrays. Element accessed via indexing - arr[0] | Iterate over an array    |
| ----------------------------------------------------- | ------------------------ |
| ```bash                                               | ```bash                  |
| arr=(a0 a1 a2)                                        | for i in "${arr[@]}"; do |
|                                                       | echo $i                  |
|                                                       | done                     |
| ```                                                   | ```                      |

## Advanced

[//]: # ("code table")

| Access last element | All elements, space separated | Number of elements | Get element at Nth position | Get subarray from position m and length n | Get keys of all elements, space separated, for dicts |
| ------------------- | ----------------------------- | ------------------ | --------------------------- | ----------------------------------------- | ---------------------------------------------------- |
| ```bash             | ```bash                       | ```bash            | ```bash                     | ```bash                                   | ```bash                                              |
| echo ${arr[-1]}     | echo ${arr[@]}                | echo ${#arr[@]}    | echo ${arr[N]}             | echo ${arr[@]:m:n}                        | echo ${!arr[@]}                                      |
| ```                 | ```                           | ```                | ```                         | ```                                       | ```                                                     |

# Numerics

Numerical Calculations are written in $((...)).

[//]: # ("code table")

| Calculations | Generate random numbers 0..N |
| ------------ | ---------------------------- |
| ```bash      | ```bash                      |
| $((a+b))     | $(($RANDOM%N))               |
| ```          | ```                          |

# Special variables

| Number of arguments | All positional arguments (as a single word) | All positional arguments (as separate strings) | Nth positional arguments(0=filename of the script) | Exit status of last task | PID of last background task | PID of shell |
| ------------------- | ------------------------------------------- | ---------------------------------------------- | -------------------------------------------------- | ------------------------ | --------------------------- | ------------ |
| $#                  | $*                                          | $@                                             | $N                                                 | $?                       | $!                          | $$           |

# Redirection

[//]: # ("code table")

| stdout to file     | stdout to file append | stderr to file      | stderr to stdout | stderr to null      | stdout&stderr to null | feed file into stdin |
| ------------------ | --------------------- | ------------------- | ---------------- | ------------------- | --------------------- | -------------------- |
| ./a.out > file.txt | ./a.out >> file.txt   | ./a.out 2> file.txt | ./a.out 2>&1     | ./a.out 2>/dev/null | ./a.out &>/dev/null   | ./a.out < file.txt   |

<p>
bash is used for interactive scripts execution and dash is for non-interactive scripts.<br>
/bin/sh is link to dash binary. dash is much faster than bash.<br>
dash is useful when redirection with sudo does not work, e.g.<br>
sudo echo 0 > file_owned_by_root, fails<br>
sudo sh -c 'echo 0 > file_owned_by_root'<br>
single quotes are Important.
</p>