class solution{
  public:
  
   bool isSafe(int newrowindex, int newcolindex, vector<vector<int>>& visited, vector<vector<int>>& m,
                int n){
        
        if((newrowindex >= 0  && newrowindex < n) && (newcolindex >= 0  && newcolindex < n) && m[newrowindex][newcolindex] == 1 &&
            visited[newrowindex][newcolindex] == 0){
                
                return true;
            }
            
            else{
                
                return false;
            }
    }
    
    
    
    void solve(vector<vector<int>>& m , int n,vector<string>& ans, int rowindex, int colindex,vector<vector<int>> visited , string paths){
        
        //base case
        
        if(rowindex == n - 1 && colindex == n - 1){
            
            //we have reached to our path
            
            ans.push_back(paths);
            return;
        }
        
        //mark visited as 1 for the current src position
        
        visited[rowindex][colindex] = 1;
        
        //down movement case
        
        int newrowindex = rowindex+1;
        int newcolindex= colindex;
        
        if(isSafe(newrowindex, newcolindex , visited ,m,n)){
            
            paths.push_back('D');
            //again call for the next one
            
            solve(m , n,ans ,newrowindex , newcolindex, visited, paths);
            
            //backtrack , pop the element that we have pushed.
            
            paths.pop_back();
        }
        
        //up movement case
        
         newrowindex = rowindex - 1;
         newcolindex= colindex;
        
        if(isSafe(newrowindex, newcolindex , visited ,m,n)){
            
            paths.push_back('U');
            //again call for the next one
            
           solve(m , n,ans ,newrowindex , newcolindex, visited, paths);
            
            //backtrack , pop the element that we have pushed.
            
            paths.pop_back();
        }
        
        
        //left movement case
        
         newrowindex = rowindex;
         newcolindex= colindex - 1;
        
        if(isSafe(newrowindex, newcolindex , visited ,m,n)){
            
            paths.push_back('L');
            //again call for the next one
            
          solve(m , n,ans ,newrowindex , newcolindex, visited, paths);
            
            //backtrack , pop the element that we have pushed.
            
            paths.pop_back();
        }
        
        //right movement case
        
         newrowindex = rowindex;
         newcolindex= colindex + 1;
        
        if(isSafe(newrowindex, newcolindex , visited ,m,n)){
            
            paths.push_back('R');
            //again call for the next one
            
            solve(m , n,ans ,newrowindex , newcolindex, visited, paths);
            
            //backtrack , pop the element that we have pushed.
            
            paths.pop_back();
        }
        
        visited[rowindex][colindex] = 0;
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        
        vector<string> ans;
        
        
        //if , m[0][0] is already 0 , that means we can not move anywhere , return the empty string.
        
        if(m[0][0] == 0){
            
            return ans;
        }
        
        
        int rowindex = 0;
        int colindex = 0;
        
        
        vector<vector<int>> visited = m;
        
        for(int i = 0; i< n;i++){
            
            for(int j = 0;j<n; j++){
                
                //marking visited as 0 , for all the indexes
                
                visited[i][j] = 0;
            }
        }
        
        
        //empty string for inserting our movements.
        
        string paths ="";
        
      solve(m , n,ans ,rowindex , colindex, visited, paths);
        
        //according to the qs , it wants the answerr to be in lexicographically manner so sort it ,before
        //returning it.
        
        sort(ans.begin() , ans.end());
        
        return ans;
        
    }
  
};
