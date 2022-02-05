/****************************************************************************
 File name:  CS460_Fork.c
 Author:     
 Date:       
 Class:      
 Assignment: 
 Purpose:    
 ****************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/****************************************************************************
 Function:    main
 
 Description  Demonstrate fork() and getpid()

 Parameters:  None

 Return:      None
 ****************************************************************************/

int main()
{

  const int READ = 0;
  const int WRITE = 1;
  int value = 42;

  pid_t childPid;
  int status;
  int thePipe[2];

  pipe(thePipe);

  childPid = fork();

  if( 0 == childPid) 
  {
    write(thePipe[WRITE], &value, sizeof(int));
    close(thePipe[WRITE]);

    printf("I am a child\n");
  }
  else
  {
    close(thePipe[WRITE]);
    value = 0;
    read(thePipe[READ], &value, sizeof(int));
  
    printf("VALUE: %d\n", value);

    waitpid(childPid, &status, 0);
    printf("I am a parent\n");
  }

  close(thePipe[READ]);
}