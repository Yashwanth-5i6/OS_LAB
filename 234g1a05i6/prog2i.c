#include <stdio.h>
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
printf("Child process (PID: %d)\n", getpid());
execlp("/bin/ls", "ls", NULL); // Execute the `ls` command
perror("Exec failed");
return 1;
} else {
// Parent process
printf("Parent process (PID: %d), waiting for child...\n", getpid());
wait(NULL); // Wait for the child to finish
printf("Child process finished.\n");
}
return 0;
}
