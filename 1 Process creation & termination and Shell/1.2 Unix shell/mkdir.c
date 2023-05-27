#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void createParent(char* path);

void mkdir_v(char* path) {
    int check = mkdir(path, 0777);
    if (check == -1) {
        printf("Error while creating the directory\n");
    }
}

void mkdir_p(char* path) {
    printf("%s\n", path);
    int check = mkdir(path, 0777);
    if (check == -1) {
        createParent(path);
    }
}


void createParent(char* path) {
    int nameIndex = -1;
    int index = 0;
    while (path[index] != '\0') {
        if (path[index] == '/') nameIndex = index;
        index++;
    }
    if (nameIndex == -1) return;
    
    int len = strlen(path) - nameIndex - 1;
    char name[len + 1];
    
    char newPath[nameIndex+1];
    index = 0;
    while (index < nameIndex) {
        newPath[index] = path[index];
        index++;
    }
    newPath[index] = '\0';
    mkdir_p(newPath);
    mkdir(path, 0777);
}

int main(int argc, char *argv[])
{
    if (strcmp(argv[0], "-v") == 0) {
        if (argv[1] == NULL)
            mkdir_v(".");
        else
            mkdir_v(argv[1]); 
    }
    else if (strcmp(argv[0], "-p\n") == 0) {
        if (argv[1] == NULL) 
            mkdir_p(".");
        else
            mkdir_v(argv[1]);
    }
    else {
        printf("mkdir: bad option %s", argv[0]);
    }
    exit(0);
    return 0;
}
