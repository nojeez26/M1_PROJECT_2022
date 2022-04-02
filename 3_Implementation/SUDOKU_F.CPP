#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Sudoku
{
  public:
    int grid[9][9];

    // This function finds an entry in grid that is still unassigned
    int Find0(int &row, int &col);

    // Checks whether specified row members matches the given number.
    int UsedInRow(int row, int num);

    // Checks whether specified column matches the given number.
    int UsedInCol(int row, int num);

    // Checks whether specified 3x3 box members matches the given number.
    int UsedInBox(int boxStartRow, int boxStartCol, int num);

    // Checks whether it will be legal to assign num to the given row,col
    int isSafe(int row, int col, int num);

    //Solves the given sudoku puzzle using backtracking algorithm
    int SolveSudoku();

    //To print the main gameboard
    void printGrid();
};

int main()
{
    Sudoku s;
    int n,value,row,col;
    
    //The user can also enter the gameboard values manually here...
    /* 0 means unassigned cells
    int grid[9][9] = {{0, 0, 0, 2, 6, 0, 7, 0, 1},
		      {6, 8, 0, 0, 7, 0, 0, 9, 0},
		      {1, 9, 0, 0, 0, 4, 5, 0, 0},
		      {8, 2, 0, 1, 0, 0, 0, 4, 0},
		      {0, 0, 4, 6, 0, 2, 9, 0, 0},
		      {0, 5, 0, 0, 0, 3, 0, 2, 8},
		      {0, 0, 9, 3, 0, 0, 0, 7, 4},
		      {0, 4, 0, 0, 5, 0, 0, 3, 6},
		      {7, 0, 3, 0, 1, 8, 0, 0, 0}};*/
    for(int i=0;i<9;i++)
	for(int j=0;j<9;j++)
	  s.grid[i][j]=0;
    printf("Enter the number of input for Sudoku: ");   scanf("%d" ,&n);
    printf("Enter %d values for initial array:\t Format:Value Row Column\n",n);
    getch();
    for(int i=0;i<n;i++)
    {
	s.printGrid();	//box printing
	printf("\n%d.",i+1);
	scanf("%d%d%d", &value,&row,&col);
	//cin>>value>>row>>col;

	if( value>10) exit(0);

	s.grid[row-1][col-1]=value;
	getch();
    }
    
  /*  for(j=0;j<9;j++)
    {
	for(int k=0;k<9;k++)
	    cout<<s.grid[j][k]<<' ';
	cout<<endl;
    }*/
		//Kindly enclose till this, if u enter the data manually.
    printf("Press any key for solution :");
    getch();
    if (s.SolveSudoku() == 1)
	  s.printGrid();
    else
	 printf("No solution exists");
    getch();
}

int Sudoku::SolveSudoku()
{
    int row, col;
    //If there in no unassigned location
    if (!Find0(row, col))
       return 1;
    for (int num = 1; num <= 9; num++)
    {
	if (isSafe(row, col, num))
	{
	    grid[row][col] = num;
	    if (SolveSudoku())
		return 1;
	    else
		grid[row][col] = 0;
	}
    }
    //If no value can be entered in this place, it trigers backtracking
    return 0;
}

int Sudoku::Find0(int &row, int &col)
{
    for (row = 0; row < 9; row++)
	for (col = 0; col < 9; col++)
	    if (grid[row][col] == 0)
		return 1;
    return 0;
}

int Sudoku::UsedInRow(int row, int num)
{
    for (int col = 0; col < 9; col++)
	if (grid[row][col] == num)
	    return 1;
    return 0;
}

int Sudoku::UsedInCol(int col, int num)
{
    for (int row = 0; row < 9; row++)
	if (grid[row][col] == num)
	    return 1;
    return 0;
}

int Sudoku::UsedInBox(int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
	for (int col = 0; col < 3; col++)
	    if (grid[row+boxStartRow][col+boxStartCol] == num)
		return 1;
    return 0;
}

int Sudoku::isSafe(int row, int col, int num)
{
    /* Check if 'num' is not already placed in current row,
       current column and current 3x3 box */
    return !UsedInRow(row, num) &&
	   !UsedInCol(col, num) &&
	   !UsedInBox(row - row%3 , col - col%3, num);
}

void Sudoku::printGrid()
{
    

    int x,y;

  char topl[45]={201,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,187};

  char midl[45]={204,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,185};

  char bottoml[45]={200,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,188};

  //clrscr();

  printf("\n");

  printf("%s\n",topl);

  for(x=0;x<9;x++)

   {

    for(y=0;y<9;y++)

    {

        if(y==0)

         printf("%c",char(186));

        printf("%c%d", char(32),grid[x][y]);

        if (grid[x][y] <10)

        printf("%c%c",char(32),char(186));

        else

        printf("%c",char(186));

     }
     printf("\n");

    if (x<8)

     printf("%s\n",midl);
   }

   printf("%s\n",bottoml);

   /* for (int row = 0; row < 9; row++)
    {
       for (int col = 0; col < 9; col++)
	    cout<<grid[row][col]<<' ';
	cout<<"\n";*/

}

