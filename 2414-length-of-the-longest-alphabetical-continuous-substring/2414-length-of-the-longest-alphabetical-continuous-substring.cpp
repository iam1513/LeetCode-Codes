class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        
        int cnt = 1, newCnt = 1;
        
        for(int i = 0; i < s.size() - 1; i++){
            if((s[i+1] - 'a')- (s[i] - 'a')  == 1){
                cnt++;
            }            
            else{
                cnt = 1;
            }
            newCnt = max(newCnt,cnt);
        }
        
        return newCnt;
    }
};