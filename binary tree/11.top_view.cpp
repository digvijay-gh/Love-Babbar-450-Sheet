class Solution
{
    public:
     
    void pre(map<int,map<int,int> >& m,Node* root,int vL,int hL){
        if(root==NULL)return ;
        if(m.find(vL)==m.end() || m[vL].find(hL)==m[vL].end()){
        m[vL][hL]=root->data;
        }
        pre(m,root->left,vL-1,hL+1);
        pre(m,root->right,vL+1,hL+1);
    }
    vector<int> topView(Node *root)
    {
        map<int,map<int,int> > m;
        pre(m,root,0,0);
        vector<int> ans;
        for(auto i:m){
            for(auto j:i.second){
                ans.push_back(j.second);
                break;
            }
        }
        
        return ans;
    }

};
// Using Inorder Trav
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int,int> res;
        vector<int> ans;
        if(root==NULL)return ans;
        queue<pair<Node*,int> >q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            Node* temp=q.front().first;
            int hz=q.front().second;
            q.pop();
            if(res.find(hz)==res.end())
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