#include<stdlib.h>
#include <stdio.h>
#include "move.h"



int move_left(char** keyPadArr, int *pRowPtr, int *pColPtr)
{
  int exit;
  if (keyPadArr[*pRowPtr][*pColPtr - 1] == ' ')
  {
    keyPadArr[*pRowPtr][*pColPtr] = ' ';
    *pColPtr = (*pColPtr - 1);
    keyPadArr[*pRowPtr][*pColPtr] = '^';
    exit = 0;
  }

  return exit;
}