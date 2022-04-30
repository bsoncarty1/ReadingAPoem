#include "fileTest.h"


int countString(const char* fileName, char *str){
    
    int word_count = 0;
    char stg[BUFSIZ];
    char *pos;
    int index;

    FILE *f1 = fopen(fileName, "r");
    if(f1 == NULL){
        printf("Unable to open the file.");
        exit(EXIT_FAILURE);
    }
    
    while((fgets(stg, BUFSIZ, f1)) != NULL){
        index = 0;
        while((pos = strcasestr(stg+index, str)) != NULL){
            index = (pos - stg) + 1;
            word_count++;
        }
    }

    fclose(f1);
    return word_count;
}


int countEmptyLines(const char *fileName){
    
    int emptyLine = 0;
    int c = '\n';
    int last = '\n';
    
    
    FILE *f1 = fopen(fileName, "r");
    if(f1 == NULL){
        printf("Unable to open the file.");
        exit(EXIT_FAILURE);
    }
        
    while(EOF != (c = fgetc(f1))){
        if(c == '\n' && last == '\n'){
            emptyLine++;
        }
        last = c;
    }
    
    fclose(f1);
    return emptyLine;
}

