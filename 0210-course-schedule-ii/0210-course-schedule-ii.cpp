class Solution {
public:
void convert(int V,vector<vector<int>>& pre,vector<int>adj[]){
    for(auto x:pre){
            adj[x[0]].push_back(x[1]);
    }
}
    vector<int> findOrder(int V, vector<vector<int>>& pre) {
             vector<int> adj[V];
          convert(V,pre,adj);


          vector<int>indegree(V,0);
	    
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(!indegree[i])
	        q.push(i);
	    }
	    vector<int>topo;
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(!indegree[it]){
	                q.push(it);
	            }
	        }
	    }
	    reverse(topo.begin(),topo.end());
	    if(topo.size()==V) return topo;
        else return {};
    }
};