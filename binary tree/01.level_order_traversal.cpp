class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {   
        vector<int> ans;
      queue<Node*> q;
      q.push(node);
      while(!q.empty()){
          Node* topNode = q.front();
          q.pop();
          ans.push_back(topNode->data);
          if(topNode->left!=NULL)q.push(topNode->left);
          if(topNode->right!=NULL)q.push(topNode->right);
          
      }
      return ans;
    }
};