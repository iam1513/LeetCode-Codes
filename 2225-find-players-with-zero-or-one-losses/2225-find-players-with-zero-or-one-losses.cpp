class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        vector<vector<int>> ans;
        int maxe1 = INT_MIN; int maxe2 = INT_MIN;
        
        for(int i = 0 ; i < matches.size(); i++){
            if(matches[i][0] > maxe1){
                maxe1 = matches[i][0];
            }
            
            if(matches[i][1] > maxe2){
                maxe2 = matches[i][1];
            }
        }
        
        int maxe = max(maxe1,maxe2);
        
        vector<int> a1(maxe+1,0);
        vector<int> a2(maxe+1,0);
        
        for(int i = 0 ; i < matches.size() ; i++){
            a1[matches[i][0]]++;
            a2[matches[i][1]]++;
        }
        
        vector<int> m; vector<int> n;
        
        for(int i = 1; i <= maxe; i++){
            if(a2[i] == 0 && a1[i]!=0){
                m.push_back(i);
            }
            
            if(a2[i] == 1){
                n.push_back(i);
            }
        }
        
        ans.push_back(m);
        ans.push_back(n);
        
        return ans;
    }
};