/*!
 * \file error.h
 * \brief the error.c is copy from apue.2e
 */

#ifndef ERROR_H
#define ERROR_H

void err_ret (const char *fmt, ...);
void err_sys (const char *fmt, ...);
void err_exit (const char *fmt, ...);
void err_dump (const char *fmt, ...);
void err_msg (const char *fmt, ...);
void err_quit (const char *fmt, ...);

#endif /* ERROR_H */
