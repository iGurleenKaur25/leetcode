class Solution {
public:
    
     int n;
    vector<string> board;
    vector<vector<string>> ans;

    bool isSafe(int row, int col){
        for(int i = row -1 ; i >= 0 ; i--){
           if(board[i][col] =='Q')
            return false;
        }

        for(int i = row -1 , j=col -1; j>=0 && i>=0;i--,j--){
              if(board[i][j] =='Q')
            return false;
        }
        for(int i = row -1 , j=col +1; j <n && i>=0;i--,j++){
              if(board[i][j] =='Q')
            return false;
        }
    return true;
    }

    
    void solve(int row){
        if(row == n){
            ans.push_back(board);
            return;
        }

         for (int col = 0; col < n; col++) {

            if (isSafe(row, col)) {

                // Choose
                board[row][col] = 'Q';

                // Explore
                solve(row + 1);

                // Undo / backtrack
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {

         this->n = n;

        board = vector<string>(n, string(n, '.'));

        solve(0);

        return ans;

        
    }
};