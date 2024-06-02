class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0; int rem = 0;

        for(int i = 0; i < s.size();i++){
            if(s[i] == 'E'){
                ans++;
                rem = max(ans,rem);
            }
            else{
                ans--;
            }
        }

        return rem;
    }
};