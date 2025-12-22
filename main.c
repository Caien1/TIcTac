#include <raylib.h>
#include <stdio.h>
#include "logic.h"

#define HEIGHT 800
#define WIDTH 800
#define COLS 100
#define ROWS 100



int main(){


    
    const int screenWidth = WIDTH;
    const int screenHeight = HEIGHT;
 
 
    Grid grid;
    grid.colSize=COLS;
    grid.rowSize=ROWS;

    int cellWidth = WIDTH/COLS;
    int cellHeight = HEIGHT/ROWS;


    Vector2 pos;




    /*-------------Allocations Section Starts---------------*/
    generateGrid(&grid);
    /*_______________Allocation Section End______________________*/




    InitWindow(screenWidth, screenHeight, "TickTackToe");
    SetTargetFPS(60); 

    while (!WindowShouldClose())    
    {
        /*-------------------Input Section-----------------------*/
    
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                pos = GetMousePosition();
                pos.x = (int)pos.x/cellWidth;
                pos.y = (int)pos.y/cellHeight;

                int x = (int)pos.x;
                int y = (int)pos.y;
                int position =  getPosition(x,y,&grid);
                Vector2 cord = getCordinates(position,&grid);
                printf("cell [x,y] %d,%d, position %d , coords [] %lf,%lf\n",x ,y ,position,cord.x,cord.y);


                /*-------------------TURN SWITCHER---------------------------*/

              
                /*___________________ TURN SWITCHER END_______________________*/



            }
        
        /*___________________Input Section END_______________________*/

                BeginDrawing();



        /*-----------------Draw Grid lines -----------------------*/
        
            for(int i=0; i<grid.colSize; i++){
                DrawLine(i*cellWidth,0,i*cellWidth,screenHeight,RAYWHITE);
            }
            
            for(int i=0; i<grid.rowSize; i++){
                DrawLine(0,i*cellHeight,screenWidth,i*cellHeight,RAYWHITE);
            }
            
        /*___________________Draw grid lines  END_______________________*/

       
        
        
         DrawRectangle(pos.x*cellWidth,pos.y*cellHeight,cellWidth,cellHeight,RAYWHITE);




           
         ClearBackground(defaultBgColor);


        EndDrawing();
    }

    //--------------------------------------------------------------------------------------

    CloseWindow(); 
    freeGrid(&grid);
    //--------------------------
}

