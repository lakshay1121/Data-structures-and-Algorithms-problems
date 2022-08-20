
//tc - O(n)
//sc - O(n)

//just do a level order traversal , and reverse the data structure and return the , ans[0][0] , this will be the answer.





class Solution {
public:
    
    vector<vector<int>> levelOrder(TreeNode* root,vector<vector<int>> &ans){
        
           
      
        
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            
           vector<int> level;
            
            for(int i = 0 ; i < size ; i++){
                
                
                
                  TreeNode* node = q.front();
                
                  q.pop();
                
                  if(node -> left != NULL) q.push(node -> left);
                
                  if(node -> right != NULL) q.push(node -> right);
                
                  level.push_back(node -> val);
            }
            
 
            
            ans.push_back(level);
        }
        
       
      
        return ans;
    }

    
    int findBottomLeftValue(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        levelOrder(root ,ans);
        
        reverse(ans.begin() , ans.end());
        
        return ans[0][0];
        
        
        
    }
      
};
