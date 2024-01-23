/*
* @Author: lenovo
* @Date:   2024-01-23 13:04:37
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-23 13:11:33
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
    queue<int> q;
    string serialUtil(TreeNode* root){
        if(root==NULL){
            return "";
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

    TreeNode* deserUtil( int l, int r){
        // cout<<l<<" "<<r<<"\n";
        if(q.empty()) return NULL;
        int k = q.front();
        // cout<<k<<endl;
        if(l>k || k>=r){
            return NULL;
        }
        // cout<<"Pooping = "<<q.front()<<endl;
        q.pop();
        TreeNode* root = new TreeNode(k);
        root->left = deserUtil(l,root->val);
        root->right = deserUtil(root->val + 1,r);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string temp = "";
        for(int i=1; i<data.length()-1; i++){
            if(data[i] == ','){
                q.push(stoi(temp));
                temp = "";
            }else{
                temp += data[i];
            }
        }
        if(temp!="") q.push(stoi(temp));
        return deserUtil(INT_MIN,INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;


/**
 * Convert the tree to a normal string of numbers seperated by comma
 * For deserializing convert the string to a queue, now use the ranges start to begin
 * in a recursive call to decide if a number can be saved in a current node or not.
 *
 * if not then return null.
 * Else pop that element and save the element on the current node. Process that node's
 * left and right using recursion
 *
 * Return the node
 *
 * Time complexity : O(N)
 * Space complexity : O(2N)
 */