/*!
 * \file tellwait.h
 * \brief the tellwait.c is copy from apue.2e
 */

#ifndef TELL_WAIT_H
#define TELL_WAIT_H

#include <unistd.h>

void TELL_WAIT (void);
void TELL_PARENT (pid_t pid);
void WAIT_PARENT (void);
void TELL_CHILD (pid_t pid);
void WAIT_CHILD (void);

#endif /* TELL_WAIT_H */
