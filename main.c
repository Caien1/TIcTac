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

    TURN turn = CROSS;



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
                printf("cell [x,y] %d,%d \n",(int)pos.x,(int)pos.y);


                /*-------------------TURN SWITCHER---------------------------*/

                    if(turn == CIRCLE){
                      turn =CROSS;
                    }else{
                        turn = CIRCLE;
                    }

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




        /*-------------------Draw Circle----------------------------*/

            // if(turn == CIRCLE){
            //     DrawCircle(pos.x*cellWidth +cellWidth/2 ,pos.y*cellHeight + cellWidth/2 ,cellWidth/2-5,RAYWHITE);
            //     DrawCircle(pos.x*cellWidth +cellWidth/2 ,pos.y*cellHeight + cellWidth/2 ,cellWidth/2 -15,BLACK);
            // }
        /*___________________Draw Circle End______________________________*/



        /*-----------------------Draw Cross------------------------------------*/
            // if(turn == CROSS){
            //     DrawLineEx((Vector2){pos.x*cellWidth, pos.y*cellHeight}, (Vector2){pos.x*cellWidth+cellWidth ,pos.y*cellHeight+cellHeight},6,RAYWHITE);
            //     DrawLineEx((Vector2){pos.x*cellWidth + cellWidth  , pos.y * cellHeight}, (Vector2){pos.x*cellWidth   ,pos.y*cellHeight +cellHeight},6,RAYWHITE);
            // }
                   
        /*______________________Draw Cross End_____________________________*/
         ClearBackground(defaultBgColor);


        EndDrawing();
    }

    //--------------------------------------------------------------------------------------
    CloseWindow();        
    //--------------------------
}

