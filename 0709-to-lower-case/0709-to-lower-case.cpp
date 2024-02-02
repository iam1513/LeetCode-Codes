class Solution {
public:
    string toLowerCase(string s) {
        string str = "";
        for(int i = 0; i < s.size(); i++){
            str+=tolower(s[i]);
        }
        
        return str;
    }
};