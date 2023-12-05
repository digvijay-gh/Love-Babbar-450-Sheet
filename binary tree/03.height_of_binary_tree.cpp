class Solution{
    public:
    int h(Node* node){
        if(node==NULL)return 0;
        int left=h(node->left);
        int right=h(node->right);
        int ans=max(left,right)+1;
        return ans;
        
    }
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        return h(node);
    }
};