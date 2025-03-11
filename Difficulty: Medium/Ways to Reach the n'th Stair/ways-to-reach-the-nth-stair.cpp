//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1);
        
        for(int i=0;i<=n;i++){
            if(i<=2) dp[i]=i;
            else{
                dp[i]+=dp[i-2];
                dp[i]+=dp[i-1];
            }
        }
        
        return dp[n];
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends