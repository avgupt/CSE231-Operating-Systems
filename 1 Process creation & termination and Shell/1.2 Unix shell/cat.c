#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cat_E(char* path) {
    int fd = open(path, O_RDONLY);
    
    if (fd == -1) {
        printf("Error while opening '%s'\n", path);
        exit(0);
    }

    int ch = 0;
    char buff[1];

    while((ch = read(fd, buff, 1)) > 0) {
        if (buff[0] == '\n')
            write(STDOUT_FILENO, "$", strlen("$"));

        write(STDOUT_FILENO, buff, ch+1);
    }
    close(fd);
}

void cat_n(char* path) {
    int fd = open(path, O_RDONLY);
    
    if (fd == -1) {
        printf("Error while opening '%s'\n", path);
        exit(0);
    }

    int ch = 0;
    char buff[1];
    int lineNum = 1;
    printf("%d ", lineNum++);
    while((ch = read(fd, buff, 1)) > 0) {
        printf("%s", buff);
        if (buff[0] == '\n')
            printf("%d ", lineNum++);
        
    }
    printf("\b\b\b\b\b\n");
    close(fd);
}

int main(int argc, char *argv[])
{
    if (strcmp(argv[0], "-E") == 0) {
        cat_E(argv[1]);
    }
    else if (strcmp(argv[0], "-n") == 0) {
        cat_n(argv[1]);
    }
    else {
        printf("cat: bad option %s\n", argv[0]);
    }
    exit(0);
    return 0;
}
