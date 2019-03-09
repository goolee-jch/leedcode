/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    if (numsSize == 0) return NULL;

    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    int max = 0;
    int position = 0; 
    
    for (int i = 0; i < numsSize; i++){
        if (nums[i] > max){
            max = nums[i];
            position = i;
        }
    }
    root->val = max;
    root->left = constructMaximumBinaryTree(nums, position);
    root->right = constructMaximumBinaryTree(nums+position+1, numsSize-position-1);
    return root;
}