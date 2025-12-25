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

/*______________________COLOR SECTION_______________________*/

void generateGrid(Grid* gridPtr){

    int gridSize =  gridPtr->rowSize * gridPtr->colSize;
    gridPtr->cells = (bool *)calloc( gridSize,sizeof(bool));
    assert(gridPtr->cells!=NULL);
}

void freeGrid(Grid* gridPtr){
    free(gridPtr->cells);
}

int getPosition(int x,int y, Grid* gridPtr){
    //requires normalised inputs ie x/cell width
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

void flipBit(bool* arr, int position){
        arr[position]= !arr[position];
}




int aliveNeighbourSum(int position , Grid *gridPtr){
    int colsize = gridPtr->colSize;
    int rowsize = gridPtr->rowSize;
    bool * arr = gridPtr->cells;
    
    int aboveIndex = position - rowsize;
    int belowIndex = position + colsize;
    int neighbourIndices[] = {
                             aboveIndex-1,aboveIndex,aboveIndex+1,
                                 position - 1, position+1
                             ,belowIndex-1,belowIndex,belowIndex+1
                             };
    Vector2 coords = getCordinates(position,gridPtr);
    int sum = 0;

    /*  
    if cell is a boundary cell 
        less that colSize ( for top boundary)
        perfectly div by row size

    */
    //corner cases
    if(coords.x <= 0 && coords.y<=0){
       sum =   arr[position+1]+arr[belowIndex]+arr[belowIndex+1];
       return sum;
    }
    if(coords.x <= 0 && coords.y >=colsize-1 ){
        sum =   arr[position-1]+arr[belowIndex]+arr[belowIndex-1];
        return sum;
    }
    if(coords.x >= rowsize-1 && coords.y <=0 ){
        sum =   arr[aboveIndex]+arr[aboveIndex+1]+arr[position+1];
        return sum;
    }
    if(coords.x >= rowsize-1 && coords.y >= colsize-1 ){
        sum =   arr[aboveIndex-1]+arr[aboveIndex]+arr[position-1];
        return sum;

    }

    //Edege case

     if(coords.x <= 0 ){
       sum =    arr[position+1]+
                arr[belowIndex]+ arr[belowIndex+1]+
                arr[aboveIndex]+ arr[aboveIndex+1];
       return sum;
    }

    if(coords.y <= 0){
        sum =   arr[position-1]+arr[position+1]+
                arr[belowIndex-1]+ arr[belowIndex]+ arr[belowIndex+1];
        return sum;

    }
    if( coords.y >=colsize-1){
         sum =   arr[position-1]+arr[position+1]+
                arr[aboveIndex-1]+ arr[aboveIndex]+ arr[aboveIndex+1];
        return sum;

    }
    if( coords.x >= rowsize-1){
           sum =    arr[position-1]+
                arr[belowIndex]+ arr[belowIndex-1]+
                arr[aboveIndex]+ arr[aboveIndex-1];
            return sum;
    }





    //if cell not in corner or edege
    
   


    for(int i=0;i< 8;i++){
        sum+= arr[neighbourIndices[i]];
    }

    return sum;

}






