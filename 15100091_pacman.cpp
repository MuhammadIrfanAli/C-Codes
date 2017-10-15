#include<ncurses.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
void drawBound();
void drawMaze();
void distFood();

int main()

{
initscr();
raw();
curs_set(0); //no curser visible.
keypad(stdscr, TRUE);
noecho();
int rows; int cols; float i=0; int value; int bug; int animate=0;
int startL=1; int startR=1; int startU=1; int startD=1;
getmaxyx(stdscr,rows,cols);
int dirL=0;int dirR=0;int dirU=0;int dirD=0;
int posX=cols/2;
int posY = rows/2;
int posGX; int posGY;int randCol;char stopWhile1;
wtimeout(stdscr,80);
drawBound();
drawMaze();
distFood();

// integers.
int startGL=1; int startGR=1; int startGU=1; int startGD=1;
int startGL1=1; int startGR1=1; int startGU1=1; int startGD1=1;
int startGL2=1; int startGR2=1; int startGU2=1; int startGD2=1;
int posGX0; int posGX1; int posGX2;
int posGY0; int posGY1; int posGY2; int last=0;
//int posFX; int posFY; int foodCreate=1; char foodPlace;/
//int Add; int foodApp;
 int score=0;

 				do {
                                    srand ( time(NULL) );
                                    posGX0 = (rand() % cols);
                                    posGY0 = (rand() % rows);
                                    char stopWhile1 = mvinch(posGX0,posGY0);
                }                   while (stopWhile1=='!' || stopWhile1=='$');

				 do {
                                    srand ( time(NULL) );
                                    posGX1 = (rand() % cols);
                                    posGY1 = (rand() % rows);
                                    char stopWhile2 = mvinch(posGX1,posGY1);
                }                   while (stopWhile1=='!' || stopWhile1=='$');

				 do {
                                    srand ( time(NULL) );
                                    posGX2 = (rand() % cols);
                                    posGY2 = (rand() % rows);
                                    char stopWhile1 = mvinch(posGX2,posGY2);
                }                   while (stopWhile1=='!' || stopWhile1=='$');



while(i>=0){

srand( time(NULL) );

int dir=getch();
i = i+0.1;

//---------------------------------------------------------------------------------------------------------------

																//		GHOST PART.
// collision detection for Ghost.
		 //for 1st ghost
                char obsGL = mvinch(posGY0,--posGX0);
                posGX0++;
                char obsGR = mvinch(posGY0,++posGX0);
                posGX0--;
                char obsGU = mvinch(--posGY0,posGX0);
                posGY0++;
                char obsGD = mvinch(++posGY0,posGX0);
                posGY0--;
				
		// for 2nd ghost.
		char obsGL1 = mvinch(posGY1,--posGX1);
                posGX1++;
                char obsGR1 = mvinch(posGY1,++posGX1);
                posGX1--;
                char obsGU1 = mvinch(--posGY1,posGX1);
                posGY1++;
                char obsGD1 = mvinch(++posGY1,posGX1);
                posGY1--;
		 
		//for 3rd ghost
                char obsGL2 = mvinch(posGY2,--posGX2);
                posGX2++;
                char obsGR2 = mvinch(posGY2,++posGX2);
                posGX2--;
                char obsGU2 = mvinch(--posGY2,posGX2);
                posGY2++;
                char obsGD2 = mvinch(++posGY2,posGX2);
                posGY2--;



// Ghost should not eat Pacman's food.
                // If GHOST faces an obstacle.
                if (obsGL == '|'){
                startGL=0;
                }

                if (obsGR == '|'){
                startGR = 0;
                }

                if (obsGU == '|'){
                startGU=0;
                }

                if (obsGD=='|'){
                startGD=0;
                }
		
		// for 2nd ghost.
                if (obsGL1 == '|'){
                startGL1=0;
                }

                if (obsGR1 == '|'){
                startGR1 = 0;
                }

                if (obsGU1 == '|'){
                startGU1=0;
                }

                if (obsGD1=='|'){
                startGD1=0;
                }
		 
		// If GHOST3 faces an obstacle.
                if (obsGL2 == '|'){
                startGL2=0;
                }

                if (obsGR2 == '|'){
                startGR2 = 0;
                }

                if (obsGU2 == '|'){
                startGU2=0;
                }

                if (obsGD2=='|'){
                startGD2=0;
                }

// for LEFT animation of GHOST1.


                	if(startGL!=0){ // checks whether obstacle is present or not. If not, runs.
                 			if (obsGL != '$'){
                        	mvprintw(posGY0,posGX0," ");
                        	mvprintw(posGY0,posGX0,"G");
                        	}

                    		else if (obsGL == '$'){ // if food predent up.
                   				mvprintw(posGY0,posGX0," ");
                                mvprintw(posGY0,--posGX0,"G");
                    			mvprintw(posGY0,posGX0,"$");
                                mvprintw(posGY0,--posGX0,"G");
                                
                    		}
                    	}
// For UP animation od Ghost1.

               		else if (startGU!=0){
				if (obsGU != '$'){// && foodEat != 1) { //to prevent food eaten by ghosts.
                			mvprintw(posGY0,posGX0," ");
                               		mvprintw(--posGY0,posGX0,"G");
                		}
                		else if (obsGU == '$'){ // if food predent up.
                			mvprintw(posGY0,posGX0," ");
                            mvprintw(--posGY0,posGX0,"G");
               				mvprintw(posGY0,posGX0,"$"); 
                                	mvprintw(--posGY0,posGX0,"G");
               			}
               		}
// for Downward animation of ghost1.


			else if (startGD!=0){
			 	if (obsGD != '$'){// && foodEat != 1) { //to prevent food eaten by ghosts.
                        		mvprintw(posGY0,posGX0," ");
                                mvprintw(++posGY0,posGX0,"G");
                    	}
                    	
			else if (obsGD == '$'){ // if food predent up.
                    	mvprintw(posGY0,posGX0," ");
                        mvprintw(++posGY0,posGX0,"G");
                    	mvprintw(posGY0,posGX0,"$");
                        mvprintw(++posGY0,posGX0,"G");
                    	}
                   } 

// for right animation of ghost1.

                else if (startGR!=0){
		 	if (obsGR != '$' ){//to prevent food eaten by ghosts.
                        		mvprintw(posGY0,posGX0," ");
                                        mvprintw(posGY0,++posGX0,"G");
                    	}
                    	else if (obsGR == '$'){ // if food predent up.

                    		mvprintw(posGY0,posGX0," ");
                                mvprintw(posGY0,++posGX0,"G");
                    		mvprintw(posGY0,posGX0,"$");
                           	mvprintw(posGY0,++posGX0,"G");
                    	}
                }

//----------------------------------------------------------------------------------------
									//for 2nd GHOST.

// for LEFT animation of GHOST2.


                     if(startGL1!=0){ // checks whether obstacle is present or not. If not, runs.
                                if (obsGL1 != '$'){
                                        mvprintw(posGY1,posGX1," ");
                                        mvprintw(posGY1,posGX1,"G");
                                }

                                        else if (obsGL1 == '$'){ // if food predent up.
                                mvprintw(posGY1,posGX1," ");
                                mvprintw(posGY1,--posGX1,"G");
                                mvprintw(posGY1,posGX1,"$");
                                mvprintw(posGY1,--posGX1,"G");
                                        }

                     }
// For UP animation od Ghost2.

                        else if (startGU1!=0){
                                if (obsGU1 != '$'){// && foodEat != 1) { //to prevent food eaten by ghosts.
                                        mvprintw(posGY1,posGX1," ");
                                        mvprintw(--posGY1,posGX1,"G");
                                }
                                else if (obsGU1 == '$'){ // if food predent up.
                                        mvprintw(posGY1,posGX1," ");
                                        mvprintw(--posGY1,posGX1,"G");
                                        mvprintw(posGY1,posGX1,"$");
                                        mvprintw(--posGY1,posGX1,"G");
                                }
                        }

			
// for Downward animation of ghost2.


                        else if (startGD1!=0){
                                if (obsGD1 != '$'){// && foodEat != 1) { //to prevent food eaten by ghosts.
                                        mvprintw(posGY1,posGX1," ");
                                        mvprintw(++posGY1,posGX1,"G");
                        }

                        else if (obsGD1 == '$'){ // if food predent up.
                        mvprintw(posGY1,posGX1," ");
                        mvprintw(++posGY1,posGX1,"G");
                        mvprintw(posGY1,posGX1,"$");
                        mvprintw(++posGY1,posGX1,"G");
                        }
                   }

// for right animation of ghost2.

                else if (startGR1!=0){
                        if (obsGR1 != '$' ){//to prevent food eaten by ghosts.
                                        mvprintw(posGY1,posGX1," ");
                                        mvprintw(posGY1,++posGX1,"G");
                        }
                        else if (obsGR1 == '$'){ // if food predent up.

                                mvprintw(posGY1,posGX1," ");
                                mvprintw(posGY1,++posGX1,"G");
                                mvprintw(posGY1,posGX1,"$");
                                mvprintw(posGY1,++posGX1,"G");
                        }
                }

//-------------------------------------------------------------------------------------
					//GHOST3
// for LEFT animation of GHOST3.


                    if(startGL2!=0){ // checks whether obstacle is present or not. If not, runs.
                               if (obsGL2 != '$'){
                                        mvprintw(posGY2,posGX2," ");
                                        mvprintw(posGY2,posGX2,"G");
                               }

                                        else if (obsGL2 == '$'){ // if food predent up.
                                        mvprintw(posGY2,posGX2," ");
                                        mvprintw(posGY2,--posGX2,"G");
                                        mvprintw(posGY2,posGX2,"$");
                                        mvprintw(posGY2,--posGX2,"G");
                                        }
                    }
// For UP animation od Ghost3.

                        else if (startGU2!=0){
                                if (obsGU2 != '$'){// && foodEat != 1) { //to prevent food eaten by ghosts.
                                        mvprintw(posGY2,posGX2," ");
                                        mvprintw(--posGY2,posGX2,"G");
                                }
                                else if (obsGU2 == '$'){ // if food predent up.
                                        mvprintw(posGY2,posGX2," ");
                                        mvprintw(--posGY2,posGX2,"G");
                                        mvprintw(posGY2,posGX2,"$");
                                        mvprintw(--posGY2,posGX2,"G");
                                }
                        }


// for Downward animation of ghost3.


                        else if (startGD2!=0){
                                if (obsGD2 != '$'){// && foodEat != 1) { //to prevent food eaten by ghosts.
                                        mvprintw(posGY2,posGX2," ");
                                        mvprintw(++posGY2,posGX2,"G");
                        }

                        else if (obsGD2 == '$'){ // if food predent up.
                        mvprintw(posGY2,posGX2," ");
                        mvprintw(++posGY2,posGX2,"G");
                        mvprintw(posGY2,posGX2,"$");
                        mvprintw(++posGY2,posGX2,"G");
                        }
                   }

// for right animation of ghost3.

                else if (startGR2!=0){
                        if (obsGR2 != '$' ){//to prevent food eaten by ghosts.
                                        mvprintw(posGY2,posGX2," ");
                                        mvprintw(posGY2,++posGX2,"G");
                        }
                        else if (obsGR2 == '$'){ // if food predent up.

                                mvprintw(posGY2,posGX2," ");
                                mvprintw(posGY2,++posGX2,"G");
                                mvprintw(posGY2,posGX2,"$");
                                mvprintw(posGY2,++posGX2,"G");
                        }
                }

//---------------------------------------------------------------------------------------------------
// Random number defined for the movemnt of first ghost.

int randPos = (rand() % 4);
						if (randPos==3){
							startGL=1;
							startGU=0;
							startGD=0;
							startGR=0;
								startGL1=0;
                                                        	startGU1=1;
                                                        	startGD1=0;
                                                        	startGR1=0;
							startGL2=0;
                                                        startGU2=0;
                                                        startGD2=0;
                                                        startGR2=1;
						}
						if (randPos==2){
							startGU=1;
							startGR=0;
							startGL=0;
							startGD=0;
								startGL1=0;
                                                        	startGU1=0;
                                                        	startGD1=1;
                                                        	startGR1=0;
							startGL2=0;
                                                        startGU2=0;
                                                        startGD2=1;
                                                        startGR2=0;
						}
						if (randPos==1){
							startGR=1;
							startGU=0;
							startGL=0;
							startGD=0;
 								startGL1=0;
                                                        	startGU1=0;
                                                       		startGD1=0;
                                                        	startGR1=1;
							startGL2=0;
                                                        startGU2=1;
                                                        startGD2=0;
                                                        startGR2=0;
						}

						if (randPos==0){
							startGD=1;
							startGU=0;
							startGL=0;
							startGR=0;
							 	startGL1=1;
                                                        	startGU1=0;
                                                        	startGD1=0;
                                                        	startGR1=0;
							startGL2=1;
                                                        startGU2=0;
                                                        startGD2=0;
                                                        startGR2=0;
						}

						//	<GHOST PART ENDS>
//------------------------------------------------------------------------------------------------------------------------

// PACMAN PART STARTS.

				 //      Collision Detection for Pacman.

                char stopL = mvinch(posY,--posX);
                posX++;
                char stopR = mvinch(posY,++posX);
                posX--;
                char stopU = mvinch(--posY,posX);
                posY++;
                char stopD = mvinch(++posY,posX);
                posY--;

                // implementation after collision detected.

                if (stopL=='|'){
                dirL=0;
                startL=0;
                mvprintw(posY,posX,">");
                }
		 		if (stopR=='|'){
                dirR=0;
                startR=0;
                mvprintw(posY,posX,"<");
                }

                if (stopU=='|'){
                dirU=0;
                startU=0;
                mvprintw(posY,posX,"v");
                }
                if (stopD=='|'){
                dirD=0;
                startD=0;
                mvprintw(posY,posX,"^"); 
                }
               /* TRY to make animation better.
                if (stopU==0 && dirU==119){
                mvprintw(posY,posX,"v");
                }
                if (stopD==0 && dirD==115){
                mvprintw(posY,posX,"^");
                }
                if (stopL==0 && dirL==97){
                mvprintw(posY,posX,"<");
                }
                if (stopR==0 && dirR==100){
                mvprintw(posY,posX,">");
                }
                */                                                                               

                
                // extra checks to make it better the way it ought to be.
                
                if (dirD==0 && dirL!=0 && dirR!=0){ // if moving down and not surrounded by obstacles.
                	startL=1;
                	startR=1;
                	startU=1;
                }
                if (dirU==0 && dirL!=0 && dirR!=0){ // if moving up and not surrounded by obstacles.
                	startL=1;
                	startR=1;
                	startD=1;
                }
		 		if (dirR==0 && dirU!=0 && dirD!=0){ // if moving right and not surrounded by obstacles.
                	startU=1;
                	startD=1;
                	startL=1;
                }
		 		if (dirL==0 && dirU!=0 && dirD!=0){ // if moving left and not surrounded by obstacles.
                	startU=1;
                	startD=1;
                	startR=1;
                }

// Movements corresponding to keypad buttons.
							if (dir==97){ // move left.
								dirL=1;
								dirR=0;
								dirU=0;
								dirD=0;
								mvprintw(posY,posX,">");
		 
							}

							if (dir==100){ //move right
								dirR=1;
								dirL=0;
								dirU=0;
								dirD=0;
								mvprintw(posY,posX,"<");
		 
							}

							if (dir==119){ //move up.
								dirU=1;
								dirR=0;
								dirL=0;
								dirD=0;
								mvprintw(posY,posX,"v");
							}

							if (dir==115){ //move down.
								dirD=1;
								dirL=0;
								dirR=0;
								dirU=0;
								mvprintw(posY,posX,"^");
		 
							}
		
		
		
		// once directions are specified.
		
		
		
							if (dirL==1 && startL==1){
								mvprintw(posY,posX," ");
								startR=1;
								startU=1;
								startD=1;
								if (stopL=='$'){
								score = score++;
								}
								if (animate==0){
									mvprintw(posY,--posX,">");
									bug=1;
								}
								if (animate==1){
									mvprintw(posY,--posX,"O");
									bug=0;
								}
							}

							if (dirR==1 && startR==1){
								mvprintw(posY,posX," ");
								startU=1;
								startD=1;
								startL=1;
								if (stopR=='$'){
								score++;
								}
								if (animate==0){
									mvprintw(posY,++posX,"<");
									bug=1;
								}
								if (animate==1){
									mvprintw(posY,++posX,"O");
									bug=0;
								}
							}

							if (dirU==1 && startU==1){
								mvprintw(posY,posX," ");
								startL=1;
								startR=1;
								startD=1;
								if (stopU=='$'){
								score = score++;
								}
		 						if (animate==0){
		 							mvprintw(--posY,posX,"v");
		 							bug=1;
		 						}
		 						if (animate==1){
						 		mvprintw(--posY,posX,"O");
		 						bug=0;
		 						}
							}

							if (dirD==1 && startD==1){
								mvprintw(posY,posX," ");
								startL=1; 
								startU=1; 
								startR=1;
								if (stopD=='$'){
								score = score++;
								}

								if (animate==0){
								mvprintw(++posY,posX,"^");
								bug=1;
								}
								if (animate==1){
								mvprintw(++posY,posX,"O");
								bug=0;
								}
							}
			
			
				// collision between Pacman and Ghost.
				if (posX==posGX0 && posY==posGY0){
				mvprintw(rows/2, cols/2,"Game Over !!");
				last = 1;
				break;
							}
				 if (posX==posGX1 && posY==posGY1){
                                mvprintw(rows/2, cols/2,"Game Over !!");
                                last = 1;
                                break;
                                }
				 if (posX==posGX2 && posY==posGY2){
                                mvprintw(rows/2, cols/2,"Game Over !!");
                                last = 1;
                                break;
                                }

				if (bug==1){
				animate=1;
				}
				if(bug==0){
				animate=0;
				}
				
				
//Pacman PART ends.
//------------------------------------------------------------------------------------------


start_color();
             init_pair(1, COLOR_BLACK, COLOR_RED);
             attron(COLOR_PAIR(1));
             mvprintw(1,cols/2-4,"YOUR GAME SCORE IS: ");
             mvprintw(1,cols/2+15,"%d",score);

//quit the game.
if (dir==113){
break ;
}
if (score>=852){
break;
}

attroff(COLOR_PAIR(1));
}//while
if (last!=1){
mvprintw(rows/2, cols/2-10, "CONGRATULATIONS. YOU WIN....!!");}
else {
mvprintw(rows/2, cols/2-10, "TRY AGAIN...YOU LOSE ...!!");
}
endwin();
}//main

