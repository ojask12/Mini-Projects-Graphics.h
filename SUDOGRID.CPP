#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<sudoku.h>
int sudoku[9][9]=  {{3, 0, 6, 5, 0, 8, 4, 0, 0},
					{5, 2, 0, 0, 0, 0, 0, 0, 0},
					{0, 8, 7, 0, 0, 0, 0, 3, 1},
					{0, 0, 3, 0, 1, 0, 0, 8, 0},
					{9, 0, 0, 8, 6, 3, 0, 0, 5},
					{0, 5, 0, 0, 9, 0, 6, 0, 0},
					{1, 3, 0, 0, 0, 0, 2, 5, 0},
					{0, 0, 0, 0, 0, 0, 0, 7, 4},
					{0, 0, 5, 2, 0, 6, 3, 0, 0}};
void main(){
 int i,j,k,l,shaded_box;
 char arr[50];
 int side=360;
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
 rectangle(100,100,100+side,100+side);
 settextstyle(5,0,0); 
 outtextxy(155,5,"Sudoku Solver");
 settextstyle(0,0,2); 
 outtextxy(15,55,"Press ENTER to fill the blank spaces");
 solve();
 
 line(100+(2*(side/3)),100,100+(2*(side/3)),100+side);  //vertical 2nd line
 line(100+(side/3),100,100+(side/3),100+side);  //vertical 1st line
 line(100,100+(2*(side/3)),100+side,100+(2*(side/3)));  //horizontal 2nd line
 line(100,100+(side/3),100+side,100+(side/3));  //horizontal 1st line
 
 
 
 for(i=(side/9);i<=(side*8)/9;i+=(side/9)){  //adding row n col lines n color
	line(100+i,100,100+i,100+side); 
	line(100,100+i,100+side,100+i); 
 
	 for(j=0;j<=side;j++){ //chnging color of all lines
		putpixel(100+(2*(side/3)),100+j, RED);//chng colors of middle lines
		putpixel(100+(side/3),100+j, RED);  
		putpixel(100+j,100+(side/3), RED);
		putpixel(100+j,100+(2*(side/3)), RED);//until here
		putpixel(100,100+j, RED);//rectangle chng
		putpixel(100+j,100, RED);
		putpixel(100+j,100+side, RED);
		putpixel(100+side,100+j, RED);//until here
		putpixel(100+j,100+i, LIGHTBLUE);//horizontal inside lines
		putpixel(100+i,100+j, LIGHTBLUE);//vertical inside lines
	}
 }
 int spacing=40;
 int inc;
 k=0;
 for(i=0;i<9;i++){
	 l=0;
	 for(j=0;j<9;j++){
		 if(sudoku[i][j]==0){for(inc=2;inc<39;inc++){
			 for(shaded_box=2;shaded_box<39;shaded_box+=1){
				 putpixel(100+j*40+shaded_box,100+i*40+inc,LIGHTGRAY);
				 // putpixel(100+j*40,100+i*40+shaded_box,LIGHTGRAY);
		 }}}
		sprintf(arr,"%d",sudoku[i][j]);
		outtextxy(120+l, 120+k, arr);
		l+=spacing;
	 }
	 k+=spacing;
 }
 getch(); 
 setbkcolor(BROWN);
 setfillstyle(SOLID_FILL,BROWN);
 bar(0,45,700,70);
 settextstyle(5,0,0); 
 outtextxy(155,5,"Sudoku Solver");
 settextstyle(0,0,2); 
 outtextxy(180,50,"Solving.");
 delay(1000);
 outtextxy(298,50,".");
 delay(1000);
 outtextxy(304,50,".");
 solve();
 k=0;
 for(i=0;i<9;i++){
	 l=0;
	 for(j=0;j<9;j++){
		 if(sudoku[i][j]==0){for(inc=2;inc<39;inc++){
			 for(shaded_box=2;shaded_box<39;shaded_box+=1){
				 putpixel(100+j*40+shaded_box,100+i*40+inc,LIGHTGRAY);
				 // putpixel(100+j*40,100+i*40+shaded_box,LIGHTGRAY);
		 }}}
		sprintf(arr,"%d",grid[i][j]);
		outtextxy(120+l, 120+k, arr);
		l+=spacing;
	 }
	 k+=spacing;
 }
 
 
 setbkcolor(GREEN);
 setfillstyle(SOLID_FILL,GREEN);
 bar(0,45,700,70);
 outtextxy(180,50,"Solved!");
 
 getch();
 closegraph();
}