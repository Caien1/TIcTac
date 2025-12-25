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
 
 
    Grid grid = {ROWS,COLS,NULL};
    Grid buffer={ROWS,COLS,NULL};

    int cellWidth = WIDTH/COLS;
    int cellHeight = HEIGHT/ROWS;

    bool running = true;

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
                flipBit(buffer.cells, position);
            }


            if(IsKeyPressed(KEY_E)){
                running = !running;
                printf("running %d\n",running);
            }
        
        /*__________________Input Section END_______________________*/


        /*-------------------Compute Next life cycle-----------------*/
    
            

        /*___________________COmpute Nex Life Cycle END______________*/

     
    /*------------------------Just render here--------------------------*/
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

            if(running){
             int sum = aliveNeighbourSum(i,&grid);
                 if(sum<2 || sum>3){
                    buffer.cells[i]=0;
                 }else{
                    buffer.cells[i]=1;
                 }
                
                }


            if(grid.cells[i]==1){
                Vector2 pos = getCordinates(i,&grid);
                 DrawRectangle(pos.x*cellWidth,pos.y*cellHeight,cellWidth,cellHeight,RAYWHITE);

            }
        }
        WaitTime(3);

        /*__________________Draw cells end_________________________________*/


           
        ClearBackground(defaultBgColor);


        EndDrawing();

    /*________________________Render HERE ENds_____________________________________*/    

      for(int i =0; i< grid.rowSize* grid.colSize;i++){
        grid.cells[i]=buffer.cells[i];
      }

    }


    CloseWindow(); 

    /*----------------------De-Allocating stuff--------------*/
    freeGrid(&grid.cells);
    freeGrid(&buffer.cells);
    /*_______________________________________________________*/
}

