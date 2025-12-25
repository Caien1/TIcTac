#include <raylib.h>
#include <stdio.h>
#include "logic.h"

#define HEIGHT 800
#define WIDTH 800
#define COLS 10
#define ROWS 10



int main(){


    
    const int screenWidth = WIDTH;
    const int screenHeight = HEIGHT;
 
 
    Grid grid;
    grid.colSize=COLS;
    grid.rowSize=ROWS;

    Grid buffer;
    buffer.colSize=COLS;
    buffer.rowSize=ROWS;

    int cellWidth = WIDTH/COLS;
    int cellHeight = HEIGHT/ROWS;


    Vector2 coords;




    /*-------------Allocations Section Starts---------------*/
    generateGrid(&grid);
    generateGrid(&buffer);
    /*_______________Allocation Section End______________________*/




    InitWindow(screenWidth, screenHeight, "TickTackToe");
    SetTargetFPS(60); 

    while (!WindowShouldClose())    
    {
        /*-------------------Input Section-----------------------*/
    
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                coords = GetMousePosition();
                int position = getPosition((int)coords.x/cellWidth,(int)coords.y/cellWidth,&grid);
                flipBit(grid.cells, position);
            }
        
        /*___________________Input Section END_______________________*/
        /*-------------------Compute Next life cycle-----------------*/



        /*___________________COmpute Nex Life Cycle END______________*/

        
        BeginDrawing();



        /*-----------------------Draw Grid lines -----------------------*/
        
            for(int i=0; i<grid.colSize; i++){
                DrawLine(i*cellWidth,0,i*cellWidth,screenHeight,RAYWHITE);
            }
            
            for(int i=0; i<grid.rowSize; i++){
                DrawLine(0,i*cellHeight,screenWidth,i*cellHeight,RAYWHITE);
            }
            
        /*___________________Draw grid lines  END_______________________*/

       
        /*---------------------Draw Cells ---------------------------------*/
        for(int i = 0; i < grid.colSize*grid.rowSize ; i++){
            if(1){
                Vector2 pos = getCordinates(i,&grid);
                // DrawRectangle(pos.x*cellWidth,pos.y*cellHeight,cellWidth,cellHeight,RAYWHITE);
                char * num ;
                sprintf(num,"%d",i);
                DrawText(num,pos.x*cellWidth+ cellWidth/2,pos.y*cellHeight + cellHeight/2,30,RAYWHITE);

            }
        }

        /*__________________Draw cells end_________________________________*/


           
        ClearBackground(defaultBgColor);


        EndDrawing();
    }

    //--------------------------------------------------------------------------------------

    CloseWindow(); 

    /*----------------------De-Allocating stuff--------------*/
    freeGrid(&grid);
    /*_______________________________________________________*/
}

