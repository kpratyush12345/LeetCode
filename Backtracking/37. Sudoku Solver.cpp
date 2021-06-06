//37. Sudoku Solver
//https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    
    // check if valid
    bool check(vector<vector<char>>& board,int i,int j,char val){
        int row=i-i%3,col=j-j%3;
       for(int x=0;x<9;x++) if(board[x][j]==val) return false;  //check in row
       for(int y=0;y<9;y++) if(board[i][y]==val) return false;  //check in col
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[row+i][col+j]==val) return false;          //check in 3x3 box
            }
        }
        return true;   
    }
    
    //Utility function
    
    bool SolveSudoku(vector<vector<char>>& board,int i,int j){
        if(i==9) return true;         // if sudoku filled complitely
        if(j==9) return SolveSudoku(board,i+1,0);  //if 3x3 box filled
        if(board[i][j]!='.') return SolveSudoku(board,i,j+1); //if already filled
        
        for(int val='1';val<='9';val++){
            if(check(board,i,j,val)){
                board[i][j]=val;
                if(SolveSudoku(board,i,j+1)) return true;
                board[i][j]='.';
            }
        }
        return false;
        
    }
    
    // main function  
    void solveSudoku(vector<vector<char>>& board) {
        SolveSudoku(board,0,0);
    }
};
