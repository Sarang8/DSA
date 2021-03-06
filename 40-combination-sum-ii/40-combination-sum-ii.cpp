class Solution {
public:
    void solve(int ind,int target,vector<int>&ds,vector<vector<int>>&ans,vector<int>& candidates){
            
        if(target==0){
            ans.push_back(ds);
            return;
        }
        
        
        for(int i=ind; i<candidates.size(); i++){
            
            if(i>ind && candidates[i-1]==candidates[i]) continue;
            
            if(candidates[i]>target) return;
            
            ds.push_back(candidates[i]);
            solve(i+1, target-candidates[i], ds,ans,candidates);
            ds.pop_back();
        }   
    }
    
    
    
    
    
    
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>>ans;
        vector<int>ds;
        
        solve(0, target, ds, ans, candidates);
        
        return ans;
        
        
    }
};