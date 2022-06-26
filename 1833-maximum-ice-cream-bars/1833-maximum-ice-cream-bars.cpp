class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        int n=costs.size();
        sort(costs.begin(), costs.end());
        int ans=0;
        
        for(int i=0; i<n; i++){
           if(coins>0 && coins>=costs[i]){
               ans++;
               coins-=costs[i];
           }
        }
        return ans; 
    }
};