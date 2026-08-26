class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int count =0;
        string ans ="";
        int left =0;
        for(int i =0; i <s.size() ; i++){
            if(s[i] == '1'){
                count++;
            }
            while(count> k){
               if(s[left] == '1'){
                 count--;
               }
                left++;
             
            }

            if(count ==k){
                while(count == k && s[left] == '0'){
        left++;
    }
                string current = s.substr(left, i - left + 1);
                if( ans.empty() ||  current.length() < ans.length() || ans.length() == current.length()&& current < ans ){
                    ans = current;
                }
            }
        }
        
        return ans;
        
    }
};