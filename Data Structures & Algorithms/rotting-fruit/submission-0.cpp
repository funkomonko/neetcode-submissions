class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;
    
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int time = 0;
        int fresh_count = 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh_count++;
                }
            }
        }
        
        while (!q.empty() && fresh_count > 0) {
            int size = q.size();
            time++; 
            
            for(int iter = 0; iter < size; iter++) {    
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int r = row + dirs[d][0];
                    int c = col + dirs[d][1];

                    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1) {
                        continue;
                    }

                    grid[r][c] = 2; 
                    fresh_count--;
                    q.push({r, c});
                }
            }
        }

        return fresh_count == 0 ? time : -1;
    }
};