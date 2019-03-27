struct TreeNode* buildTree(int* preorder, int pSize, int* inorder, int iSize)
{
    if(pSize == 0)
        return NULL;
    struct TreeNode *root = ( struct TreeNode* )malloc(sizeof( struct TreeNode ));
    root->val = *preorder;
    int i = 0;
    while(inorder[i] != *preorder) i++;
    root->left = buildTree(preorder+1, i, inorder, i);
    root->right = buildTree(preorder+i+1, pSize-i-1, inorder+i+1, iSize-i-1);
    return root;
}
