class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
         
         int m=abs(n);
        while(m!=0)
        {
            if(m & 1){
                ans*=x;
                m--;
            }
            else{
              x*=x;
            m/=2;  
            }
            
        }

    if(n<0) return 1.0/ans;
        return ans;
    }
};