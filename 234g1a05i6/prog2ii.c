#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
pid_t pid = fork();
if (pid < 0) {
perror("Fork failed");
return 1;
}
if (pid == 0) {
// Child process
printf("Child process (PID: %d), exiting...\n", getpid());
exit(42); // Exit with status code 42
} else {
// Parent process
int status;
wait(&status); // Wait for the child process
if (WIFEXITED(status)) {
printf("Child exited with status: %d\n", WEXITSTATUS(status));
}
}
return 0;
}