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
    int makeConnected(int n, vector<vector<int>>& connections) {
        // if(connections.size()!=n-1) return -1;
        DisJointSet ds(n);
        int extraEdges=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.Find(u)==ds.Find(v)){
                extraEdges++;
            }else{
                ds.Size(u,v);
            }
        }

        //now find nmber of provinces; if 
        // provinces-1 <= extraEdges

        //1  -- 2 -- 3 -- 4 -- 5 -- 6


        int provinces=0;

        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)
            provinces++;
        }
        
        // for(int i=0;i<=n;i++){
        //    cout<<ds.parent[i]<<" "; 
        // }
        // cout<<endl;

        //  for(int i=0;i<=n;i++){
        //    cout<<ds.size[i]<<" "; 
        // }
        // cout<<endl;

         
        if(extraEdges>=provinces-1){
            return provinces-1;
        }
        return -1;
    }
};