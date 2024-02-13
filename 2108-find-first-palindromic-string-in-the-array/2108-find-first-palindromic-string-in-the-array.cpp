class Solution {
public:
    
    bool chck(string &s){
        int ptr1 = 0; int ptr2 = s.size()-1;
        while(ptr1<ptr2){
            if(s[ptr1] != s[ptr2]){
                return false;
            }
            ptr1++;
            ptr2--;
        }
        
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        for(int i = 0;i < words.size();i++){
            if(chck(words[i])){
                return words[i];
            }
        }
        return "";
    }
};