//-------------------------------------------------------------------------------------------
											// DrawBoundary
void drawBound(){
int rows; int cols;
	getmaxyx(stdscr, rows, cols);
	int xL=0; int yU=0; int yD; int xR=0; int x=-2; int y=0; int xM;
	// left bounday
	start_color();
	init_pair(1,COLOR_RED,COLOR_WHITE);
	attron(COLOR_PAIR(1));
	for (int j=0;j<=rows;j++){
	xL=0;
	xR=2;
	xM=1;
	y=y++;
	mvprintw(y,xL,"|");
	mvprintw(y,xR,"|");
	mvprintw(y,xM,"|");
	}
	 // for upper boundary.
	for (int i=0;i<=cols;i++){
        yU=0;
       	yD=1;
        x=x++;
        mvprintw(yU,x,"|");
        mvprintw(yD,x,"|");
    }
	// for right boundary.
 		xR=0; xL=0; y=0; 
 		for (int j=0;j<=rows;j++){
        	xR=cols-1;
        	xL=cols-3;
        	xM=cols-2;
        	y=y++;
        	mvprintw(y,xL,"|");
        	mvprintw(y,xR,"|");
        	mvprintw(y,xM,"|");
        }
 // for lower part.
 		x=0; yU=0; yD=0;
 		for (int i=0;i<=cols;i++){
       		yU = rows-1;
      		yD = rows-2;
       		x=x++;
       		mvprintw(yU,x,"|");
     		mvprintw(yD,x,"|");
        }

attroff(COLOR_PAIR(1));
}// boundary function.
//--------------------------------------------------------------------------------------------
											// draw Maze

