class Solution {
public:

void solve(vector<int>& candidates, int target, int index,
               vector<int>& path, vector<vector<int>>& ans){
       if (target == 0) {
            ans.push_back(path);
            return;
        }

        if (target < 0) {
            return;
        }
        for(int i =index; i < candidates.size(); i++){
           
            path.push_back(candidates[i]);
            solve(candidates , target-candidates[i] , i , path , ans);
            path.pop_back();
        }

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       
        vector<vector<int>> ans;
        vector<int> path;

        solve(candidates, target, 0, path, ans);

        return ans;
        }
};