class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        vector<int>ans(n, 1);
        
        //L to R
        for(int i=1; i<n; i++){
            if(ratings[i-1]<ratings[i]  &&  ans[i]<=ans[i-1]){
                ans[i] = ans[i-1]+1;
            }   
        }
        
        //R to L
        for(int i=n-2; i>=0; i--){
            
            if(ratings[i+1] < ratings[i]  &&  ans[i]<=ans[i+1]){
                ans[i] = ans[i+1]+1;
            }
        }
        
        int res=0;
        for(int i=0; i<n; i++){
            res+=ans[i];
        }
        
        return res;
    }
};