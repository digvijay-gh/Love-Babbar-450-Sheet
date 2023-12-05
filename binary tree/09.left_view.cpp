void pre(map<int,int>& mapping,Node* root,int level){
        if(root==NULL)return ;
        if(mapping.find(level)==mapping.end())
        mapping[level]=root->data;
        pre(mapping,root->left,level+1);
        pre(mapping,root->right,level+1);
    }
vector<int> leftView(Node *root)
{
        map<int,int> mapping;
        pre(mapping,root,0);
        vector<int> ans;
        for(const pair<int,int>& p:mapping){
            ans.push_back(p.second);
        }
        return ans;
}