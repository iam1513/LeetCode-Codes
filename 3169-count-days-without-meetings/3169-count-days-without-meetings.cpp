class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(), meetings.end());
        
        int ans = meetings[0][0] - 1; 
        int maxi = meetings[0][1]; 
        
        for(int i = 1; i < meetings.size(); i++){
            if(meetings[i][0] > maxi + 1) {
                ans += (meetings[i][0] - maxi - 1);
            }
            maxi = max(meetings[i][1], maxi);
        }

        ans += (days - maxi);
        
        return ans;
    }
};
