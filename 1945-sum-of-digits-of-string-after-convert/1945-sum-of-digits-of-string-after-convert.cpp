class Solution {
public:
    int getLucky(string s, int k) {
        string nums="";
        for(auto it:s){
            int tmp=it-'a';
            ++tmp;
            nums+=to_string(tmp);
        }
        // Convert to an integer
        long long number;
        if (nums.size() <= 9) {  // Fits into an int
            number = stoi(nums);
        } else {  // Larger than int, use stoll for long long
            number = stoll(nums);
        }
        int res=0;
        while(k--){
         int sum=0;
         for(auto x:nums){
            sum+=x-'0';
         }
         res=sum;
         nums=to_string(sum);
        }

        

        return res;
    }
};