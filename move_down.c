#include<stdlib.h>
#include <stdio.h>
#include "move.h"


int move_down(char** keyPadArr, int *pRowPtr, int *pColPtr)
{
  int exit;
  if (*pRowPtr != 7)
  {
      if (keyPadArr[*pRowPtr + 2][*pColPtr] == ' ')
    {
      keyPadArr[*pRowPtr][*pColPtr] = ' ';
      *pRowPtr = (*pRowPtr + 2);
      keyPadArr[*pRowPtr][*pColPtr] = '^';
      exit = 0;
    }
  } 

  return exit;
}
