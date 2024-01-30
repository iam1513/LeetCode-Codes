class Solution {
public:
    
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o'|| ch=='u'){
            return true;
        }
        return false;
    }
    
    int maxVowels(string s, int k) {
        
        int cnt = 0, maxCnt = 0;
        
        //         for(int i = 0; i < s.size(); i++){
            
//             j = i;
            
//             while(j<k+i && j < s.size()){
//                 if((s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')){
//                     cnt++;
//                     j++;
//                 }  
                
//                 else{j++;
//                     }
            
//             }
            
//             maxCnt = max(cnt,maxCnt);
//             cnt = 0;
//         }
        
//                     return maxCnt;

        for(int i = 0; i < k; i++){
            if(isVowel(s[i]) == true){
                cnt++;
            }
        }
        
        maxCnt = cnt;
        
        for(int i = 1; i < s.size() - k + 1; i++){
            int j = i + k - 1;
            if(isVowel(s[i-1]) == true ){
                cnt = cnt - 1;
            }
            if(isVowel(s[j]) == true){
                cnt = cnt + 1;
            }
            
            maxCnt = max(cnt, maxCnt);
        }
        
        return maxCnt;
    }
};
