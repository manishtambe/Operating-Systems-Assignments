#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

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

    if(p > 0)
    {
        printf("Parent Process : \n");
        printf("Parent => PID: %d\n", getpid());
    }
    else if(p == 0)
    {
        printf("Child Process Before Parent Die = \n");
        printf("Child => PPID: %d PID: %d\n", getppid(), getpid());
        sleep(1);
        printf("Child Process After Parent Die = \n");
        printf("Child => PPID: %d PID: %d\n", getppid(), getpid());
    }
    
    else
    {
        printf("Unable to create an child process !\n");
    }

}
