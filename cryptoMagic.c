#include<stdio.h>
#include<string.h>

/*
encypt();   ENCRYPT AND DECRYPT FUNTIONS & DEFINITIONS
decrypt();
*/

int main (int argc, char *argv[]){ //argc for arguement count argv for arguement vector  * is  pointer

/*There will be three arguements.  The program itself, the file to be changed, and to encrypt or decrypt*/

if (argc ==2){
        printf("Insufficient arguments.  Please supply file and select -D or -E.\n");
}
else if (argc==3){
    printf("Correct number of arguements supplied.\nThe file %s will be %s.\n", argv[1],(*argv[2]=='D')?"decrypted":"encrypted"); //can't select decrypted.  has to do with char variable.
    printf("%s",argv[2]);

    if (*argv[2]=='D'){
        printf("\nRun decrypt function");
    }
    else
        printf("\nRun encrypt function"); //UNTIL fIX ARGUMENT SWITCH THIS RUNS
        
        /*
        FILE *pf;
        char data[50];
        pf = fopen("text.txt","r"); //open file function, r for read mode?
        fgets(data, 50,pf);
        printf("It read %s",data);
        */





}
else
    printf("Too many arguements!\n");

    return 0;
} 
