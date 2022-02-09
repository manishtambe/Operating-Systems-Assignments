#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    char *Args[] = {"Hello",NULL};
    printf("Process id of Exec.c = %d\n",getpid());
    execv("./Hello",Args);
    return 0;
}
