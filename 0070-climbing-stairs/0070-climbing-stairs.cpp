class Solution {
public:

    vector<int> dp;

    int f(int i , int n){
        // Base case
        if(i == n) return 1;
        // If its at last step and then it takes 2 steps
        if(i>n) return 0;
        if(dp[i] != -1) return dp[i];

        return dp[i] = f(i+1,n) + f(i+2,n);
    }

    int climbStairs(int n) {
        dp.clear();
        dp.resize(50,-1);
        return f(0,n);

    }
};