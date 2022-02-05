//****************************************************************************
// File name:	dup2_example.c
// Author:		chadd williams
// Date:		2/21/2018
// Class:		CS 460
// Assignment:	In Class Examples
// Purpose:		Demonstrate dup2
//***************************************************************************



#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define MAXLEN 1024

/****************************************************************************
 Function: 		main
 
 Description:	open a file, dup stdout to that file, print to file and stdout
 
 Parameters:	none
 
 Returned:		0
****************************************************************************/
int main()
{
	/* dup2(int oldfd, int newfd)  makes newfd be 
	 * the copy of oldfd closing newfd first if necessary.
	 */

	char data[MAXLEN];
	int fd;
	int save_stdout_fd;
	
	save_stdout_fd = dup(STDOUT_FILENO);
	
	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	
	dup2(fd, STDOUT_FILENO);
	
	// stderr
	fprintf(stderr,"> ");
	
	// stdin
	fgets(&(data[0]),MAXLEN,stdin);
	
	// test.txt via fd
	write(fd, &(data[0]), strlen(data));
	
	// ????
	printf("%d: %s\n", __LINE__, data);
	
	// ???? 
	close(fd);
	
	// ????
	printf("%d: ONCE MORE: %s\n", __LINE__, data);
	
	// ????
	dprintf(save_stdout_fd, "%d: SCREEN!\n\n", __LINE__);

	// why is this necessary?
	fflush(NULL);
	
	dup2(save_stdout_fd, STDOUT_FILENO);

	// ????
	printf("%d: FINALLY: %s \n", __LINE__, data);
	
	return 0;
}
