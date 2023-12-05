//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
  void pre(map<int,map<int,int> >& m,Node* root,int vL,int hL){
        if(root==NULL)return ;
        // if(m.find(vL)==m.end() || m[vL].find(hL)==m[vL].end()){
        m[vL][hL]=root->data;
            
        // }
        pre(m,root->left,vL-1,hL+1);
        pre(m,root->right,vL+1,hL+1);
    }
    vector <int> bottomView(Node *root) {
        map<int,map<int,int> > m;
        pre(m,root,0,0);
        vector<int> ans;
        for(auto i:m){
            int val;
            for(auto j:i.second){
                val=j.second;
                
            }
            ans.push_back(val);
        }
        
        return ans;
    }
};
// Using inorder trav
//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
       map<int,int> res;
        vector<int> ans;
        if(root==NULL)return ans;
        queue<pair<Node*,int> >q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            Node* temp=q.front().first;
            int hz=q.front().second;
            q.pop();
            
                res[hz]=temp->data;
            
            if(temp->left)q.push(make_pair(temp->left,hz-1));
            if(temp->right)q.push(make_pair(temp->right,hz+1));

        }
        for(auto i:res){
            ans.push_back(i.second);
        }
        return ans;
    }
};