void drawMaze(){
		int rows; int cols; int midObsI; int midObsF;
		getmaxyx(stdscr, rows, cols);

		// for very middle obstacles.
		start_color();
		init_pair(2,COLOR_RED, COLOR_BLACK);
		attron(COLOR_PAIR(2));
		for (int i=cols-151; i<=cols-20; i++){
			mvprintw((rows/2)-1,i,"|");
		}
		for (int i=cols-150; i<=cols-19;i++){
			mvprintw(rows/2+1,i,"|");
		}

		//  lower right obstacles.
		for (int i=rows/2; i<=(rows-3); i=i+3){ // very right obstacle.
 		mvprintw(i,cols-5,"|");
		}
		for (int i=(rows/2)+1; i<=(rows-3); i=i+2){ // 2nd right obstacle.
		mvprintw(i,cols-7,"|");
		}
		for (int i=(rows/2); i<=(rows-3); i++){ // 3rd right obstacle.
		mvprintw(i,cols-9,"|");
		}

		 // lower left obstacles.
                for (int i=rows/2; i<=(rows-3); i=i+3){ // very left obstacle.
                mvprintw(i,4,"|");
                }
                for (int i=(rows/2)+1; i<=(rows-3); i=i+2){ // 2nd left obstacle.
                mvprintw(i,6,"|");
                }
                for (int i=(rows/2); i<=(rows-3); i++){ // 3rd left obstacle.
                mvprintw(i,8,"|");
                }



         // upper right obstacles.
               for (int i=3; i<=(rows/2)-10; i++){ // right upper sai neechay
               mvprintw(i,cols-5,"|");
               mvprintw(i,cols-6,"|");
               }
               for (int i=(cols-10); i<=(cols-5);i++){ // right right sai left.
               mvprintw(3,i,"|");
               }
			  for (int i=3; i<=(rows/2)-10; i++){ // left upper sai neecahy.
               mvprintw(i,cols-20,"|");
               mvprintw(i,cols-19,"|");
               }
               for (int i=(cols-20); i<=(cols-15);i++){ // left sai right.
               mvprintw(3,i,"|");

               }
               for (int i=5; i<=(rows/2)-10; i++){ //right inner obstacles
               mvprintw(i, cols-10, "|");
               mvprintw(i,cols-9,"|");
               } 
               for (int i=5; i<=(rows/2)-10; i++){ // left inner obstacle.
               mvprintw(i, cols-15,"|");
               mvprintw(i,cols-16,"|");
               }
		// upper left obstacles.
               for (int i=3; i<=(rows/2)-10; i++){ // left upper sai neechay
               mvprintw(i,4,"|");
               mvprintw(i,5,"|");
               }
               for (int i=4; i<=10;i++){ // left sai left.
               mvprintw(3,i,"|");

               }
            for (int i=3; i<=(rows/2)-10; i++){ // right upper sai neecahy.
               mvprintw(i,17,"|");
               mvprintw(i,18,"|");
               }
               for (int i=12; i<=18;i++){ // right wala left sai left..
               mvprintw(3,i,"|");

               }
               for (int i=5; i<=(rows/2)-10; i++){ //left inner obstacles
               mvprintw(i, 9, "|");
               mvprintw(i,10,"|");
               }
               for (int i=5; i<=(rows/2)-10; i++){ // right inner obstacle.
               mvprintw(i, 12,"|");
               mvprintw(i,13,"|");

               }
         // Boxes.
         // lower right square box.
         for (int j=cols/2+1; j<=cols-20; j++){
         	for (int i=rows-11; i<=rows-4; i++){
         	mvprintw(i, j,"|");
         	}
         }

	 	// lower left square box.
         for (int j=cols-150; j<=cols/2-1; j++ ){
         	for (int i=rows-11; i<=rows-4; i++){ //up and down outer.
         	mvprintw(i, j, "|");
        	 }
         }
         
	 // 	right upward square box.
         for (int j=cols/2+1; j<=cols-24; j++){
         	for (int i=3; i<=rows/2-12; i++){
         	mvprintw(i, j, "|");
         	}
         }
	   // left upward square box.
        for (int j=cols-146; j<=cols/2-1; j++){
         	for (int i=3; i<=(rows/2)-12; i++){
         	mvprintw(i, j, "|");
         	}
		}
	
		// right darmayan wali patti right sai left sai neechay.
		for (int i=(rows/2)-3; i<=rows-4; i++){ //left bahir wali
		mvprintw(i, cols-16, "|");
		mvprintw(i, cols-17, "|");
		mvprintw(i, cols-18,"|");
		}
		for (int i=(rows/2)-2; i<=rows-3; i++){ // left andar wali
		mvprintw(i, cols-14,"|");
		mvprintw(i, cols-13, "|");
		mvprintw(i, cols-12, "|");
		}
		for (int j=cols-12; j<=cols-5; j++){ //down right sai left.
		mvprintw(rows/2-2, j, "|");
		}
		for (int j=cols-18; j<=cols-3; j++){// up right sai left.
		mvprintw(rows/2-4,j,"|");
		}


				// left darmayan wali patti right sai left sai neechay.
                for (int i=(rows/2)-4; i<=rows-4; i++){ //right bahir wali
                mvprintw(i, cols-152, "|");
                mvprintw(i, cols-153, "|");
                mvprintw(i, cols-154,"|");
                }
                for (int i=(rows/2)-2; i<=rows-3; i++){ // left andar wali
                mvprintw(i, cols-156,"|");
                mvprintw(i, cols-157, "|");
                mvprintw(i, cols-158, "|");
                }
                for (int j=4; j<=cols-156; j++){ //down left sai right.
                mvprintw(rows/2-2, j, "|");
                }
                for (int j=2; j<=cols-152; j++){// up left sai right.
                mvprintw((rows/2)-4,j,"|");
                }
        		// Down boxes sai upar middle tak ka pattern. 
				for (int j=cols-150; j<=cols-20; j+=2){ //most lower.
				mvprintw(rows-13, j, "|");
				mvprintw(rows-17,j,"|");
				}
				for (int j=cols-151; j<=cols-19; j=j+2){ //2nd most outer.
				mvprintw(rows-15, j,"|");
				mvprintw(rows-19, j ,"|");
				}
				// Up boxes sai neechay wali tak ka pattern.
						for (int j=cols-150; j<=cols-20; j+=2){ //most lower.
                                mvprintw(rows/2-10, j, "|");
                                mvprintw(rows/2-6,j,"|");
                                }
                                for (int j=cols-151; j<=cols-19; j=j+2){ //goes up..
                                mvprintw(rows/2-8, j,"|");
                                mvprintw(rows/2-4, j ,"|");
                                }
attroff(COLOR_PAIR(2));


} // drawMaze finishes.
//---------------------------------------------------------------------------------------------------------

									// distribute food.

