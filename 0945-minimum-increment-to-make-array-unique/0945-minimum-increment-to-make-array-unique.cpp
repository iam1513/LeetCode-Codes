class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        
        int maxi = 0 ;
        int cnt = 0;
        
        for(int i = 0;i < n; i++){
            maxi = max(maxi,nums[i]);
        }
        
        vector<int> freq(n+maxi+10,0);
        
        for(int i = 0;i < n; i++){
            freq[nums[i]]++;
        }
        
        for(int i = 0; i < freq.size(); i++){
            if(freq[i] <=1) continue;
            
            int dups = freq[i] - 1;
            freq[i+1] += dups;
            freq[i] = 1;
            cnt+=dups;
        }
        
        return cnt;
    }
    
};





// BRUTE FORCE : TLE

// class Solution {
// public:
//     int minIncrementForUnique(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         int cnt= 0 ;
        
//         for(int i = 0; i < nums.size() ; i++){
//             mp[nums[i]]++;
//         }
        
//         for(int i = 0;i < nums.size(); i++){
//             if(mp[nums[i]] > 1){
//                 int curr = nums[i];
//                 while(mp.find(curr) != mp.end()){
//                     curr++;
//                     cnt++;
//                 }
//                 mp[curr]++;
                
//             }
//             mp[nums[i]]--;
//         }
//         return cnt;
//     }
// };


