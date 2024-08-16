class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int stored=0;
        int lmax=0,rmax=0,l=0,r=n-1;
        while(l<r){
            if(height[l]<=height[r])
            {
               if(lmax>height[l]){
                stored+=lmax-height[l];
            }else{
                lmax=height[l];
            }
            l++; 
            }
            
        else{
             if(rmax>height[r]){
                  stored+=rmax-height[r];
            }
            else{
                rmax=height[r];
            }
            r--;
        }
           
        }

        return stored;
    }
};