---
layout: default
title: Dev Tools
---
# Dev Tools

# Valgrind

## Basic usage

### valgrind \--tool=[tool name] [tool options] [program] [program options]

## Tools

[//]: # ("code table")

| Tool    | Options    | Description                                                                      |
| ------- | ---------- | -------------------------------------------------------------------------------- |
| --tool= | memcheck   | memory error detector, memory leaks, invalid memory access                       |
| ------- | ---------- | -------------------------------------------------------------------------------- |
|         | cachegrind | cache misses, miss rate                                                          |
| ------- | ---------- | -------------------------------------------------------------------------------- |
|         | callgrind  | number of instructions executed, their relationship to source lines,             |
|         |            | the caller/callee relationship between functions, and the numbers of such calls. |
| ------- | ---------- | -------------------------------------------------------------------------------- |
|         | helgrind   | a thread error detector, detects synchronisation errors                          |
| ------- | ---------- | -------------------------------------------------------------------------------- |
|         | drd        | a thread error detector                                                          |
| ------- | ---------- | -------------------------------------------------------------------------------- |
|         | massif     | heap profiler. It measures how much heap memory your program uses.               |
| ------- | ---------- | -------------------------------------------------------------------------------- |
|         | dhat       | a dynamic heap analysis tool                                                     |
| ------- | ---------- | -------------------------------------------------------------------------------- |
|         | lackey     | various kinds of basic program measurement like number of function calls, etc    |
| ------- | ---------- | -------------------------------------------------------------------------------- |
|         | exp-bbv    | an experimental basic block vector generation tool                               |
| ------- | ---------- | -------------------------------------------------------------------------------- |

# gcc

| Option        | Description          | Description    |
| ------------- | -------------------- | -------------- |
| -fsanitize=   | address              |                |
|               | undefined            |                |
|               | float-cast-overflow  |                |
|               | float-divide-by-zero |                |
| -Wall -Wextra |                      | Shows warnings |
|               |                      |                |
