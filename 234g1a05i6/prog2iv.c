#include <stdio.h>
#include <dirent.h>
int main(int argc, char *argv[]) {
const char *path = argc > 1 ? argv[1] : ".";
DIR *dir = opendir(path);
if (!dir) {
perror("Error opening directory");
return 1;
}
struct dirent *entry;
while ((entry = readdir(dir)) != NULL) {
printf("%s\n", entry->d_name);
}
closedir(dir);
return 0;
}