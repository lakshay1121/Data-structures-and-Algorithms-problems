class Solution {
public:
    
    void inorder(TreeNode* root , vector<int> &ans){
        
        if(root == NULL) return ;
        
        inorder(root -> left , ans);
        
        ans.push_back(root -> val);
        
        inorder(root -> right ,ans);
    }
    
    
    bool findTarget(TreeNode* root, int k) {
        
        
        vector<int> ans;
        
        inorder(root , ans);
        
        int start = 0 ; 
        
        int end = ans.size() - 1;
        
       while(start < end){
            
            int sum = ans[start] + ans[end];
             
            if(sum == k) return true;
            
            if(sum < k) start++;
            
            if(sum > k) end--;
        
        }
        
        return false;
        
    }
};
