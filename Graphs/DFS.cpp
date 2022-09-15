  void dfs(vector<int> adj[] , int node, int vis[] , vector<int> &ans){
      
      
       vis[node] = 1;
       
       ans.push_back(node);
       
       //traversing all the neighbours.
       
       for(auto it: adj[node]){
           
           if(!vis[it]){
             
               dfs(adj , it , vis, ans);
               
           }
       }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> ans;
        
        int vis[V] = {0};
        
        int start = 0 ;
        
        dfs(adj , start ,vis , ans);
        
        return ans;
    }
