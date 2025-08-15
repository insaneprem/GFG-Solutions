class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int maxsum = accumulate(begin(arr),end(arr),0);
        vector<int> dp(maxsum+1,0);
        
        dp[0] = 1;
        
        sort(begin(arr),end(arr));
        
        for(auto num:arr){
            for(int i=maxsum;i>=num;i--){
                dp[i] = dp[i] + dp[i-num];
            }
        }
        
        int cnt = 0;
        for(int i=0;i<=maxsum;i++){
            if(dp[i]>0){
                int sum1 = i;
                int sum2 = maxsum - i;
                
                if(sum1>=sum2 && (sum1-sum2 == d)){
                    cnt+=dp[i];
                }
            }
        }
        
        return cnt;
    }
};