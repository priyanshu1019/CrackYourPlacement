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
    bool helper(TreeNode* root , int targetSum , int sum ){
        sum += root->val;
        if( root->left == NULL and root->right == NULL ){
            //leaf node 
            return targetSum == sum;
        }
        bool left = false , right = false;

        if( root->left){
            left = helper(root->left , targetSum , sum);
        }
        if( root ->right){
            right = helper(root->right , targetSum , sum);
        }
        return left || right;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if( root == NULL ) return false;
        return helper(root , targetSum , 0);
    }
};
