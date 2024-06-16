class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int i=0,output=0,upto=0;
        int N = nums.size();
        while(upto<n){

            if(i<N && nums[i]<=upto+1){
                upto+=nums[i];
                i++;
            }else{
                output++;
                upto+=upto+1;
            }
        }

        return (int)output;
    }
};