void distFood(){
				int rows; int cols; int midFoodI; int midFoodF;
                getmaxyx(stdscr, rows, cols);

                // for very middle Food.

                for (int j=cols-150; j<=cols-19; j+=2){
                        mvprintw((rows/2),j,"$");
                        mvprintw((rows/2),j,"$");
                }

                // right side Food.
                for (int i=rows/2; i<=(rows-3); i=i+3){ // very right obstacle.
                mvprintw(i,cols-4,"$");
                }
                for (int i=(rows/2)+1; i<=(rows-3); i=i+2){ // 2nd right obstacle.
                mvprintw(i,cols-6,"$");
                }
                for (int i=(rows/2); i<=(rows-3); i+=2){ // 3rd right obstacle.
                mvprintw(i,cols-8,"$");
                }

		 		// left side Food.
                for (int i=rows/2; i<=(rows-3); i=i+3){ // very left obstacle.
                mvprintw(i,3,"$");
                }
                for (int i=(rows/2)+1; i<=(rows-3); i=i+2){ // 2nd left obstacle.
                mvprintw(i,5,"$");
                }
                for (int i=(rows/2); i<=(rows-3); i+=2){ // 3rd left obstacle.
                mvprintw(i,7,"$");
                }


				// upper right obstacles.
               for (int i=4; i<=(rows/2)-10; i+=2){ // right upper sai neechay
               mvprintw(i,cols-7,"$");
               }
     
               for (int i=4; i<=(rows/2)-10; i+=2){ // left upper sai neecahy.
               mvprintw(i,cols-18,"$");
               }
    
               for (int i=5; i<=(rows/2)-10; i+=2){ //right inner obstacles
               mvprintw(i, cols-8, "$");
   
               }
               for (int i=5; i<=(rows/2)-10; i+=2){ // left inner obstacle.
               mvprintw(i, cols-17,"$");
        
               }

		 		// upper left obstacles.
               for (int i=4; i<=(rows/2)-10; i+=2){ // left upper sai neechay
               mvprintw(i,6,"$");
               }
               for (int i=4; i<=(rows/2)-10; i+=2){ // right upper sai neecahy.
               mvprintw(i,16,"$");
               }
               for (int i=5; i<=(rows/2)-10; i+=2){ //left inner obstacles
               mvprintw(i, 8, "$");
               }

		       for (int i=5; i<=(rows/2)-10; i+=2){ // right inner obstacle.
               mvprintw(i,14,"|");

               }
   

         // Boxes.

         // lower right square box.
         for (int j=cols-150; j<=cols-20; j+=2){
                mvprintw(rows-3, j,"$");
                mvprintw(rows-12,j,"$");
                mvprintw(rows/2-11,j,"$");
         }

		 //     right upward square box.
         for (int j=3; j<=cols-4; j+=2){
                mvprintw(2, j, "$");
         }


                // right darmayan wali patti right part.
                for (int i=(rows/2)-3; i<=rows-4; i+=2){ //left bahir wali
                mvprintw(i, cols-15, "$");
                }
		 		for (int i=(rows/2); i<=rows-3; i+=2){ // left andar wali
                mvprintw(i, cols-10,"$");
                }
                for (int j=cols-9; j<=cols-5; j+=2){ //down right sai left.
                mvprintw(rows/2-1, j, "$");
                }
                for (int j=cols-15; j<=cols-4; j+=2){// up right sai left.
                mvprintw(rows/2-3,j,"$");
                }


                // left darmayan wali patti right sai left sai neechay.
                for (int i=(rows/2)-3; i<=rows-4; i+=2){ //right bahir wali
                mvprintw(i, cols-155, "$");
                }
                for (int i=(rows/2); i<=rows-3; i+=2){ // left andar wali
                mvprintw(i, cols-159,"$");
                }
				 for (int j=3; j<=cols-159; j+=2){ //down left sai right.
                mvprintw(rows/2-1,  j, "$");
                }
                for (int j=3; j<=cols-155; j+=2){// up left sai right.
                mvprintw((rows/2)-3, j, "$");
                }

                        // Down boxes sai upar middle tak ka pattern.
               for (int j=cols-150; j<=cols-20; j+=4){ //most lower.
               mvprintw(rows-14, j, "$");
               mvprintw(rows-18,j,"$");
               }
               for (int j=cols-151; j<=cols-19; j=j+4){ //2nd most outer.
               		mvprintw(rows-20, j,"$");
              		mvprintw(rows-16, j ,"$");
               }
					 // Up boxes sai neechay wali tak ka pattern.
              for (int j=cols-150; j<=cols-20; j+=4){ //most lower.
                 mvprintw(rows/2-9, j, "$");
                 mvprintw(rows/2-5,j,"$");
              }
              for (int j=cols-151; j<=cols-19; j=j+4){ //goes up..
              	mvprintw(rows/2-7, j,"$");
                mvprintw(rows/2-3, j ,"$");
             }
} // food distribution finishes.
//--------------------------------------------------------------------------------------------------
