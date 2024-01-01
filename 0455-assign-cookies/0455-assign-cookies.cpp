class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0) return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int ptr1 = 0; int ptr2 = 0; int cnt = 0;
        while(ptr1<g.size() && ptr2<s.size()){
            if(g[ptr1] <= s[ptr2]){

                cnt++;
                ptr1++;ptr2++;
            }
            else{
                ptr2++;
            }
        }

        return cnt;
    }
};