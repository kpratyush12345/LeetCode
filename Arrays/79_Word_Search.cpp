//79. Word Search
//https://leetcode.com/problems/word-search/

class Solution {
public:
    bool findWord(vector<vector<char>>& board , string word , int index, int i , int j , vector<vector<bool>>& visited){
        if(index == word.length()) return true;
        if(i<0 || i>=board.size()) return false;
        if(j<0 || j>=board[0].size()) return false;
        if(visited[i][j]) return false;
        if(board[i][j]==word[index]){
            visited[i][j]=true;
            bool ret1 = findWord(board,word,index+1,i-1,j,visited);
            bool ret2 = findWord(board,word,index+1,i+1,j,visited);
            bool ret3 = findWord(board,word,index+1,i,j-1,visited);
            bool ret4 = findWord(board,word,index+1,i,j+1,visited);
            bool flag = (ret1 || ret2 || ret3 || ret4);
            if(!flag) visited[i][j]=false;
            return flag;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(),columns =0,i=0,j=0;
        bool flag = false;
        if(rows) columns = board[0].size();
        
        for(i=0;i<rows;i++){
            for(j=0;j<columns;j++){
                if(word[0]==board[i][j]){
                    vector<vector<bool>> visited(rows,vector<bool> (columns,false));
                    if(findWord(board,word,0,i,j,visited)) return true;
                }
            }
        }
        return false;
    }
};
