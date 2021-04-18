//105. Construct Binary Tree from Preorder and Inorder Traversal
//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {
public:
    unordered_map<int,int>mp;
    TreeNode* recur(vector<int>& preorder,vector<int>& inorder,int start,int end,int index) {
        if(start>end) return NULL;
        TreeNode *root = new TreeNode(preorder[index]);
        
        int inIndex=mp[preorder[index]];
        
        root->left = recur(preorder,inorder,start,inIndex-1,index+1);
        root->right = recur(preorder,inorder,inIndex+1,end,index+inIndex-start+1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        if(n==0) return NULL;
        for(int i=0;i<n;i++) mp.insert(make_pair(inorder[i],i));
        return recur(preorder,inorder,0,n-1,0);
    }
};
