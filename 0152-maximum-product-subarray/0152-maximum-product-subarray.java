class Solution {
    public int maxProduct(int[] nums) {
        int maxProd = Integer.MIN_VALUE;
        int newProd = 1;
        
        for(int i = 0; i < nums.length; i++){
            newProd *= nums[i];
            maxProd = Math.max(maxProd,newProd);
            if(newProd == 0){
                newProd = 1;
            }
        }
        
        newProd = 1;
        for(int i = nums.length -1; i >=0 ; i--){
            newProd *= nums[i];
            maxProd = Math.max(maxProd,newProd);
            if(newProd == 0){
                newProd = 1;
            }
        }
        
        return maxProd;
    }
}