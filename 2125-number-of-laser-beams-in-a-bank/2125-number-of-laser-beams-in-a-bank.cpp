class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int r = bank.size();
        int c = bank[0].size();

        int prev = 0;
        int ans = 0;
        for(int i = 0; i < r; i++){
            int cnt = 0;
            for(int j = 0; j < c; j++){
                
                if(bank[i][j] == '1'){
                    cnt++;
                }           
            }
            if(cnt!=0){
                ans += (prev * cnt);
                prev = cnt;
            }
            
        }
        
        return ans;
    }
};