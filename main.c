#include <stdio.h>
#include <stdlib.h>
#include "move.h"
#include "printkeypad.h"
#include <string.h>
#include <time.h>
#include "terminal.h"
#include "clear.h"
void concatenate(char *str1, char *str2);

/*
    Creating 2d Array to store the Interface
*/

int main(int argc, char* argv[])
{
    char str1[20];
    char str2[20];
    int cRow, cCol;
    int* cursorRowPtr = &cRow;
    int* cursorColPtr = &cCol;
    char input;
    char screenVal = '0';
    char userInput;
    int exit = 0;
    int i = 0;
    int count = 1; 
    char **keyPadArr;
    int col, row;
    row = 8;
    col = 3;

    srand(time(NULL));  /* generating random numbers */

    if (argc == 1) /* checking if argument provided */
    {
        printf("%s","Please enter an argument! \n");
        exit = 1;
    }

    /*
        Creating the 2d array to store map via malloc()
    */

    keyPadArr = (char**)malloc((row) * sizeof(char*));

    for(i = 0 ; i < (row + 1) ; i++)
    {
        keyPadArr[i] = (char *) malloc((col) * sizeof(char));
    }



    if (1+rand()%2 == 1)
    {
        /*
            Assigning Interface 1 to array
        */

        keyPadArr[0][0] = '+'; keyPadArr[0][1] = '0'; keyPadArr[0][2] = '=';
        keyPadArr[1][0] = '^'; keyPadArr[1][1] = ' '; keyPadArr[1][2] = ' ';
        keyPadArr[2][0] = '7'; keyPadArr[2][1] = '8'; keyPadArr[2][2] = '9';
        keyPadArr[3][0] = ' '; keyPadArr[3][1] = ' '; keyPadArr[3][2] = ' ';
        keyPadArr[4][0] = '4'; keyPadArr[4][1] = '5'; keyPadArr[4][2] = '6';
        keyPadArr[5][0] = ' '; keyPadArr[5][1] = ' '; keyPadArr[5][2] = ' ';
        keyPadArr[6][0] = '1'; keyPadArr[6][1] = '2'; keyPadArr[6][2] = '3';
        keyPadArr[7][0] = ' '; keyPadArr[7][1] = ' '; keyPadArr[7][2] = ' ';

        cRow = 1;
        cCol = 0;
    }
    else
    {
        /*
            Assigning Interface 2 to array
        */

        keyPadArr[0][0] = '1'; keyPadArr[0][1] = '2'; keyPadArr[0][2] = '3';
        keyPadArr[1][0] = '^'; keyPadArr[1][1] = ' '; keyPadArr[1][2] = ' ';
        keyPadArr[2][0] = '4'; keyPadArr[2][1] = '5'; keyPadArr[2][2] = '6';
        keyPadArr[3][0] = ' '; keyPadArr[3][1] = ' '; keyPadArr[3][2] = ' ';
        keyPadArr[4][0] = '7'; keyPadArr[4][1] = '8'; keyPadArr[4][2] = '9';
        keyPadArr[5][0] = ' '; keyPadArr[5][1] = ' '; keyPadArr[5][2] = ' ';
        keyPadArr[6][0] = '+'; keyPadArr[6][1] = '0'; keyPadArr[6][2] = '=';
        keyPadArr[7][0] = ' '; keyPadArr[7][1] = ' '; keyPadArr[7][2] = ' ';

        cRow = 1;
        cCol = 0;
    }


/*
    Printing the Interface
*/



    while (exit == 0)
    {
        clear();
            /*
            Printing the Interface
            */
        printKeyPad(keyPadArr, screenVal);
        disableBuffer();
        scanf(" %c", &userInput);
        if (userInput == 'a')
            {
             move_left(keyPadArr, cursorRowPtr, cursorColPtr);
            }

        else if (userInput == 'd')
            {
             move_right(keyPadArr, cursorRowPtr, cursorColPtr);
            }

        else if (userInput == 'w')
            {
             move_up(keyPadArr, cursorRowPtr, cursorColPtr);
            }
          
        else if (userInput == 's')
           { 
            move_down(keyPadArr, cursorRowPtr, cursorColPtr);
           }
        else if (userInput == 'e')
        {
            input = keyPadArr[*cursorRowPtr - 1][*cursorColPtr];
            switch (input)
            {
                case '+': /* concat and add to linked list */

                    count = 0;
                    break;
                
                case '=': /* print to file from file and end program */
                    exit = 1;
                    break;

                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':

                    if (count <= 7)
                    {
                        
                        screenVal = input;
                        
                        str2[count] = input;
                        if (count >= 2)
                        {
                            concatenate(str1, str2);
                        }
                        
                        count++;
                    }printf("%s \n", str1);
                    break;

                default:
                    /*default method stub*/
                    break;
            }
            
        }


    }

    for(i=0; i < (row)+1; i++)  /* FREEING THE MALLOCED ARRAYS*/
        {
            free(keyPadArr[i]);
            keyPadArr[i] = NULL;
        }
 
    free(keyPadArr);

    enableBuffer();

return 0;
    
}


void concatenate(char *str1, char *str2)
{
    int i = strlen(str1), j = 0;

    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0';  /* declaring the end of the string */
}



