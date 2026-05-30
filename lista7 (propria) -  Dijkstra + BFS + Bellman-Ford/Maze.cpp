// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<array<int,2>> q;
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size()));
        vector<vector<int>> dist(maze.size(), vector<int>(maze[0].size()));
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        dist[entrance[0]][entrance[1]] = 0;
        vector<vector<int>> d = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while (!q.empty()){
            array<int,2> u = q.front();
            q.pop();
            int x = u[0];
            int y = u[1];
            for (auto &dir: d){
                int dx = dir[0];
                int dy = dir[1];
                if (dx+x > maze.size()-1 ||  dx+x <0 || dy+y > maze[0].size()-1 ||  dy+y < 0 ){
                    continue;
                }
                if (maze[dx+x][dy+y]== '+'){
                    continue;
                }
                else if (!visited[dx+x][dy+y]){
                    if (dx+x == 0 || dx+x == maze.size()-1 || dy+y == 0 || dy+y == maze[0].size()-1){
                        return dist[u[0]][u[1]] + 1;
                    }
                    else{
                        visited[dx+x][dy+y] = true;
                        dist[dx+x][dy+y] = dist[u[0]][u[1]] + 1;
                        q.push({dx+x, dy+y});
                    }
                }
            }
        }
        return -1;
    }
};
