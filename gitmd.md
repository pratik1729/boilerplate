---
layout: default
title: GIT
---
# GIT

# Setup

## Initialize empty git repository

### git init

## Configure username and email ID

### git config \--global user.name "John Doe"

### git config \--global user.email johndoe@example.com

## Set global proxy.

### git config \--global http.proxy http://username:password@proxy.server.com:port

## Set credential helper for Windows.

### git config \--global credential.helper wincred

______________________

# Status&info

## Show linear history of commits

### git log

## Show the content of the object with ID [hash]

### git cat-file -p [hash]

## Show the changes from the head or between two commits.

### git diff

### git diff [commit1] [commit2] [file]

## List all branches in local and remote repositories.

### git branch -a

## See all tags

### git tag

## Show which tag you are on.

### git describe \--tags

## See config information.

### git config \--list

## Show information about a commit.

### git show [hash]
______________________

# Branching

## Create new branch.

### git branch [name]

## Checkout to a branch or commit. 

Be careful of checking out without commiting.

### git checkout [branch or hash]

## Create and checkout to a new branch.

### git checkout -b [name]
______________________

# Staging

## Add all files for Staging.

### git add .

## Add [file] to staging area. -p is used for interactive staging.

### git add -p [file]
______________________

# Commit

## Commit all staged files with/without message.

### git commit .

### git commit -m [message]
______________________

# Stash

## Annotate your stashes with a description.

### git stash save "description"

## See all stashes.

### git stash list

## Reapply the changes to your working copy and remove it from the stash.

### git stash pop "stash@{2}"

## Reapply the changes to your working copy and without removing it from the stash.

### git stash apply "stash@{2}"