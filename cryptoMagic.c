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
    printf("Correct number of arguements supplied.\nThe file %s will be %s.\n", argv[2],(strcmp(argv[1],"-D")==0)?"decrypted":"encrypted"); //if arguement is -D decrypt, everything else encrypt
    //printf("argv[1]: %s\n",argv[1]);//For checking arguement



    if ((strcmp(argv[1],"-D")==0)){
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
            printf("%s\n",line);//Testing 
            //printf("%c\n",line[0]);//Testing  
            
            //printf("String length:%d\n",strlen(line));//Testing
            
            for(int i=0;i<strlen(line);i++){                     //check each character of line for encryption needs
               if((line[i]==9)||(line[i]==13)||(line[i]==10)){        
               // //don't encrypt tabs ASCII 9 or Carriage Returns ASCII 13 or LF ASCII 10    
               }
               else{
                    line[i] -= 16;                      //take ASCII code and subtract 16
                    if (line[i]<32)
                        line[i] = (line[i] - 32) + 144;   //if resulting character is less than 32, subtract 32, add 144
               }
                               
            }
            

           for(int i=0;i<strlen(line);i++){ 
            if((line[i]==13)||(line[i]==10)){//CR LF T not printed as hex
                printf("\n");
                fprintf(file_write,"\n");//formated print to file, formated capital hex 2 char, from line
            }
            else if(line[i]==9){
                //tab is 4 spaces in vs code. save text file from notepad
                printf("%s","TT");
                fprintf(file_write,"%s","TT");
                }
           
           else{//Print the rest in hex
                printf("%2X",line[i]);//Test //Need to use array[] because X is not a string
                fprintf(file_write,"%2X",line[i]);//formated print to file, formated capital hex 2 char, from line
           }
           }        
            printf("\n");
            //printf("%s\n",line);//testing
                //convert from char to hex
                
             
           
        }
        fclose(file_read);//Close files
        fclose(file_write);       
    }
    
}
else
    printf("Too many arguements!\n");

    return 0;
} 
