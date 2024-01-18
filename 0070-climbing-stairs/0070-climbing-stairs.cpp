// APPROACH 1

// class Solution {
// public:

//     vector<int> dp;

//     int f(int i , int n){
//         // Base case
//         if(i == n) return 1;
//         // If it is at last step and then it takes 2 steps
//         if(i>n) return 0;
//         if(dp[i] != -1) return dp[i];

//         return dp[i] = f(i+1,n) + f(i+2,n);
//     }

//     int climbStairs(int n) {
//         dp.clear();
//         dp.resize(50,-1);
//         return f(0,n);

//     }
// };


// APPROACH 2 
// class Solution {
// public:

//     vector<int> dp;

//     int f(int n){
//         // Base case
//         if(n == 0) return 1;
//         // If it is at last step and then it takes 2 steps
//         if(n<0) return 0;
//         if(dp[n] != -1) return dp[n];

//         return dp[n] = f(n-1) + f(n-2);
//     }

//     int climbStairs(int n) {
//         dp.clear();
//         dp.resize(50,-1);
//         return f(n);

//     }
// };


// APPROACH 3 : BOTTOM UP

class Solution {
public:
    
    vector<int> dp;
    
    int climbStairs(int n) {
        dp.clear();
        dp.resize(50,-1);
        
        // Corner case
        if(n == 1) return 1;
        
        dp[n-1] = 1; // Present on the top stair
        dp[n-2] = 2; // Present on the second last stair
        
        for(int i = n-3 ; i>=0 ; i--){
            dp[i] = dp[i+1] + dp[i+2];
        }
        
        return dp[0];
        
    }
};