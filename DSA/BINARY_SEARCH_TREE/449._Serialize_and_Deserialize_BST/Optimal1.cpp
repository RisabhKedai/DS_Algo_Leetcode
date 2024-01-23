/*
* @Author: lenovo
* @Date:   2024-01-23 12:31:25
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-23 13:15:12
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
int ind;
    string serialUtil(TreeNode* root){
        if(root==NULL){
            return "#,";
        }
        string ans = "";
        ans += to_string(root->val);
        ans += ",";
        ans += serialUtil(root->left);
        ans += serialUtil(root->right);
        return ans;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "[]";
        }
        string ans = "[";
        ans += serialUtil(root);
        ans = ans.substr(0,ans.length()-1);
        ans += ']';
        // cout<<ans<<endl;
        return ans;
    }

    TreeNode* deserUtil(string data){
        if(ind >= data.length()-1){
            return NULL;
        }
        if(data[ind] == ','){
            ind++;
        }
        string temp = "";
        for(;ind<data.length()-1 && data[ind]!=','; ind++){
            temp += data[ind];
        }
        // cout<<temp<<endl;
        if(temp == "#"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(temp));
        root->left = deserUtil(data);
        root->right = deserUtil(data);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        ind = 1;
        return deserUtil(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;


/**
 * Convert BST to string using preorder.
 * Replace null with #.
 *
 * Convert string back to tree using recurssion and use # as null.
 *
 * Time complexity :O(N)
 * Space complexity :O(2N)
 */