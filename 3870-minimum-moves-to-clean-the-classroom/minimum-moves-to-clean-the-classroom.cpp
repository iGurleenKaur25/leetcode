class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int n = classroom.size();
        int m = classroom[0].size();

        int sr, sc;
        int trashCount = 0;

        // Find starting position and count trash
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    trashCount++;
                }
            }
        }

        // All trash collected
        int allDone = (1 << trashCount) - 1;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            n,
            vector<vector<vector<bool>>>(
                m,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << trashCount, false)
                )
            )
        );

        // row, col, current energy, mask, moves
        queue<tuple<int, int, int, int, int>> q;

        q.push({sr, sc, energy, 0, 0});
        visited[sr][sc][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [r, c, currEnergy, mask, moves] = q.front();
            q.pop();

            // All trash collected
            if (mask == allDone) {
                return moves;
            }

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                // Outside grid
                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                // Wall
                if (classroom[nr][nc] == 'X')
                    continue;

                // Need energy to move
                if (currEnergy == 0)
                    continue;

                int newEnergy = currEnergy - 1;
                int newMask = mask;

                // Trash
                if (classroom[nr][nc] == 'L') {

                    // Find which trash this is
                    int id = 0;

                    for (int i = 0; i < nr; i++) {
                        for (int j = 0; j < m; j++) {
                            if (classroom[i][j] == 'L')
                                id++;
                        }
                    }

                    for (int j = 0; j < nc; j++) {
                        if (classroom[nr][j] == 'L')
                            id++;
                    }

                    newMask = newMask | (1 << id);
                }

                // Energy reset cell
                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                if (!visited[nr][nc][newEnergy][newMask]) {

                    visited[nr][nc][newEnergy][newMask] = true;

                    q.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask,
                        moves + 1
                    });
                }
            }
        }

        return -1;
    }
};