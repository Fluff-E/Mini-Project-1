#include<stdio.h>
#include<string.h>

/*
encypt();   ENCRYPT AND DECRYPT FUNTIONS & DEFINITIONS
decrypt();
*/

int main (int argc, char *argv[]){ //argc for arguement count argv for arguement vector  * is  pointer

/*There will be three arguements. [0] The program itself,[1] the file to be changed, [2]and to encrypt or decrypt*/

if (argc ==2){
        printf("Insufficient arguments.  Please supply file and select -D or -E.\n");
}
else if (argc==3){
    printf("Correct number of arguements supplied.\nThe file %s will be %s.\n", argv[1],(*argv[2]=='D')?"decrypted":"encrypted"); //can't select decrypted.  has to do with char variable.
    printf("argv[2]: %s\n",argv[2]);

    if (*argv[2]=='D'){ //Try *argv2
        printf("\nRun decrypt function");
    }
    else{
            
        FILE *pf; //pf pointer file
        char data[120];//20 lines 120 characters each
        pf = fopen(argv[1],"r"); //open file function, r for read mode
        
        while(!feof(pf)){ //while end of file not reached
            //int line =0;
            fgets(data, 120,pf);
            //line++;
            printf("It read %s\n",data);

        }
        
        
    }
    
        




}
else
    printf("Too many arguements!\n");

    return 0;
} 
