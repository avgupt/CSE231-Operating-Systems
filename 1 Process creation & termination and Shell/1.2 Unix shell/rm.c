#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

void rm_d(char* path) {
    int check = rmdir(path);
    
    if (check == -1) {
        printf("Error encountered while removing the directory.\n");
    }
}

void rm_f(char* path) {
    
    int check = unlink(path);

    if (check == -1) {
        struct stat sb;
        check = stat(path, &sb);
        if (check == 0) {
            if (sb.st_mode & S_IFDIR) {
                printf("rm: cannot remove '%s': Is a directory\n", path);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (strcmp(argv[0], "-d") == 0) {
        rm_d(argv[1]);
    }
    
    else if (strcmp(argv[0], "-f") == 0) {
        rm_f(argv[1]);
    }
    else {
        printf("rm: bad option %s", argv[0]);
    }
    exit(0);
    return 0;
}

