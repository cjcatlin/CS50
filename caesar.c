/******************************************************************
*   Author: Christopher Catlin                                    *  
*   Date: 14/08/2014                                              *                  
*   Program: caesar                                               *
*   Description: Takes a key from the user at the command line,   *
*                and applies a caesar cipher to the string the    *
*                user gives.                                      *
******************************************************************/                 

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
// check to see if user has provided a single command line argument
if (argc != 2)
{
    // tells the user what to do
    printf("Error, usage: ./caesar.c KEY.\n");
    return 1;
}
else
{

    // convert the key, k, from string to int
    int key = atoi(argv[1]);

    // get plain text fomr user
    printf("Enter text to be encrypted.\n");
    string plain = GetString();
    
    // encytp the message
    for (int i = 0, n = strlen(plain); i < n; i++)
    {   
        // checks if charater is a letter of the alphabet
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                // converts A to 0 then back to ascii after key applied
                printf("%c", (((plain[i] - 'A') + key) % 26) + 'A');
            }    
            else
            {
                // converts a to 0 then back to ascii after key applied
                printf("%c", (((plain[i] - 'a') + key) % 26) + 'a');
            }
        }
        else
        {
            // if not letter prints uchanged
            printf("%c", plain[i]);
        }
          
    }
    return 0;
}
}
