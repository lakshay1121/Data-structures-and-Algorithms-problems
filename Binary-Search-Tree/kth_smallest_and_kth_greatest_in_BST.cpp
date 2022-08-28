//kth smallest element.



class Solution {
public:
    
    int solve(TreeNode* root , int k , int &i){
        
        if(root == NULL) return -1;
        
        //left call.
        
        int left = solve(root -> left, k , i);
        
        if(left != -1) return left;
        
        //root -> data.
        
        i++;
        
        if(i == k) return root -> val;
        
        //right call.
        
        return solve(root -> right , k , i);
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        
        int i = 0;
        
        int ans = solve(root , k , i);
        
        return ans;
        
    }
};



//kth greatest element.

