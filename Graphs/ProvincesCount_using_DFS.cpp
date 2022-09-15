class Solution {
    
    private:
    
    void dfs(int node , vector<int> &vis , vector<vector<int>> &isConnected){
        
        vis[node] = 1;
        
        for(int j = 0 ; j < isConnected.size() ; j++){
            
            if(!vis[j] && isConnected[node][j] == 1){
                
                dfs(j , vis , isConnected);
            }
        }
    }
    
    public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
      
       int ans = 0;
        
        vector<int> vis(n , 0);
        
        for(int i = 0 ; i < n;i++){
            
             if(!vis[i]){
                 
                ans++;
                 
                 dfs(i , vis , isConnected);
             }
            
        }
        
        return ans;
       
    }
};
