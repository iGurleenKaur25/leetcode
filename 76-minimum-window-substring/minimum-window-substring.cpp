class Solution {
public:
    string minWindow(string s, string t) {

        int mini = INT_MAX;
        int left =0;
        int start =0;
        unordered_map<char,int> tp;
        unordered_map<char,int> sp;
        for(char m : t){
            tp[m]++;
        }
        int have =0; 
        for(int right=0;right<s.size() ; right++){
            char c = s[right];
            sp[c]++;
            if(tp.count(c) && sp[c] == tp[c]){
                have++;
            }
            while( have == tp.size()){
                if(mini > right-left+1){
                    mini = right-left+1;
                    start = left;
                }
                if(tp.count(s[left]) && sp[s[left]] == tp[s[left]]){
                    have--;
                }
                sp[s[left]]--;
                left++;
            }
        }
        return mini == INT_MAX ? "" : s.substr(start,mini);
    }
};