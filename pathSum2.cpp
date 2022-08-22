class Solution {
public:
    
    void findPath(TreeNode* root , vector<int> temp , vector<vector<int>> &ans, int targetSum){
        
        if(root == NULL) return;
        
        temp.push_back(root -> val);
        
        targetSum -= root -> val;
        
        if(targetSum == 0 && !root -> left && !root -> right) ans.push_back(temp);
        
        findPath(root -> left ,temp,ans, targetSum);
        
        findPath(root -> right,temp,ans, targetSum);  
        
        
       if(targetSum > 0 && !root -> left && !root -> right){
        
         temp.pop_back();
            
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
         vector<vector<int>> ans;
        
        vector<int> temp;
        
        if(!root) return ans;
        
        findPath(root ,temp, ans , targetSum);
        
       
        return ans;
    }
}
