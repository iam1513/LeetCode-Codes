class Solution {
public:
    bool halvesAreAlike(string s) {
        
        transform(s.begin(), s.end(), s.begin(), ::tolower); // Converting string to lowercase
        int cnt1 = 0; int cnt2 = 0;
        int ptr1 = 0; int ptr2 = s.size() - 1;
        
        while(ptr1<ptr2){
            if(s[ptr1] == 'a' || s[ptr1] == 'e' || s[ptr1] == 'i' || s[ptr1] == 'o' || s[ptr1] == 'u' ){
                cnt1++;
            }
            if(s[ptr2] == 'a' || s[ptr2] == 'e' || s[ptr2] == 'i' || s[ptr2] == 'o' || s[ptr2] == 'u' ){
                cnt2++;
            }
            ptr1++;ptr2--;
        }
        
        if(cnt1!=cnt2) return false;
        
        return true;
    }
};