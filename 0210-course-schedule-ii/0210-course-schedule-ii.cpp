class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Without maintaining visited array
        vector<int> graph[numCourses];
        vector<int> ans;
        vector<int> inDeg(numCourses, 0);
        
        for(auto nei : prerequisites){
            graph[nei[1]].push_back(nei[0]);
            inDeg[nei[0]]++;
        }
        
        queue<int> q;
        
        for(int i = 0; i < numCourses; i++){
            if(inDeg[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int neighbor : graph[node]){
                inDeg[neighbor]--;
                if(inDeg[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        
        for(int i = 0; i < numCourses; i++){
            if(inDeg[i] > 0){
                return {};
            }
        }
        
        return ans;
    }
};



// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
//         vector<int> graph[numCourses];
//         vector<bool> visited(numCourses,false);
//         vector<int> ans;
//         vector<int> inDeg(numCourses,0);
        
//         for(auto nei : prerequisites){
//             graph[nei[1]].push_back(nei[0]);
//             inDeg[nei[0]]++;
//         }
        
//         queue<int> q;
        
//         for(int i = 0; i < numCourses; i++){
//             if(inDeg[i] == 0) q.push(i);
//             // ans.push_back(i);
//         }
        
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             visited[node] = true;
//              ans.push_back(node);
//             for(int i = 0; i < graph[node].size(); i++){
//                 inDeg[graph[node][i]]--;
//                 if(inDeg[graph[node][i]] == 0 && visited[graph[node][i]] == false){
//                     q.push(graph[node][i]);
                    
//                     visited[graph[node][i]] = true;
                    
//                 }
                
//             }
//         }
        
//         for(int i = 0; i < numCourses; i++){
//             if(inDeg[i] > 0){
                
//                 return {};
//             }
//         }
        
//         return ans;
//     }
// };