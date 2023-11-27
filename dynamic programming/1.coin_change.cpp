class Solution {
public:
    int rec(vector<int>& coins,int amount){
        if(amount<0)return INT_MAX;
        if(amount==0){
            return 0;
        }
        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int c= rec(coins,amount-coins[i]);
            if(c!=INT_MAX)
            ans=min(ans,1+c);
        }
        return ans;
    }
    int mem(vector<int>& coins,int amount,vector<int>& dp){
        if(amount<0)return INT_MAX;
        if(amount==0){
            return 0;
        }
        if(dp[amount]!=-1)return dp[amount];
        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int c= mem(coins,amount-coins[i],dp);
            if(c!=INT_MAX)
            ans=min(ans,1+c);
        }
        dp[amount]=ans;
        return dp[amount];
    }
    int tab(vector<int>& coins,int amount){
        int n=coins.size();
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
             
            for(int j=0;j<n;j++){
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX)
                
                 
                dp[i]=min( dp[i] , 1 + dp[ i - coins[j] ] );
            }
             
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans=rec(coins,amount);
        // vector<int> dp(amount+1,-1);
        // int ans=mem(coins,amount,dp);
        int ans=tab(coins,amount);
        return(ans==INT_MAX)?  -1:  ans;
    }
};