//51. N-Queens
//https://leetcode.com/problems/n-queens/

class Solution {
public:
    vector<vector<string>> ans;
    
    int check(vector<string> board,int row,int col){
        
        //To check column
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q')
                return 0;
        }
        
        //To check diagonal +45
        for(int i=1;row-i>=0 && col+i<board[0].size();i++){
            if(board[row-i][col+i]=='Q')
                return 0;
        }
        
        //To check diagonal -45
        for(int i=1;row-i>=0 && col-i>=0;i++){
            if(board[row-i][col-i]=='Q')
                return 0;
        }
        
        return 1;
    }

    void solve(int n,vector<string> board,int row){
        
        if(row==n){
            ans.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(check(board,row,i)){
                board[row][i]='Q';
                solve(n,board,row+1);
                board[row][i]='.';
            }
        }
        
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        string temp;
        for(int i=0;i<n;i++)
            temp+='.';
        
        vector<string> board (n,temp);
        solve(n,board,0);
        
        return ans;
    }
};
