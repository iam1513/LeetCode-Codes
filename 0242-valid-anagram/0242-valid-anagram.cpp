class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(t.begin(),t.end());
        sort(s.begin(),s.end());

// APPROACH 1 
        if(s.size() != t.size()){
            return false;
        }

        for(int i = 0; i < s.size(); i++){
            char temp1 = s[i];
            char temp2 = t[i];
            if(temp1!=temp2){
                return false;
            }
        }
        return true;

// APPROACH 2
        // return s==t;

//  APPROACH 3
//         unordered_map<char,int> m1;
//         unordered_map<char,int> m2;

//         for(auto ele:t){
//             m1[ele]++;
//         }

//         for(auto ele:s){
//             m2[ele]++;
//         }

//         return m1 == m2;

    }  
};