class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {

        int n = grid.size();

        if (grid[0][0] != 0)
            return false;

        vector<pair<int,int>> pos(n * n);

        // Store position of every number
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }

        // Check every consecutive move
        for (int i = 1; i < n * n; i++) {

            int x1 = pos[i - 1].first;
            int y1 = pos[i - 1].second;

            int x2 = pos[i].first;
            int y2 = pos[i].second;

            int dx = abs(x1 - x2);
            int dy = abs(y1 - y2);

            if (!((dx == 2 && dy == 1) || (dx == 1 && dy == 2)))
                return false;
        }

        return true;
    }
};