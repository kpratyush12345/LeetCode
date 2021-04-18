//297. Serialize and Deserialize Binary Tree
//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

class Codec {
public:

    // Encodes a tree to a single string of preorder traversal.
    string serialize(TreeNode* root) {
        if (root == NULL) return "null";
        string s;
        s += to_string(root -> val);
        string serial_left = serialize(root -> left);
        string serial_right = serialize(root -> right);
        return s + "," + serial_left + "," + serial_right;
    }
    
    TreeNode* helper_deserialize(queue<string> &q) {
        if (q.empty()) return NULL;
        string s = q.front();
        q.pop();
        if (s == "null") return NULL;
        int num = stoi(s);
        // int num = 10;
        TreeNode* node = new TreeNode(num);
        node -> left = helper_deserialize(q);
        node -> right = helper_deserialize(q);
        return node;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == ',') {
                q.push(temp);
                temp = "";
            }
            else  temp.push_back(data[i]);
        }
        return helper_deserialize(q);
        return NULL;
    }
};
