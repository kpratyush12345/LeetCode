//1329. Sort the Matrix Diagonally
//https://leetcode.com/problems/sort-the-matrix-diagonally/

class Solution {
public:
    void dsort(int r,int c,vector<vector<int>>& mat){
        vector<int> d;
        int i = r;
        int j = c;
        while(i<mat.size() && j<mat[i].size()){
            d.push_back(mat[i++][j++]);
        }
        sort(d.begin(),d.end());
        i=r;j=c;
        int count =0;
        while(i<mat.size() && j<mat[i].size()){
            mat[i++][j++]=d[count++];
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int r=0;r<mat.size();r++){dsort(r,0,mat);}
        for(int c=0;c<mat[0].size();c++){dsort(0,c,mat);}
        return mat;
    }
};
