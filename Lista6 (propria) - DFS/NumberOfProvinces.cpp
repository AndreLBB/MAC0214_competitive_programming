//https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    void DFS(int u, vector<bool>& visited,vector<vector<int>>& isConnected){
        visited[u] = true;
        for (int i = 0;i<isConnected.size();i++){
            if (isConnected[u][i] == 1 && !visited[i]){
                DFS(i, visited, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size());
        int num_provincias = 0;
        for (int i = 0;i<isConnected.size();i++){
            if (!visited[i]){
                DFS(i, visited, isConnected);
                num_provincias++;
            }
        }
        return num_provincias;
    }
};
