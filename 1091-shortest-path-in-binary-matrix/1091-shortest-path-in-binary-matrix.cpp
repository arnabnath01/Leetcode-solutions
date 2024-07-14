class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1){
            return grid[0][0]==0 ? 1 : -1;
        }
        vector<vector<int>>vis(n,vector<int>(n,INT_MAX));

        int dx[]={-1,-1,0,1,1,1,0,-1};
        int dy[]={0,1,1,1,0,-1,-1,-1};

        if(grid[0][0]) return -1;
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        vis[0][0]=0;

        while(!q.empty())
        {
            int dis=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();

            // if(x==n-1 && y==n-1)
            // return dis+1;
            
            for(int i=0;i<8;i++){
                
                    int newi=x+dx[i];
                    int newj=y+dy[i];
                    if(newi<n && newi>=0 && newj>=0 && newj<n && grid[newi][newj]==0
                    && dis+1<vis[newi][newj]
                    ){
                         vis[newi][newj]=dis+1;
                         
                        if(newi==n-1 && newj==n-1)
                             return dis+1;
                             
                    q.push({dis+1,{newi,newj}});
                    }
                
            }

            // for(auto x:vis){
            //     for(auto y:x){
            //         cout<<y<<" ";

            //     }
            //     cout<<endl;
            // }

        }

        return -1;
    }
};