#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include  "colors.h"


void printDir(struct stat s, struct dirent *d, int n){

    if(stat(d->d_name, &s) == 0){

        if(S_ISDIR(s.st_mode)){
            printf(GREEN "0%d. %s/\n", n, d->d_name);
        }

        if(S_ISREG(s.st_mode)){
            printf(BLUE "0%d. %s\n", n, d->d_name);
        }
    }
            
}

int main(int argc, char *argv[]){
    int num = 0;
    DIR* dir;
    struct stat info;

    if(argv[1] == NULL){
        dir = opendir(".");
    } else {
        dir = opendir(argv[1]);
    }
    

    if(dir == NULL){
        printf("Ocurrió un error al momento de leer el directorio.\n");
        return 1;
    }

    struct dirent *entrada;

    while((entrada = readdir(dir)) != NULL){
        if(strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name, "..") == 0){
            continue;
        }


        if(num < 10){
            printDir(info, entrada, num);
        } else {
            printDir(info, entrada, num);
        }

        num++;
    }

    closedir(dir);

    return 0;
}