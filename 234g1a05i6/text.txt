#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
int main() {
const char *filename = "text.txt";
struct stat file_stat;
int fd = open(filename, O_RDONLY); // Open file for reading
if (fd < 0) {
perror("Failed to open file");
return 1;
}
if (fstat(fd, &file_stat) < 0) { // Get file stats
perror("Failed to get file stats");
close(fd);
return 1;
}
printf("File: %s\nSize: %ld bytes\n", filename, file_stat.st_size);
close(fd); // Close the file
return 0;
}