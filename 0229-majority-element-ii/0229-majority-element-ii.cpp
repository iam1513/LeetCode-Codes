class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Same like majority element , some advancements
        // ---> There can exist 2 elements 
        
        int n = nums.size();
        int ele1,ele2,cnt1=0,cnt2=0;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(cnt1==0 && nums[i]!=ele2){
                cnt1++;
                ele1 = nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1){
                cnt2++;
                ele2 = nums[i];
            }
            else if(ele1 == nums[i]){
                cnt1++;
            }
            else if(ele2== nums[i]){
                cnt2++;
            }
            
            else{
                cnt1--,cnt2--;
            }
        }
        
        // Verify both elements cnt 
        cnt1 = 0,cnt2 =0;
        for(int i = 0; i < n; i++){
            if(ele1 == nums[i]){
                cnt1++;
            }
            else if(ele2 == nums[i]){
                cnt2++;
            }
        }
        
        if(cnt1 > n/3){
            ans.push_back(ele1);
        }
        
        if(cnt2 > n/3){
            ans.push_back(ele2);
        }
        
        return ans;
    }
};