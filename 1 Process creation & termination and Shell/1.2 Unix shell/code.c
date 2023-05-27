#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>


#define MAX_LIMIT 200
void cd(char* in) {
    char s[100];
    strtok(in, "\n");
    if (in == "~") {
        chdir(getenv("HOME"));
    }
    else {
        int check = chdir(in);
        if (check == -1) {
            perror("chdir()");
            return;
        }
    }
}

void echo(char* in) {
    // -n and -e

    char* s = in;
    in = strtok(NULL, " ");
    if (strcmp(s, "-n") == 0) {
        strtok(in, "\n");
        printf("%s", in);
    }
    else if (strcmp(s, "-e") == 0) {
        printf("%s", in);
    }
    else {
        printf("%s ", s);
        while (in != NULL) {
            printf("%s ", in);
            in = strtok(NULL, " ");
        }
    }
}

void pwd_P() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        // write(STDOUT_FILENO, cwd, sizeof(cwd));
        printf("%s\n", cwd);
        
    }
    else {
        perror("getcwd() error");
    }
}

void pwd_L() {
    system("pwd");
}

int main(int argc, char* argv[]) {

    char cwd[PATH_MAX];
    char* pwd = getcwd(cwd, sizeof(cwd));
    strcat(pwd, "/");

    while (1) {
        char str[MAX_LIMIT];
        char *command;

        fgets(str, MAX_LIMIT, stdin); 
        command = strtok(str, " ");  

        if (strcmp(command, "cd") == 0) {
            command = strtok(NULL, " ");
            cd(command);
        }
        else if (strcmp(command, "echo") == 0) {
            command = strtok(NULL, " ");
            echo(command);
        }
        else if (strcmp(command, "pwd") == 0) {
            command = strtok(NULL, " ");
            if (strcmp(command, "-P\n") == 0) {
                pwd_P();
            }
            else if (strcmp(command, "-L\n") == 0 || command == NULL)
                pwd_L();
            else
                printf("pwd: bad option %s", command);
        }
        else if (strcmp(command, "pwd\n") == 0) {
            pwd_L();
        }

        else if (strcmp(command, "exit\n") == 0)
            exit(0);
            
        else {
            int status;
            pid_t pid, w;
            char c;

            pid = fork();


            if (pid < 0){
                perror("fork");
                exit(1);
            }


            if (pid == 0) {
                
                char* fileName = pwd;
                strcat(fileName, command);

                command = strtok(NULL, " ");
                char* flag = command;
                
                command = strtok(NULL, " ");
                char* file = command;

                if (file != NULL) {
                    file = strtok(file, "\n");
                }

                printf("%s %s %s \n", fileName, flag, file);
                int check = execl(fileName, flag, file, NULL);
                if (check == -1) {
                    perror("execl()");
                }

                exit(0);
            }

            else {
                w = waitpid(pid, &status, WUNTRACED);
                if (w == -1) {
                    perror("waitpid");
                    exit(1);
                }
            }

        }

    }
    

}