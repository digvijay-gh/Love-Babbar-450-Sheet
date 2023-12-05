void postorder(TreeNode* node, vector<int> &ans)
{
    if (node == NULL) return ;
     
    postorder(node->left, ans);
    postorder(node->right, ans);
    ans.push_back(node->data);
}  
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    // pre(root,ans);
    stack<TreeNode*> priStack;
    stack<TreeNode*> secStack;
    priStack.push(root);
    while(!priStack.empty()){
        TreeNode* topNode=priStack.top();
        priStack.pop();
        secStack.push(topNode);
        if(topNode->left)
        priStack.push(topNode->left);
        if(topNode->right)
        priStack.push(topNode->right);
    }
    while(!secStack.empty()){
        TreeNode* topNode=secStack.top();
        secStack.pop();
        ans.push_back(topNode->data);
    }
    
    return ans;
}