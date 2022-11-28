#include <stdio.h>
#include <stdlib.h>
#include "printkeypad.h"



void printKeyPad(char** keyPadArr, char input)
{
    int j,i;
    /*
        Printing the Screen
    */
    printf("%s","-------------");
    printf("\n");
    printf("%s","|         ");
    printf("%c", input);
    printf("%s"," | ");
    printf("\n");
    printf("%s","-------------");
    printf("\n");

    
    /*
        Printing the Keypad
    */
    for (j = 0; j < 8; j++)
    {
        for (i = 0; i < 3; i++)
        {
         printf("%c", keyPadArr[j][i]);
         printf(" ");
        }
        printf("\n");
    }
}