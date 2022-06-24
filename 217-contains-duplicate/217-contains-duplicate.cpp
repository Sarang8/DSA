class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>m;
        
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        
        for(auto it:m){
            if(it.second>=2)
                    return true;
           // m.erase(it);
        }
        return false;
        
    }
};