// USING STACK

class Solution {
public:
    
    void f(int i, int j, vector<string> &ans, int n,stack<char> & st){
        
        if(i==n && j == n){
            
            string str = "";
            stack<char> s = st;
            while(!s.empty()){
                str+=s.top();
                s.pop();
            }
            
            reverse(str.begin(),str.end());
            
            ans.push_back(str);
            return ;
        }
        
        
        
       if(i<n){ st.push('(');
        f(i + 1, j, ans, n, st);
        st.pop();}
        
        if(j<i){st.push(')');
        f(i, j + 1, ans, n, st);
        st.pop();}
        
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        stack<char> st;
        f(0,0,ans,n,st);
        
        return ans;
        
    }
};


// USING STRING
// class Solution {
// public:
    
//     void f(int i, int j, vector<string> &ans, int n,stack<char> & st){
        
//         if(j>i){
//             return;
//         }
        
//         if(i==n && j == n){
            
//             string str = "";
//             stack<char> s = st;
//             while(!s.empty()){
//                 str+=s.top();
//                 s.pop();
//             }
            
//             reverse(str.begin(),str.end());
            
//             ans.push_back(str);
//             return ;
//         }
        
        
        
//        if(i<n){ st.push('(');
//         f(i + 1, j, ans, n, st);
//         st.pop();}
        
//         if(j<n){st.push(')');
//         f(i, j + 1, ans, n, st);
//         st.pop();}
        
        
//     }
    
//     vector<string> generateParenthesis(int n) {
//         vector<string> ans;
//         stack<char> st;
//         f(0,0,ans,n,st);
        
//         return ans;
        
//     }
// };