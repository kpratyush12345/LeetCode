//94. Binary Tree Inorder Traversal
//https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
	    if(root==NULL) return;
        
        else {
		inorder(root->left, ans);
		ans.push_back(root->val);
		inorder(root->right, ans);
	}
}
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> ans;
	    inorder(root, ans);
	    return ans;
    }
};
