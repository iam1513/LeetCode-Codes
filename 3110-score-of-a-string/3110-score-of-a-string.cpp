class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        
        for(int i = 0; i < s.size()-1; i++){
            int k = (int(s[i+1])-int(s[i]));
            if(k < 0){
                
                ans-= k;
                
            }
            else{
                ans+=k;
            }
            
        }
        
        return ans;
    }
};