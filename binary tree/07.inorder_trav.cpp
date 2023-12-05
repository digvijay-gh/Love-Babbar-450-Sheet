void inorder(TreeNode* root,vector<int>& ans){
    if(root==NULL)return ;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    // inorder(root,ans);
    TreeNode* temp=root;
    stack<TreeNode*> st;
    
    while(true){
        if(temp!=NULL){
            st.push(temp);
            temp=temp->left;
        }else{
            if(st.empty())break;
            temp=st.top();
            st.pop();
            ans.push_back(temp->data);
            temp=temp->right;
        }
    }
    return ans;
}