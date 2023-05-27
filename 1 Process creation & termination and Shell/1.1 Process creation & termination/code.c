#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

void getDetails(char* sec_) {
    FILE *fptr;
    fptr = fopen("file.csv","r");
    char* c;
    while (fgets(c, 2000, fptr)) {
        char* field = strtok(c, ",");
        int id = atoi(field);
        field = strtok(NULL, ",");
        char* sec = field;
        field = strtok(NULL, ",");
        int a1 = atoi(field);
        field = strtok(NULL, ",");
        int a2 = atoi(field);
        field = strtok(NULL, ",");
        int a3 = atoi(field);
        field = strtok(NULL, ",");
        int a4 = atoi(field);

        int avg = (a1+a2+a3+a4)/4;

        if (strcmp(sec, sec_) == 0) {
            // write(STDOUT_FILENO, &id, sizeof(id));
            // write(STDOUT_FILENO, &sec, sizeof(sec));
            // write(STDOUT_FILENO, &a1, sizeof(a1));
            // write(STDOUT_FILENO, &a2, sizeof(a2));
            // write(STDOUT_FILENO, &a3, sizeof(a3));
            // write(STDOUT_FILENO, &a4, sizeof(a4));
            // write(STDOUT_FILENO, &avg, sizeof(avg));
            // printf("%s %s %s %s %s %s %d\n",id, sec, a1, a2, a3, a4, (a1+a2+a3+a4)/4);
            printf("%d %s %d %d %d %d %d\n",id, sec, a1, a2, a3, a4, (a1+a2+a3+a4)/4);

        }
            // printf("%d %s %d %d %d %d %d\n",id, sec, a1, a2, a3, a4, (a1+a2+a3+a4)/4);
    }
    fclose(fptr);

}

int main() {
    int status;
    pid_t pid, cpid, w;

    pid = fork();
    if (pid == -1){
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        getDetails("A");
        exit(0);
    }
    else {

        w = waitpid(pid, &status, WUNTRACED);
        if (w == -1) {
            perror("waitpid");
            exit(1);
        }

        if (WIFEXITED(status)) {
            getDetails("B");

        }
    }

}
