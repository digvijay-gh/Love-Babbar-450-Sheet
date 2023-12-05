class Solution 
{
    public:
    static bool cmp(Job& a,Job& b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        int count=0;
        int maxDead=0;
        for(int i=0;i<n;i++){
         
            maxDead=max(maxDead,arr[i].dead);
        }
         
        vector<int> jobs(maxDead,-1);
        int p=0;
        for(int i=0;i<n;i++){
            Job x=arr[i];
            for(int j=x.dead-1;j>=0;j--){
                if(jobs[j]==-1){
                    jobs[j]=x.id;
                    count++;
                    p+=x.profit;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(p);
        return ans;
        
    } 
};