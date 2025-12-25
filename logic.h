#pragma once
#include <assert.h>
#include <stdlib.h>
#include <raylib.h>

/*______________________DATA SECTION___________________*/
typedef struct grid
{
    int rowSize;
    int colSize;
    bool *cells;
} Grid;

/*______________________DATA SECTION ENDS___________________*/

/*______________________COLOR SECTION_______________________*/
Color defaultBgColor = {0,0,0,0};
Color defaultGridColor = {255,255,255};
Color colorTable[] = {  
    {255,0,0,255},
    {0,255,0,255},
    {0,0,255,255},
    MAGENTA,

   };

/*______________________COLOR SECTION END_______________________*/


void generateGrid(Grid* gridPtr);
void freeGrid(Grid* gridPtr);
int getPosition(int x,int y, Grid* gridPtr);
Vector2 getCordinates(int position,Grid* gridPtr);
void flipBit(bool* arr, int position);
bool isCornerCell(int position, Grid* gridPtr);
bool isEdegeCell(int position, Grid* gridPtr);
int cornerCellNeighbourSum(int position,Grid* gridPtr,int belowIndex, int aboveIndex,bool*arr);
int edegeCellNeighbourSum(int position,Grid* gridPtr,int belowIndex, int aboveIndex,bool*arr);
int aliveNeighbourSum(int position , Grid* gridPtr);