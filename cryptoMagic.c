#include <stdio.h>
#include <string.h>

FILE *file_read; // pointers for files
FILE *file_write;

void encrypt(char file_name[], int n);
void decrypt(char file_name[], int n);

int main(int argc, char *argv[])
{ // argc for arguement count argv for arguement vector  * is  pointer

    /*There will be three arguements. [0] The program itself,[1] the file to be changed, [2]and to encrypt or decrypt*/

    if (argc == 2)
            printf("Insufficient arguments.  Please supply file and select -D or -E.\n");
    
    else if (argc == 3){    
        printf("Correct number of arguements supplied.\nThe file %s will be %s.\n", argv[2], (strcmp(argv[1], "-D") == 0) ? "decrypted" : "encrypted"); // if arguement is -D decrypt, everything else encrypt
        // printf("argv[1]: %s\n",argv[1]);//For checking arguement

        if ((strcmp(argv[1], "-D") == 0)){        
            /////////DECRYPTION////////////
            decrypt(argv[2], strlen(argv[2]));
        }
        else{        
            //////////ENCRYPTION///////////
            encrypt(argv[2], strlen(argv[2]));
        }
    }
    else
        printf("Too many arguements!\n");

    return 0;
}



///////////ENCRYPTION///////////////
void encrypt(char file_name[], int n)
{
    char line[120]; // lines 120 characters each

    char file_name_write[50]={}; //name of file to write
    char type[] = "crp"; //extension to be attatched
    memcpy(file_name_write,file_name,(strlen(file_name)-3)); //Copy the file name with out the file type
    strcat(file_name_write,type);//string catenate function links strings, adds file type

    file_read = fopen(file_name, "r");    // open file function, r for read mode
    file_write = fopen(file_name_write,"w"); // open file, w for writing

    while (!feof(file_read))
    { // while end of file not reached

        fgets(line, 120, file_read); // sends a 120 character string to the char array line
        printf("%s\n", line);        // Testing
        // printf("%c\n",line[0]);//Testing

        // printf("String length:%d\n",strlen(line));//Testing

        for (int i = 0; i < strlen(line); i++)//This loop selects and modifies input stream
        { // check each character of line for encryption needs  //Added int because that's what strleng returns and there was an error
            if ((line[i] == 9) || (line[i] == 13) || (line[i] == 10))
            {
                //don't encrypt tabs ASCII 9 or Carriage Returns ASCII 13 or LF ASCII 10
            }
            else
            {
                line[i] -= 16; // take ASCII code and subtract 16
                if (line[i] < 32)
                    line[i] = (line[i] - 32) + 144; // if resulting character is less than 32, subtract 32, add 144
            }
        }

        for (int i = 0; i < strlen(line); i++)//This loops selects and prints output stream
        {
            if ((line[i] == 13) || (line[i] == 10))
            { // CR LF T not printed as hex
                printf("\n");
                fprintf(file_write, "\n"); // formated print to file
            }
            else if (line[i] == 9)
            {
                // tab is 4 spaces in vs code. save text file from notepad
                printf("%s", "TT");
                fprintf(file_write, "%s", "TT");
            }

            else
            {                                        // Print the rest in hex
                printf("%2X", line[i]);              // Test //Need to use array[] because X is not a string
                fprintf(file_write, "%2X", line[i]); // formated print to file, formated capital hex 2 char, from line
            }
        }
        printf("\n");
        // printf("%s\n",line);//testing
        
    }
    fclose(file_read); // Close files
    fclose(file_write);
}


///////////DECRYPTION///////////////
void decrypt(char file_name[], int n)
{
    char encrypt_line[255]={};
    char decrypt_line[126]={};

    char file_name_write[50]={}; //name of file to write initialize to zero or wack shit happens
    char type[] = "txt"; //extension to be attatched
    memcpy(file_name_write,file_name,(n-3)); //Copy the file name with out the file type
    strcat(file_name_write,type);//string catenate function links strings, adds file type

    file_read = fopen(file_name, "r");    // open file function, r for read mode
    file_write = fopen(file_name_write,"w"); // open file, w for writing

    while(!feof(file_read)){
            
        fgets(encrypt_line,255,file_read); //get string from file
        printf("encrypt line: %s",encrypt_line);//Testing
        //printf("string length: %d\n",strlen(encrypt_line));//Testing

            
        for(int i=0,j=0;i<strlen(encrypt_line);i+=2,j++)//i indexes pairs, j indexes encrypt_line the first of each pair,process characters in pairs
        {        
            if((encrypt_line[i]== 84))//If the first character is T ASCII 84 change to ascii 9 for Tab
            {             
                decrypt_line[j]=9;
                printf("\nTAB\n"); //Testnig                                      
            }
            else if((encrypt_line[i]==9) || (encrypt_line[i]==13) || (encrypt_line[i]==10))
            {
                //printf("NEWLINE \n");//testing
                decrypt_line[j] = encrypt_line[i]; //tabs ASCII 9 or Carriage Returns ASCII 13 or LF ASCII 10 into encryption line without change
            }
            else
            {
                int hex1,hex2;//pair of integers for scanning to
                                    
                sscanf(&encrypt_line[i],"%1X",&hex1);//memory address of encrypt line, scan 1 hex character as int
                //printf("hex1:  In hex %X    In DECIMAL: %d\n",hex1,hex1);//testing print the integer as hex and decimal

                sscanf(&encrypt_line[i+1],"%1X",&hex2);//memory address of encrypt line second of pair, scan 1 hex character as int
                //printf("hex2:  In hex %X    In DECIMAL: %d\n",hex2,hex2);//testing print the integer as hex and decimal

                decrypt_line[j]= hex1 * 16 + hex2;//covert two hex characters to a single integer
                //printf("decrypt line input: %d\n",decrypt_line[j]);//Testing

                if (decrypt_line[j] > 127)
                    decrypt_line[j] = (decrypt_line[j]-144) + 32; //decryption shuffle the ascii table    
                     
            }         
        }
        
        printf("\ndecrypt line input: %s\n",decrypt_line);//Testing
        
        for(int i=0;i<strlen(decrypt_line);i++)
        {
            fprintf(file_write, "%c",decrypt_line[i]);    
        }
    
    }
    fclose(file_read);//close files
    fclose(file_write);
    
}



