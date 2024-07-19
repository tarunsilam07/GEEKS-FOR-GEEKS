//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
      vector<vector<int>> nQueen(int n) {
        vector<vector<int>> solutions;
        vector<int> board(n, 0);
        solveNQueens(n, 0, board, solutions);
        return solutions;
    }

private:
    void solveNQueens(int n, int col, vector<int>& board, vector<vector<int>>& solutions) {
        if (col == n) {
            solutions.push_back(board);
            return;
        }
        
        for (int row = 1; row <= n; row++) {
            if (isSafe(col, row, board)) {
                board[col] = row;
                solveNQueens(n, col + 1, board, solutions);
                // No need to reset board[col] due to direct overwrite in next iteration
            }
        }
    }

    bool isSafe(int col, int row, const vector<int>& board) {
        for (int prevCol = 0; prevCol < col; prevCol++) {
            int prevRow = board[prevCol];
            // Check if queens are in the same row or in the same diagonal
            if (prevRow == row || abs(prevRow - row) == abs(prevCol - col)) {
                return false;
            }
        }
        return true;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends