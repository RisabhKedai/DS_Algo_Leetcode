/*
* @Author: lenovo
* @Date:   2024-01-18 22:18:53
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-18 22:20:28
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
private:
    int cnt;
    TreeNode* util(TreeNode* root, int k){
        // base case
        if(root){
            // search in left subtree
            TreeNode* left = util(root->left, k);
            
            // if k'th smallest is found in left subtree, return it
            if(left != NULL){
                return left;
            }
            cnt ++;

            // if current element is k'th smallest, return it
            if(cnt == k){
                return root;
            }
            // else search in right subtree
            return util(root->right,k);
        }
        return NULL;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        cnt = 0;
        return util(root, k)->val;
    }
};

/**
 * Use Inorder traversal to count to the kth smallest element
 * in the binary search tree. 
 *
 * Time Complexity : O(N)
 * Space Complexity : O(1)
 */