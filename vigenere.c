/******************************************************************
*   Author: Christopher Catlin                                    *
*   Date: 14/08/2014                                              *
*   Program: vigenere                                              *
*   Description: Takes a key from the user at the command line,   *
*                and applies a vigenere cipher to the string the  *
*                user gives.                                      *
******************************************************************/

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // Checking that only one command line argument has been passed
    // by the user
    if (argc != 2)
    {
        printf("Error, usage: ./vigenere KEYWORD.\n");
        return 1;
    }
    else
    {
        // Make an array for the converted keyword to keynumber
        int key[strlen(argv[1])];
        
        // Convert chars in keyword to numbers
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
                        
            if (isalnum(argv[1][i]))
            {
                if (isupper(argv[1][i]))
                {
                    key[i] = argv[1][i] - 65;
                   
                }
                else if (islower(argv[1][i]))
                
                {
                    key[i] = argv[1][i] - 96;
                  
                }
                else
                {
                    key[i] = argv[1][i];
                    
                }
            }
            else
            {
                // Returns error if special charaters are used
                printf("Error: keyword may be alphanumetric only.\n");
                return 1;
            }
            
       }
       printf("\n");
       
       // Getting the string to be encrypted
       printf("Enter text for encryption:\n");
       string plain = GetString();
       
       // Creat an variable to use modulo
       int k = strlen(argv[1]);
       
       for (int i = 0, n = strlen(plain); i < n; i++)
        {
            // Encrypts the char if it is a letter
            if (isalpha(plain[i]))
            {
                if (isupper(plain[i]))
                {
                    printf("%c",(((plain[i] - 65) + key[i % k]) % 26)+ 65);
                    
                }
                else
                {
                    printf("%c",(((plain[i] - 97) + key[i % k]) % 26)+ 97);
                    
                }
            }    
            else
            {
                // if not a letter prints unencrytped
                printf("%c", plain[i]);
            }
        }
    }
    printf("\n");
}
