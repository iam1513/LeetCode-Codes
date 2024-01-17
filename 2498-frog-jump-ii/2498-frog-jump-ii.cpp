class Solution {
public:
    int maxJump(vector<int>& stones) {
        // Intuition : We have to go and come back, so we have to leave a stone to comeback. 
        // We will have to make a alternate jump at least once.
        // So, calculate maximum among those jumps.
        int ans = stones[1] - stones[0];
        int i = 2;
        while(i<stones.size()){
            ans = max(ans,(stones[i]-stones[i-2]));
            i++;
        }
        
        
        return ans;
    }
};

// tried testcases : [0,2,100,102]
// [0,1,5,6,7]