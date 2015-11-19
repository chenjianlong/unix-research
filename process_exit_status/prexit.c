#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void pr_exit(int status)
{
    if (WIFEXITED(status)) {
        printf("normal termination, exit status = %d\n",
                WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("abnormal termination, signal number = %d%s\n",
                WTERMSIG(status),
                WCOREDUMP(status) ? " (core file generated)" : "");
    } else if (WIFSTOPPED(status)) {
        printf("child stopped, signal number = %d\n",
                WSTOPSIG(status));
    }
}

int main(int argc, char *argv[])
{
	int status;
    pid_t pid;

	if (argc < 2) {
		printf("command-line argument required\n");
        exit(0);
	}

    if ((pid = fork()) < 0) {
		printf("fork error\n");
        exit(0);
    } else if (pid == 0) {
        if (execl(argv[1], argv[1], (char*)0) < 0) {
            printf("execl error\n");
            return 0;
        }
    }

    if (waitpid(pid, &status, 0) < 0) {
        printf("waitpid error\n");
        return 0;
    }

    printf("status = %d\n", status);
	pr_exit(status);
	exit(0);
}
// vim: set et ts=4 sts=4 sw=4:
