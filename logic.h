#include <assert.h>
#include <malloc.h>
#include <raylib.h>

/*______________________DATA SECTION___________________*/
typedef struct grid
{
    int rowSize;
    int colSize;
    int *cells;
} Grid;

typedef enum turn
{
        CROSS,CIRCLE
}TURN;
/*______________________DATA SECTION ENDS___________________*/

/*______________________COLOR SECTION_______________________*/
Color defaultBgColor = {0,0,0,0};
Color defaultGridColor = {255,255,255};


/*______________________COLOR SECTION_______________________*/

void generateGrid(Grid* gridPtr){

    int gridSize =  gridPtr->rowSize * gridPtr->colSize;
    gridPtr->cells = (int *)malloc( gridSize * sizeof(int));
    assert(gridPtr->cells!=NULL);

}

void freeGrid(Grid* gridPtr){
    free(gridPtr->cells);
}

int getPosition(int x,int y, Grid* gridPtr){
    int cols = gridPtr->colSize;
    int rows = gridPtr->rowSize;

    int position = rows * y + x;

    return position; 
}

Vector2 getCordinates(int position,Grid* gridPtr){
    int cols = gridPtr->colSize;
    int rows = gridPtr->rowSize;
    Vector2 pos = {(float)(position%cols),(float)(position/rows)};
    return pos;    
}








