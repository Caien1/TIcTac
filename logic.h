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

int getPosition(int i,int j, Grid* gridPtr){
    int cols = gridPtr->colSize;
    int rows = gridPtr->rowSize;


    return 0; 
}






