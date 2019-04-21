#include<iostream.h>
#include<conio.h>
int grid[9][9]= {{3, 0, 6, 5, 0, 8, 4, 0, 0},
		      {5, 2, 0, 0, 0, 0, 0, 0, 0},
		      {0, 8, 7, 0, 0, 0, 0, 3, 1},
		      {0, 0, 3, 0, 1, 0, 0, 8, 0},
		      {9, 0, 0, 8, 6, 3, 0, 0, 5},
		      {0, 5, 0, 0, 9, 0, 6, 0, 0},
		      {1, 3, 0, 0, 0, 0, 2, 5, 0},
		      {0, 0, 0, 0, 0, 0, 0, 7, 4},
		      {0, 0, 5, 2, 0, 6, 3, 0, 0}};	
int addzeroes(int i,int j,int k,int a[9][9]){
int f,l,m;
//conditions for box
int bsr=i - i% 3 ;
int bsc= j - j % 3;
for ( f = 0; f < 3; f++)  
{for (l = 0; l < 3; l++) {if (a[f+bsr][l+bsc] == k){return 0;} }}
//row & column
for(f=0;f<9;f++){
 if(a[i][f]==k){return 0;}
 if(a[f][j]==k){return 0;}
}
//UNASSIGNED chk
// if(a[i][j]==0){return 0;}
return 1;
}
int traversearr(int trav[9][9],int &row,int &col){
for(row=0;row<9;row++){
  for(col=0;col<9;col++){
  if(trav[row][col]==0){
	  return 1;
   }
  }
}
return 0;
}
int SolveSudoku(int grid[9][9])  {  
    int row, col;  
  
    // If there is no unassigned location, 
    // we are done  
    if (traversearr(grid, row, col)==0)  
    {return 1; }// success!  

    // consider digits 1 to 9  
    for (int num = 1; num <= 9; num++)  
    {
        // if looks promising  
	
        if (addzeroes(row, col, num, grid)==1)  
        {  
            // make tentative assignment  
            grid[row][col] = num;  
  
            // return, if success, yay!  
            if (SolveSudoku(grid)==1)  
			{   return 1;  }
  
            // failure, unmake & try again  
            grid[row][col] = 0;  
			} 
    }  
    return 0; // this triggers backtracking  
}  
void solve(){
SolveSudoku(grid);
}