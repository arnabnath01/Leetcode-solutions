class Solution {

bool possible(vector<int> arr,int day, int m, int k)
{
    int n=arr.size();
    int noOfBq=0;
     int cnt=0;
    for(int i=0;i<n;i++)
    {
       
        if(arr[i]<=day)
        {
            cnt++;
        }
        else
        {
            noOfBq+=cnt/k;
            cnt=0;
        }
        

    }
    noOfBq+=cnt/k;
    
    return noOfBq>=m;
}

public:

    int minDays(vector<int>& arr, int m, int k) {


        int s = *min_element(arr.begin(),arr.end());
        int e = *max_element(arr.begin(),arr.end());
        // for(int i=mini;i<=maxi;i++)
        int ans=-1 ;
        while(s<=e)
        {
            int mid = (s+e)/2;
          if(possible(arr,mid,m,k)) 
          {
              ans=mid;
              e=mid-1;
          }
          else s=mid+1;
         
        }
        return ans; 
    }
};