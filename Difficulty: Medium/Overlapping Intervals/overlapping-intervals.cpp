class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(begin(arr),end(arr),[](auto a,auto b){
            return a[0]<b[0];
        });
        
        
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        
        int n=arr.size();
        
        for(int i=1;i<n;i++){
            if(ans.back()[1] >= arr[i][0]){
                ans.back()[1] = max(ans.back()[1],arr[i][1]);
            }
            else ans.push_back(arr[i]);
        }
        
        return ans;
    }
};