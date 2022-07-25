class Solution {
public:
    string multiply(string num1, string num2) {
        
        int n=num1.size();
        int m=num2.size();
        
        if(num1=="0" or num2=="0") return "0";
        
        vector<int>ans(n+m,0);
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                
                ans[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
                ans[i+j] +=  ans[i+j+1]/10;
                ans[i+j+1] = ans[i+j+1]%10; 
            }
        }
        
        
        int i=0;
        while(i<ans.size() && ans[i]==0){
            i++;
        }
        
        string res="";
        
        while(i<ans.size()){
            res+=to_string(ans[i]);
            i++;
        }   
        
        return res;
    }
};