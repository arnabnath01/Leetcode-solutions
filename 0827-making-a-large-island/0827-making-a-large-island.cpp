class DisJointSet{
public:
    vector<int> parent,rank,size;
    DisJointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

   
   // time complexity: O(4*alpha) ~ O(4) ~ O(1
    int Find(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=Find(parent[u]);    // path compression
    }



    void Rank(int u,int v){
        int up=Find(u);
        int vp=Find(v);
        if(up==vp) return ;

        if(rank[up]<rank[vp]){
            parent[up]=vp;
        }
        else if(rank[up]>rank[vp]){
            parent[vp]=up;
        }
        else{   // equal rank
        parent[up]=vp;
        rank[vp]++;
        }

    }


        void Size(int u,int v){
        int up=Find(u);
        int vp=Find(v);
        if(up==vp) return ;
        
        if(size[up]<size[vp]){
            parent[up]=vp;
            size[vp]+=size[up];
        }
        else{
            parent[vp]=up;
            size[up]+=size[vp];
        }
        
        }

};


class Solution {

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        // int m=grid[0].size();
        DisJointSet ds(n*n);
        int mx=0;
        // first conncting all the pre-grouped ones 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int dx[]={1,0,0,-1};
                    int dy[]={0,-1,1,0};
                    
                    for(int x=0;x<4;x++){
                        int adjr=i+dx[x];
                        int adjc=j+dy[x];
                        if((adjc<n && adjr<n && adjc>=0 && adjr>=0) && grid[adjr][adjc]==1){
                            int adjNode=i*n+j;
                            int adjNodeNo=adjr*n+adjc;

                                ds.Size(adjNode,adjNodeNo);
                        }
                    }
                }   
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                continue;

                    int dx[]={1,0,0,-1};
                    int dy[]={0,-1,1,0};
                    set<int>components;
                    for(int x=0;x<4;x++){
                        int adjr=i+dx[x];
                        int adjc=j+dy[x];
                        if((adjc<n && adjr<n && adjc>=0 && adjr>=0) && grid[adjr][adjc]==1){
                            components.insert(ds.Find(adjr*n+adjc));    // ading the parents of the corrresponding cell number
                        }
                    }

                     int totSize=0;
                        for(auto it:components){
                            totSize+=ds.size[it];
                        }
                        mx=max(mx,totSize+1);
            }
        }
       

        for(int cellNo=0;cellNo<n*n;cellNo++){
            mx=max(mx,ds.size[ds.Find(cellNo)]);
        }
        return mx;
    }
};