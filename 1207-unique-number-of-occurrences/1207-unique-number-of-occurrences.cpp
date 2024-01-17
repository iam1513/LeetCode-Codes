class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int,int> m;
        
        for(auto ele: arr){
            m[ele]++;
        }
        
        vector<int> nums;
        
        for(auto ele:m){
            nums.push_back(ele.second);
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                return false;
            }
        }
        
        return true;
    }
};