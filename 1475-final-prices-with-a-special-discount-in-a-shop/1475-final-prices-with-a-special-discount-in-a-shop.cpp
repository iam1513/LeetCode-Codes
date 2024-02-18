class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        vector<int> ans;
        
        for(int i = 0; i < prices.size(); i++){
            int present = prices[i];
            for(int j = i+1; j < prices.size() ; j++){
                if(present >= prices[j]){
                    int a = present - prices[j];
                    ans.push_back(a);
                    break;
                }
                
                if(j == prices.size()-1 && present <= prices[j]){
                    ans.push_back(present);
                }
            }
            
        }
        
        ans.push_back(prices[prices.size()-1]);
        
        return ans;
    }
};