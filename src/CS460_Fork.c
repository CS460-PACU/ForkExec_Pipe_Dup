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

  pid_t childPid;
  
  childPid = fork();

  // exit if fork fails
  if(-1 == childPid)
  {
    perror("Fork failed");
    return -1;
  }
  printf("Other PID: %d My PID: %d\n", childPid, getpid());

}