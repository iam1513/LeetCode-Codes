class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        
        vector<int> graph[numCourses];
        
        for(auto nei : prerequisites){
            graph[nei[1]].push_back(nei[0]); // As we have 0 ---> 1
        }
        
        vector<int> inDeg(numCourses,0);
        
        
        for(int i = 0; i <n; i++ ){
            inDeg[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        vector<bool> visited(numCourses,false);
        
        for(int i = 0; i <numCourses; i++ ){
            if(inDeg[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited[node] = true;
            for(int i = 0; i < graph[node].size(); i++){
                inDeg[graph[node][i]]--;
                if(inDeg[graph[node][i]] == 0 && visited[graph[node][i]] == false){
                    q.push(graph[node][i]);
                    visited[graph[node][i]] = true;
                }
            }
        }
        
        for(int i = 0; i < numCourses; i++){
            if(inDeg[i] > 0){
                return false;
            }
        }
        
        return true;
    }
};