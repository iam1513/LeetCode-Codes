class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        
//           for(int i = 0 ;i < n; i++){
//               System.out.print(nums[i] + " ");
//           }
        
        
        int maxi = 0;
        int num = nums[0];
        int maxe = 0;
        int maxEle = nums[0];
        
        for (int i = 0; i < n; i++){

            if(num == nums[i]){
                maxe++;
            }
           else {

                if (maxe > maxi) {
                    maxi = maxe;
                    maxEle = num;
                }

                maxe = 1; 
                num = nums[i];
            }
        }
         if(maxe > maxi){
               maxEle = num;
            }
        
        return maxEle;
    }
}