class Solution {
public:
    int numberOfBeams(std::vector<std::string>& bank) {
        int r = bank.size();
        int c = bank[0].size();
        int cnt = 0;
        std::vector<int> ans;

        for (int i = 0; i < r; i++) {
            cnt = 0;
            for (int j = 0; j < c; j++) {
                if (bank[i][j] == '1') {
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }

        int sol = 0;
        int prev = 0;
        
        for(int i = 0; i < r; i++){
            if(ans[i] != 0){
                sol += ans[i]*prev;
                prev = ans[i];
            }
        }

        return sol;
    }
};