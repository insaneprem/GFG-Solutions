class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
        // xor -> 1 2 3 4
        
        int xr = 0;
        for(int i=1;i<=n;i++) xr^=i;
        
        xr ^= n;
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(i == xr) continue;
            ans.push_back(i);
        }
        
        return ans;
    }
};
