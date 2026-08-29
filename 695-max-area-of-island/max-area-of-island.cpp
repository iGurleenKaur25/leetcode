class Solution {
public:

    int dfs(vector<vector<int>>& grid , int r , int c ){

       grid[r][c] =0;
       int area=1;
       int dr[] = {-1,1,0,0};
       int dc[] = {0,0,-1,1};

       for(int k = 0; k < 4; k++) {

        int nr = r + dr[k];
        int nc = c + dc[k];

        if(nr >= 0 && nr < grid.size() && nc >=0 && nc <grid[0].size() && grid[nr][nc] == 1){
            area+=dfs(grid , nr,nc);
            
        }

         }

    return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        vector<vector<int>>ans;
        
        int maxArea =0;
        
        int sr = grid.size();
        int sc = grid[0].size();

        for(int i =0 ;i<sr ;i++){
            for(int j =0; j < sc;j++){
                if(grid[i][j] == 1){
                  int area = dfs(grid , i,j);
                     maxArea = max(maxArea, area);

                }
            }
        }
        return maxArea;
    }
};