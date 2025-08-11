class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<int> dp(sum+1,0);
        dp[0]=1;
        vector<int> v;
        
        for(auto &e:arr){
           v.clear();
 
           for(int i=0;i<=sum;i++) if(dp[i] && i+e<=sum) v.push_back(i+e);
        
           for(auto i:v) dp[i]=1;
        }
    
        return dp[sum];
    }
};