class Solution {
public:
    int minBitFlips(int start, int goal) {
        long long res = start ^ goal;

        int  cnt =0;

        while(res!=0){
            if((res & 1)==1) cnt++;
            res>>=1;
        }

        return cnt;
    }
};