#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]){
    int num = 0;
    DIR* dir;

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
            printf("0%d. %s\n", num, entrada->d_name);
        } else {
            printf("%d. %s\n", num, entrada->d_name);
        }

        num++;
    }

    closedir(dir);

    return 0;
}