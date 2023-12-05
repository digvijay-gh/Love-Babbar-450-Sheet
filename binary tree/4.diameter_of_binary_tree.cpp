class Solution {
  public:
    pair<int,int> func(Node* root){
        if(root==NULL)return {0,0};
        pair<int,int> left=func(root->left);
        pair<int,int> right=func(root->right);
        pair<int,int> ans;
        ans.first=max(left.first,max(right.first,left.second+right.second+1));
        ans.second=max(left.second,right.second)+1;
        return ans;
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        return func(root).first;
    }
};