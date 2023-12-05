class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       map<int,int> res;
   vector<int>ans;
   if(root==NULL)return ans;
   queue<pair<Node*,int> >q;
   q.push(make_pair(root,0));
   while(!q.empty()){
       Node* temp=q.front().first;
       int lvl=q.front().second;
       q.pop();
       if(res.find(lvl)==res.end())
        res[lvl]=temp->data;
        
        if(temp->right)  q.push(make_pair(temp->right,lvl+1));
        if(temp->left)  q.push(make_pair(temp->left,lvl+1));
        

   }
   for(auto i:res){
       ans.push_back(i.second);
   }
   return ans;
    }
};