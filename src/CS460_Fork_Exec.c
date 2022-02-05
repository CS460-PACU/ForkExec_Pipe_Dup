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
  //char *aArgs[] = {"/usr/bin/ls", "-al", '\0'};
  char *aArgs[] = {"/bin/ls", "-al", '\0'};


  childPid = fork();

  if ( 0 == childPid)
  {
    execv(aArgs[0], aArgs);
    perror("execv");
    printf("I WILL NEVER PRINT\n");  
  }
  else
  {
    waitpid(childPid, &status, 0);
    printf("\nI am a parent\n");
  }
  
  
}