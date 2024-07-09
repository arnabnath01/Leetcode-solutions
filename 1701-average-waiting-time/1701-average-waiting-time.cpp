class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wait=(double)customers[0][0],ans=0;

        for(int i=0;i<customers.size();i++){
            int arr=customers[i][0];
            int time=customers[i][1];
            
            if(ans<arr){
                wait=max(wait,(double)arr);
                wait+=time;
                ans+=(wait-arr);
            }
            else{
                wait+=time;
                 ans+=(wait-arr);
            }
        }



        return ans/customers.size();
    }
};