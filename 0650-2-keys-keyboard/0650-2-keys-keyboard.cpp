class Solution {
public:
    int largestDiv(int n){
          int i;
        for (i = 2; i <=sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return n/i;
            }
        }
        return n;
    }
    int minSteps(int n) {

    if(n==1) return 0;
    if(n==2) return 2;
     int div=largestDiv(n);

     if(div==n) return n;

     return n/div + minSteps(div);

    }
};