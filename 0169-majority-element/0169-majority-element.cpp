class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // USING MOORE'S VOTING ALGORITHM
        int ele,cnt = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                ele = nums[i];
                cnt++;
            }
            
            else if(ele == nums[i]){
                cnt++;
            }
            
            else{
                cnt--;
            }
        }
        
        return ele;
    }
};


// APPROACH 2 : EXTRA SPACE 
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int,int> m;
//         int n = nums.size();
//         for(auto ele:nums){
//             m[ele]++;
//         }
//         for(auto ele:m){
//             if(ele.second > n/2){
//                 return ele.first;
//             }
//         }
//         return -1;
//     }
// };