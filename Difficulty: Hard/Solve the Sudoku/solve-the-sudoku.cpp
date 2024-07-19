//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
bool isValid(int grid[N][N], int row, int col, int num) {
    // Check the row
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    // Check the column
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;

    // Check the 3x3 sub-box
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Function to solve the Sudoku
bool SolveSudoku(int grid[N][N]) {
    int row = -1, col = -1;
    bool isEmpty = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty)
            break;
    }

    // No empty space left
    if (isEmpty)
        return true;

    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (SolveSudoku(grid))
                return true;
            grid[row][col] = 0; // Backtrack
        }
    }
    return false; // Trigger backtracking
}

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            cout << grid[r][d] << " ";
        }
    }
}
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends