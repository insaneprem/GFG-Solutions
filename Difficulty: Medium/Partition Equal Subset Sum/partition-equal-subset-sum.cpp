//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        
        // code here
        int sum=accumulate(arr.begin(),arr.end(),0);
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool> (sum+1,0));
        
        dp[0][0]=1,dp[0][arr[0]]=1;
        for(int i=1;i<arr.size();i++){
            for(int j=0;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(j-arr[i]>=0) dp[i][j]=dp[i][j]||dp[i-1][j-arr[i]];
            }
        }
        
        return sum%2 == 0 && dp[n-1][sum/2];
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends