---
layout: default
title: VIM
---
# Vim

| Command             | Description                                             |
| ------------------- | ------------------------------------------------------- |
| o                   | enter insert mode with new line below current cursor    |
| Shift+o             | enter insert mode with new line above current cursor    |
| gg                  | go to start of file                                     |
| Shift+g             | go to end of file                                       |
| set nu!             | Toggle display of line numbers                          |
| D                   | shift+d, delete from current position to end of line    |
| dG                  | delete from current line to end of file                 |
| cc                  | Change(replace) a line                                  |
| I                   | Insert at the beginning of the line                     |
| a                   | append after cursor                                     |
| A                   | Append at the end of line                               |
| u                   | undo                                                    |
| ctrl+r              | redo                                                    |
| .                   | repeat last command                                     |
| di(                 | delete inside of (...) block where the cursor is        |
| d[line_number]G     | delete upto line_number inclusive from the current line |
| gg=G                | Reident entire buffer                                   |
| ==                  | Autoident the current line                              |
| ={                  | auto-ident the current code block                       |
| :%s/before/after/gc | Replace string with confirm                             |
| tabnew file.txt     | open file.txt in new tab                                |
| ctrl+o              | jump back to the previous (older) location              |