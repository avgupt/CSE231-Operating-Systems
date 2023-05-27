#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/dir.h>
#include <malloc.h>
#include <stdlib.h>

void ls_1(char* path) {
    struct dirent *de;

    struct dirent **names;
    int returnValue;
    int index = 0;

    returnValue = scandir(path, &names, NULL, alphasort);

    if (returnValue < 0) {
        perror("scandir");
    }
    else {
        while (index < returnValue) {
            if (names[index]->d_name[0] != '.') printf("%s\n", names[index]->d_name);
            free(names[index]);
            ++index;
        }
    }
}

void ls_m(char* path) {
    struct dirent *de;

    struct dirent **names;
    int returnValue;
    int index = 0;

    returnValue = scandir(path, &names, NULL, alphasort);
    if (returnValue < 0) {
        perror("scandir");
    }
    else {
        while (index < returnValue) {
            if (names[index]->d_name[0] != '.') printf("%s ,", names[index]->d_name);
            free(names[index]);
            ++index;
        }
        printf("\b \n");
    }
}

int main(int argc, char *argv[])
{
    if (strcmp(argv[0], "-1") == 0) {
        if (argv[1] == NULL)
            ls_1(".");
        else
            ls_1(argv[1]); 
    }
    else if (strcmp(argv[0], "-m") == 0) {
        if (argv[1] == NULL)
            ls_m(".");
        else
            ls_m(argv[1]);
    }
    exit(0);
    return 0;
}
