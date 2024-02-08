class Solution {
    public boolean isPalindrome(int x) {
        
        if(x<0){
            return false;
        }
        
        String st="";
        while(x>0){
            st+=x%10;
            x/=10;
        }
        
        int ptr1 = 0; int ptr2 = st.length() - 1;
        
        while(ptr1<ptr2){
            if(st.charAt(ptr1) == st.charAt(ptr2)){
                ptr1++;ptr2--;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
}