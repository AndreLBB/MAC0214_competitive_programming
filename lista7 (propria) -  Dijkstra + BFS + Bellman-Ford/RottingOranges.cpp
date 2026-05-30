// https://leetcode.com/problems/rotting-oranges/
// multi-source bfs em que as origens são as estragadas
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int quant_boas = 0;
        queue<array<int,2>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>> d = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for (int i = 0;i<grid.size();i++){
            for (int j = 0;j<grid[0].size();j++){
                if (grid[i][j] == 1) quant_boas++;
                if (grid[i][j] == 2){
                    q.push({i,j});
                    visited[i][j] = true;
                    dist[i][j]=0;
                } 

            }
        }
        while (!q.empty()){
            array<int,2> u = q.front();
            q.pop();
            int x = u[0];
            int y = u[1];
            for (auto &dir: d){
                int dx = dir[0];
                int dy = dir[1];
                if (dx+x > grid.size()-1 ||  dx+x <0 || dy+y > grid[0].size()-1 ||  dy+y < 0 ){
                    continue;
                }
                if (grid[dx+x][dy+y]== 0){
                    continue;
                }
                else if (!visited[dx+x][dy+y]){
                    visited[dx+x][dy+y] = true;
                    quant_boas--;
                    dist[dx+x][dy+y] = dist[u[0]][u[1]] + 1;
                    q.push({dx+x, dy+y});
                }
            }
        }
        if (quant_boas> 0) return -1;
        else{
            int maior = 0;
            for (int i = 0;i<grid.size();i++){
                for (int j = 0;j<grid[0].size();j++){
                    if (dist[i][j]>maior){
                        maior = dist[i][j];
                    }
                }
            }
            return maior;
        }
    }
};
