//https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    void DFS(int u, vector<vector<int>>& rooms, vector<bool>& visited){
        visited[u] = true;
        for (int v: rooms[u]){
            if (!visited[v]){
                DFS(v,rooms,visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // rooms[i] eh o vetor de adjacencia de i
        vector<bool> visited(rooms.size());
        DFS(0,rooms, visited);
        bool da = true;
        for (int i=0;i<rooms.size();i++){
            if (!visited[i]){
                da = false;
            }
        }
        return da;
    }
};
