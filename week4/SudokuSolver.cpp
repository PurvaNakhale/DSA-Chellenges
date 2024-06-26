// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

class Solution {
    public:
    bool isPossible(int row,int column,vector<vector<char>>& board,char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][column]==c) return false;
            if(board[row][i]==c) return false;
            if(board[3 * (row/3) +i/3][3* (column/3) + i%3]==c) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(isPossible(i,j,board,c))
                        {
                            board[i][j]=c;
                            if(solve(board)==true)
                            {
                                return true;
                            }
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
      return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);

    }
};