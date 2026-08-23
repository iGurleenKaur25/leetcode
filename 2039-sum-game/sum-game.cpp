class Solution {
public:
    bool sumGame(string num) {

        int leftSum =0;
        int rightSum=0;
        int left =0;
        int right=0;
        int n= num.size();

        for(int i =0 ; i < n ; i++){
            if(num[i] == '?'){
                if(i < n/2){
                    left++;
                }else{
                    right++;
                }
            }else{
                if(i < n/2){
                    leftSum +=num[i] -'0';
                }else{
                    rightSum += num[i] -'0';
                }
            }
        }
    return 2*(leftSum -rightSum)  != 9 * (right -left);
        
    }
};