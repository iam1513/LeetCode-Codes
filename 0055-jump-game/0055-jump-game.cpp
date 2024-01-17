class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Intuition : We will keep count of jumps that are remaining after jumping to a particular position.
        // If jumps rem are lower than value at the idx, we we choose the val as next jump
        int i = 1;
        int cnt = 1;
        int ans = nums[0];
        if(ans == 0 && nums.size() > 1) return false;
        while(i < nums.size()){
            
            if((ans-cnt) == 0 && nums[i] == 0 && i!=nums.size()-1 ){
                return false;
            }
            
            if((ans - cnt) < nums[i]){
                ans = nums[i];
                i++;
                cnt  = 1;
            }
            
            else{
                i++;
                cnt++;
            }
        }
        
        return true;
    }
};



// MORE OPTIMIZED : GREEDY

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int maxReach = nums[0];
//         int n = nums.size();

//         for (int i = 1; i < n; ++i) {
//             // If at any point maxReach is less than the current index, return false
//             if (maxReach < i) {
//                 return false;
//             }
            
//             // Update maxReach based on the current position
//             maxReach = max(maxReach, i + nums[i]);

//             // If maxReach is greater than or equal to the last index, return true
//             if (maxReach >= n - 1) {
//                 return true;
//             }
//         }

//         return true;
//     }
// };
