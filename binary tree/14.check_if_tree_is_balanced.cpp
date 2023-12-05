/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int heightTree(Node* node){
        if(node==NULL)return 0;
        if(node->left==NULL && node->right==NULL)return 1;
        int leftAns=heightTree(node->left);
        int rightAns=heightTree(node->right);
        int height=max(leftAns,rightAns)+1;
        return height;
    }
    pair<bool,int> solve(Node* node){
        if(node==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        if(node->left==NULL && node->right==NULL){
            pair<bool,int> p=make_pair(true,1);
            return p;
        }
        pair<bool,int> left=solve(node->left);
        pair<bool,int> right=solve(node->right);
        
        bool diff=abs(left.second-right.second)<=1;
        pair<bool,int> ans;
        if(left.first && right.first && diff){
            ans.first=true;
        }
        else{
            ans.first=false;
        }
        ans.second=max(left.second,right.second)+1;
        return ans;
    }
    bool isBalanced(Node *root){
        return solve(root).first;    
    }
};