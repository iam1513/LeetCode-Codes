class Solution {
    
    boolean chck(String s){
        int ptr1 = 0; 
        int ptr2 = s.length()-1;
        while(ptr1<ptr2){
            if(s.charAt(ptr1) != s.charAt(ptr2)){ //  Keep in mind
                return false;
            }
            ptr1++;
            ptr2--;
        }
        
        return true;
    }
    
    public String firstPalindrome(String[] words) {
        for(int i = 0;i < words.length;i++){
            if(chck(words[i])){
                return words[i];
            }
        }
        return "";
    }
}

 
    