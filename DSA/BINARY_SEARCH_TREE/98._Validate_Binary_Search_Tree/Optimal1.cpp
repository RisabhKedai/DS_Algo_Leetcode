/*
* @Author: lenovo
* @Date:   2024-01-15 21:56:22
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-15 22:15:50
*/

class Solution {
public:
	TreeNode* prev;
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> st;
        while(root!=NULL || !st.empty()){
            while(root != NULL){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            inorder.push_back(root->val);
            root = root->right;
        }
        for(int i=1; i<inorder.size(); i++){
            if(inorder[i] <= inorder[i-1])
            return false;
        }
        return true;
    }
};

/** 
 * Inorder traversal of binary tree is always sorted.
 * Keep adding values to the stack for the left sub trees. 
 * Then move to the right . Even there check if any left subtree is present and add it to the stack,
 *
 * Time Complexity : O(N)
 * Space Complexity : O(N)
 */