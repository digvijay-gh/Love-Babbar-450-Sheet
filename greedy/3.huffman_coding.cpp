class Node{
	        public:
	       
	        Node* left;
	        Node* right;
	        int freq;
	        Node(int _freq){
	            
	            freq=_freq;
	            left=NULL;
	            right=NULL;
	        }
	    };
class cmp{
    public:
    bool operator()(Node* a,Node* b){
	        return a->freq>b->freq;
	    }
};
class Solution
{
	public:
	    void pre(Node* root,vector<string>& ans,string& code){
	        if(root->left==NULL && root->right==NULL){
	            ans.push_back(code);
	            return;
	        }
	        code.push_back('0');
	        pre(root->left,ans,code);
	        code.pop_back();
	        code.push_back('1');
	        pre(root->right,ans,code);
	        code.pop_back();
	        
	    }
	    vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		     priority_queue<Node*,vector<Node*>,cmp> pq;
		     for(int i=0;i<N;i++){
		         Node* temp=new Node(f[i]);
		         pq.push(temp);
		     }
		     while(pq.size()>1){
		         Node* a=pq.top();
		         pq.pop();
		         Node* b=pq.top();
		         pq.pop();
		         Node* newNode=new Node(a->freq+b->freq);
		         newNode->left=a;
		         newNode->right=b;
		         pq.push(newNode);
		     }
		     Node* root=pq.top();
		     vector<string> ans;
		     string code="";
		     pre(root,ans,code);
		     return ans;
		}
};