class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;

        int n = strs.size();

        for(int i = 0; i < n; i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());

            if(m.find(temp)!=m.end()){
                m[temp].push_back(strs[i]);

            }
            else{
                vector<string> temp1;
                m[temp] = temp1;
                m[temp].push_back(strs[i]);
            }
        }

        for(auto ele:m){
            ans.push_back(ele.second);
        }

        return ans;
    }
};