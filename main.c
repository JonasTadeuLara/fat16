#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "string.h"
#include "fat.h"

#define BUFFER_SIZE 1024

int main(){
    char buffer[BUFFER_SIZE];
    char *arquivo = NULL, *string = NULL, comando = 0;
    int i = 0, j = 0;
    bool ler_string = false, ler_diretorio = false;

    printf("pois não senhor: ");
    while(fgets(buffer, BUFFER_SIZE, stdin)){
        
        i = 0, j = 0;
        while (isspace(buffer[i])) i++;
        while(!isspace(buffer[i + j])) j++;

        if(strncmp(&(buffer[i]), "mkdir", j)   == 0 
        || strncmp(&(buffer[i]), "create", j)  == 0 
        || strncmp(&(buffer[i]), "unlink", j)  == 0 
        || strncmp(&(buffer[i]), "mkdir", j)   == 0
        || strncmp(&(buffer[i]), "read", j)    == 0) {
            comando = buffer[i];

            ler_string = false;
            ler_diretorio = true;
        }

        else if(strncmp(&(buffer[i]), "init", j) == 0) {
            comando = buffer[i];

            ler_string = false;
            ler_diretorio = false;
        }

        else if(strncmp(&(buffer[i]), "load", j) == 0) {
            comando = buffer[i + 1];

            ler_string = false;
            ler_diretorio = false;
        }

        else if(strncmp(&(buffer[i]), "ls", j) == 0) {
            comando = buffer[i + 1];

            ler_string = false;
            ler_diretorio = true;
        }       

        else if (strncmp(&(buffer[i]), "write", j)   == 0 || strncmp(&(buffer[i]), "append", j)  == 0) {
            comando = buffer[i];

            ler_string = true;
            ler_diretorio = true;
        }

        i += j;

        if(ler_string) {
            j = 1;
            while(buffer[i] != '"') i++;
            while(buffer[i + j] != '"') j++;
            
            string = calloc(j, sizeof(char));
            strncpy (string, &(buffer[i + 1]), j - 1);

            i += j + 1;
        }

        if(ler_diretorio){
            j = 1;
            while (isspace(buffer[i])) i++;
            while (!isspace(buffer[i + j])) j++;

            arquivo = calloc(j + 1, sizeof(char));
            strncpy (arquivo, &(buffer[i]), j);
        }

        printf("%c -*- %s -*- %s\n", comando, string, arquivo);
        
        switch (comando) {
        case 'i': // INIT
            /* code */
            break;
        case 'o': // LOAD
            /* code */
            break;
        case 's': // LS
            /* code */
            break;
        case 'm': // MKDIR
            /* code */
            break;
        case 'c': // CREATE
            /* code */
            break;
        case 'u': // UNLINK
            /* code */
            break;
        case 'w': // WRITE
            /* code */
            break;
        case 'a': // APPEND
            /* code */
            break;
        case 'r': // READ
            /* code */
            break;
        default:
            printf("Comando n reconhecido\n");
            break;
        }

        if(ler_diretorio) free(arquivo);
        if(ler_string) free(string);
        printf("Pois não senhor: ");
    }



    return 0;
}