void preorder(TreeNode* node, vector<int> &ans)
{
    if (node == NULL) return ;
    

    // Inserting node's value to ans array.    
    ans.push_back(node->val);

    // Traversing left subtree
    preorder(node->left, ans);

    // Traversing right subtree
    preorder(node->right, ans); 
} 
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> ans;
    // pre(root,ans);
    stack<TreeNode*> st;
    st.push(root);
    
    while( !st.empty() ){
        TreeNode* topNode = st.top();
        st.pop();
        ans.push_back(topNode->val);
        if(topNode->right!=NULL)st.push(topNode->right);
        if(topNode->left!=NULL)st.push(topNode->left);
    }
    return ans;
}