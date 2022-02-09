#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void CreateArray(int *Arr, int iSize)
{
    int iElement = 0;
    int p = 0;
    int i = 0;
    int j = 0;
    int temp = 0;

    for(i = 0; i < iSize; i++)
    {
        printf("Enter the %d element in the array = \n", i + 1);
        scanf("%d",&iElement);
        Arr[i] = iElement;
    }

    printf("The Entered Array Elements Are = \n");

    for(i = 0; i < iSize; i++)
    {
        printf("%d\n",Arr[i]);
    }

    p = fork();

    if(p == 0)
    {
        printf("Child => PPID: %d PID: %d\n", getppid(), getpid());
        for(i = 0; i < iSize; i++)
        {
             for(j = i+1; j < iSize; j++)
            {
                 if(Arr[i] < Arr[j])
                {
                     temp = Arr[i];
                     Arr[i] = Arr[j];
                     Arr[j] = temp;
                }
            }
        }

        printf("The Entered Array Elements In Descending Order Are = \n");
        for(i = 0; i < iSize; i++)
        {
            printf("%d\n",Arr[i]);
        }
    }
    else 
    if(p > 0)
    {
        
        printf("Parent => PID: %d\n", getpid());

        for(int i = 0; i < iSize; i++) 
        {     
            for(int j = i+1; j < iSize; j++) 
            {     
                if(Arr[i] > Arr[j]) 
                {    
                    temp = Arr[i];    
                    Arr[i] = Arr[j];    
                    Arr[j] = temp;    
                }
           }     
        }  

        printf("The Entered Array Elements In Ascending Order Are = \n");
        for(i = 0; i < iSize; i++)
        {
            printf("%d\n",Arr[i]);
        }

        wait(NULL);
    }
    else
    {
        printf("Child process is created successfully but error while creating an child process !\n");
    }
}

int main()
{
  
    int iSize = 0;
    int *Arr = NULL;

    printf("Enter the number of elements you want to add in the array = \n");
    scanf("%d",&iSize);

    Arr = (int*)malloc(sizeof(int)*iSize);

    CreateArray(Arr,iSize);
    
    return 0;
}
