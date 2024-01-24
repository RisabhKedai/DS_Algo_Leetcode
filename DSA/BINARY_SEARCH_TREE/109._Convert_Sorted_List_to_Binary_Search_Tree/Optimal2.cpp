/*
* @Author: lenovo
* @Date:   2024-01-25 00:09:55
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-25 00:11:34
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    TreeNode* util(ListNode* head, ListNode* tail) {
        ListNode* fast = head;
        ListNode* slow = head;
        if(head == tail){
            return NULL;
        }
        while(fast!=tail && fast->next!=tail){
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = util(head, slow);
        root->right = util(slow->next, tail);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL){
            return NULL;
        } 
        return util(head, NULL);
    }
};

/**
 * The same concept as an array would be used. The only difference is that,
 * TO reach the mis element we use Fast and slow pointer
 *
 * The fast pointer moves at twice the speed. so the slow pointer reaches the mid
 * while the fast pointer is at the end. 
 *
 * Time complexity : O(NlogN)
 * Space Complexity : O(1)
 */