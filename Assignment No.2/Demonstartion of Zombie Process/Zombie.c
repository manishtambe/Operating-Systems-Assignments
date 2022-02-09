#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void Demo();

int main()
{
    Demo();
    return 0;
}

void Demo()
{
    int p = 0;
    
    p = fork();

    if(p == 0)
    {
        printf("Child => PPID: %d PID: %d\n", getppid(), getpid());
        exit(0);
    }
    else if(p > 0)
    {
        printf("Parent => PID: %d\n", getpid());
        sleep(10);
    }
    else
    {
        printf("Unable to create an child process !\n");
    }
}

/* We cannot kill the zombie process as it itself is an dead process its entry only can be removed from process table from 
   its parent itself of if parent process is also get killed its parenting is done by the init process which is an parent 
   process of all the process that exists in the system so that in the above program we are executing parent process and keep
   it in the wait for 10 seconds in that period child process will executes and get exited but its entry will in the process
   table for the 10 seconds at that period that process will becomes zombie process when ever parent process comes out from 
   the sleep it will delete the entry of the zombie process from the process table.
*/