/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int rangeSumBST(struct TreeNode* root, int L, int R) {
    if(root==NULL)
        return 0;
    if(root->val>=L && root->val<=R)
    {
        if(root->left!=NULL && root->right!=NULL)
        {
            return root->val+rangeSumBST(root->left,L,R)+rangeSumBST(root->right,L,R);
        }
        else if(root->left!=NULL)
        {
            return root->val+rangeSumBST(root->left,L,R);
        }
        else
        {
            return root->val+rangeSumBST(root->right,L,R);
        }
    }
    else
    {
        if(root->val<L)
        {
            if(root->right!=NULL)
                return rangeSumBST(root->right,L,R);
            else
                return 0;
        }
        else
        {
            if(root->left!=NULL)
                return rangeSumBST(root->left,L,R);
            else
                return 0;
        }
    }
}