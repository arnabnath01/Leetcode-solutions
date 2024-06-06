class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        if(hand.size()%k) return false;

        // sort(hand.begin(),hand.end());

        map<int,int>mp;
        for(auto x:hand){
            mp[x]++;
        }
        // create a min heap to store the it.firsts
       priority_queue<int,vector<int>,greater<int>>pq;

       for(auto x:mp)
       pq.push(x.first);

        if(mp[pq.top()]>1) return false;

       
        

        while(!pq.empty())
        {
             int temp=pq.top();

             for(int i=0;i<k;i++){
                int card = temp+i;
                
                   
                if(mp[card]==0) return false;
                 mp[card]--;
                 if(mp[card]==0) {
                   if(card!=pq.top()) return false; 
                    pq.pop();
                 }
             }

            
        }
       

       return true;



    }
};