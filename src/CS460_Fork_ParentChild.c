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
  int status;

  childPid = fork();

  if ( 0 == childPid)
  {
    printf("I am a child\n");  
  }
  else
  {
    waitpid(childPid, &status, 0);
    printf("I am a parent\n");
  }
  
  
}