/*
* @Author: lenovo
* @Date:   2024-01-18 03:14:00
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-18 03:16:50
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }
            if(root->left==NULL){
                return root->right;
            }
            if(root->right==NULL){
                return root->left;
            }
            TreeNode* temp = root->left;
            while(temp->right != NULL){
                temp = temp->right;
            }
            root->val = temp->val;
            root->left = deleteNode(root->left, temp->val);
        }
        if(root->val>key){
            root->left = deleteNode(root->left, key);
        };

        if(root->val<key){
            root->right = deleteNode(root->right, key);
        };
        return root;
    }
};

/**
 * Recursively find the node that has the same value as the key, while setting the left/right nodes equal to the returned subtree
 * Once the node is found, have to handle the below 4 cases
 * node doesn't have left or right - return null
 * node only has left subtree- return the left subtree
 * node only has right subtree- return the right subtree
 * node has both left and right - find the minimum value in the right subtree, set that value to the currently found node, then recursively delete the minimum value in the right subtree
 * 
 * Time complexity : O(N + log(N))
 * Space complexity : O(1)
 */