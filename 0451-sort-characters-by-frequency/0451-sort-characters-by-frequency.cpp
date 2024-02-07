class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        multimap<int, char, greater<int>> mm; // Multimap will store in sorted order , int should be first always

        for (auto ele : s) {
            m[ele]++;
        }
        for (auto ele : m) {
            mm.insert({ele.second, ele.first});
        }

        string str = "";
        for (auto i = mm.begin(); i != mm.end(); ++i) {
            for (int j = 0; j < i->first; j++) {
                str += i->second;
            }
        }

        return str;
    }
};