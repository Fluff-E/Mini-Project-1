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
    printf("Correct number of arguements supplied.\nThe file %s will be %s.\n", argv[2],(*argv[1]=='D')?"decrypted":"encrypted"); //can't select decrypted.  has to do with char variable.
    printf("argv[1]: %s\n",argv[1]);

    if (*argv[1]=='D'){
    /////////DECRYPTION////////////    
        

        
    }
    else{
    //////////ENCRYPTION///////////        
        FILE *file_read;  //pointers for files
        FILE *file_write;
        char line[120];// lines 120 characters each

        file_read = fopen(argv[2],"r"); //open file function, r for read mode
        file_write = fopen("Write.crp","w"); //open file, w for writing
        
        while(!feof(file_read)){ //while end of file not reached
            
            fgets(line,120,file_read);//sends a 120 character string to the char array line
                       
            for(int i=0;i<119;i++){                     //check each character of line for encryption needs
               if(!(line[i]==9)||(line[i]==13)){        //don't encrypt tabs ASCII 9 or carriage returns ASCII 13
                    line[i] -= 16;                      //take ASCII code and subtract 16
                    if (line[i]<32)
                        line[i] = line[i] - 32 + 144;   //if resulting character is less than 32, subtract 32, add 144
               } 
               
            }
            //convert from char to hex
            fprintf(file_write,"%2X",line);//formated print to file, formated capital hex 2 char, from line 
        }
        fclose(file_read);//Close files
        fclose(file_write);       
    }
    
}
else
    printf("Too many arguements!\n");

    return 0;
} 
