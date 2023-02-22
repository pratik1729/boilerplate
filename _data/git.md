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

## Set aliases

### git config --global alias.hist "log \--all \--graph \--decorate \--oneline"

Alias are saved in ~/.gitconfig file. Use this alias as:

### git hist

### .gitignore file is used to ignore unwanted files and folders. Its syntax is one expression per line. It can be a file glob also. 
______________________

# Status&info

## Repository status

### git status

## git logs

Show linear history of commits

### git log

### git log [commit1]...[commit2]

### git log \--since="3 days ago"

Specific history of an individual file. Returns commits that involve this file.

### git log \-- [file]

History in tree form, more useful when branches exist

### git log \--all \--graph \--decorate \--oneline

## Show the content of the object with ID [hash]

### git cat-file -p [hash]

## Show the changes from the head or between two commits.

### git diff

### git diff [commit1] [commit2] [file]

## List all branches in local and remote repositories.

### git branch -a

## Information about remote

To get remote URL:

### git config \--get remote.origin.url

To show full information about remote repo:

### git remote show origin

## See all tags

### git tag

## Show which tag you are on.

### git describe \--tags

## See config information.

### git config \--list

## Show information about a commit.

### git show [hash]
______________________

# Clone & Pull

## Cloning remote repository

### git clone [repo.git]

The remote master branch is named as 'origin/master'. 'origin' is reference to remote repository.

## Update local repository with changes from remote.

Name of remote repo and branch is entered.

### git pull origin master
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

## Add all files, folders and all subfolders recursively for Staging.

### git add .

## Add [file] to staging area. -p is used for interactive staging.

### git add -p [file]

Same file can be in the staging area as well as working directory(unstaged area). Some changes to the file were staged and new changes are still in the working directory.  

Add all unstaged as well as untracked files to staging area at once with -A option:

### git add -A

## Unstage changes

### git reset HEAD [file]

## Discard changes in working directory

### git checkout \-- [file]
______________________

# Rename, Move, Delete

## Rename or move file using git mv

It is recommended to rename/move files using git mv. This helps git track/stage that rename/move has happened. This operation can be undoed also.

### git mv [file] [new file name]

Delete actually happens in the repository when commit is done. This command stages the delete operation, the file is deleted from the filesystem. Reset operation unstages the delete operation but does not actually restore the file. You need to do git checkout... command for that.
### git rm [file]
______________________

# Commit

## Commit all staged files with/without message.

### git commit .

### git commit -m [message]

Add and commit one liner. This can only be done with files that can be tracked. Tracked files are those which are commited or added to staging area previously

### git commit -am [message]
______________________

# Push

Name of remote repo and branch is entered.

### git push origin master
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

## Undo applied stash

### git checkout -f

# Patches

## Create patch files for uncommited changes

For unstaged changes

### git diff > filename.patch

For staged changes

### git diff \--cached > filename.patch

# Rectify

## Git message

Rectify incorrect git message

### git commit \--amend -m "New commit message"

If you've already pushed your commit up to your remote branch, then - after amending your commit locally (as described above) - you'll also need to force push the commit with this.  
May cause problem if remote repo is shared.
### git push [remote] [branch] \--force