#include<stdio.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("Process id of Hello.c = %d\n",getpid());
    printf("Hello ! From Hello.c\n");
    return 0;
}