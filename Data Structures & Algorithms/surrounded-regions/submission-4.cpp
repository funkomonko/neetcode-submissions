class Solution {
public:
    int ROW, COL;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        ROW = board.size(); COL = board[0].size();
        vector<vector<bool>> connect(ROW, vector<bool>(COL, false));
        for(int i = 0; i<ROW; i++){
            if(board[i][0] == 'O'){
                dfs(i, 0, board, connect);
            }
        }
        for(int i = 0; i < ROW; i++){
            if(board[i][COL-1] == 'O'){
                dfs(i, COL-1, board, connect);
            }
        }
        for(int i = 0; i < COL; i++){
            if(board[0][i] == 'O'){
                dfs(0, i, board, connect);
            }
        }
        for(int i = 0; i < COL; i++){
            if(board[ROW-1][i] == 'O'){
                dfs(ROW-1, i, board, connect);
            }
        }

        for(int i = 1; i<ROW ; i++){
            for(int j = 1; j<COL ; j++){
                if(!connect[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>> &connect){
        connect[i][j] = true;
        for (auto [dr, dc] : directions) {
            int nr = i + dr, nc = j + dc;
            if (nr >= 0 && nr < ROW && nc >= 0 && nc < COL && !connect[nr][nc] && board[nr][nc] == 'O') {
                dfs(nr, nc, board, connect);
            }
        }
    }
};
