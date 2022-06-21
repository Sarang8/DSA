// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1e9+7;
    int solve(int n, int r, vector<vector<int>>&dp){
        
        if(n==0 or r==0){
            return 1;
        }
        if(n==r){
            return 1;
        }
        if(dp[n][r]!=-1){
            return dp[n][r];
        }
        
        int x = solve(n-1, r-1, dp);
        int y = solve(n-1, r, dp);
        return dp[n][r] = (x+y)%mod;
    }

    int nCr(int n, int r){
        // code here
        if(n<r) return 0;
       vector<vector<int>>dp(n+1, vector<int>(r+1, -1));
       return solve(n, r, dp);
       
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends