/*!
 * \file main.c
 * \brief test trancate an opening file
 * \author Jianlong Chen <jianlong99@gmail.com>
 * \date 2013-11-20
 */
/* $Id$ */
#include "tellwait.h"
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main ()
{
	int fd = 0;
	pid_t pid;

	TELL_WAIT ();
	pid = fork ();
	if (pid == -1) {
		err_sys ("\nfork failed");
	} else if (pid == 0) {
		WAIT_PARENT ();
		fd = open ("./temp.map", O_RDWR | O_CREAT | O_TRUNC);
		TELL_PARENT (getppid ());
		if (-1 == fd) {
			err_sys ("\nopen failed by child");
		} else {
			printf ("open by child successful\n");
		}
		exit (1);
	}

	fd = open ("./temp.map", O_RDWR | O_CREAT | O_EXCL, 0666);
	if ((-1 == fd) && (errno == EEXIST)) {
		fd = open ("./temp.map", O_RDWR, 0666);
	}

	if (-1 == fd) {
		TELL_CHILD (pid);
		err_sys ("\ncan not open file by parent");
	}


	if (MAP_FAILED == mmap (NULL, 1024, PROT_READ | PROT_WRITE,
				MAP_SHARED, fd, 0)) {
		TELL_CHILD (pid);
		err_sys ("\nmmap failed");
	}

	printf ("open and mmap by parent success\n");
	TELL_CHILD (pid);
	WAIT_CHILD ();
	exit (0);
}
