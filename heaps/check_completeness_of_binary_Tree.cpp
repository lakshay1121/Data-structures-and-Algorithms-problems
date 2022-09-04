class Solution {
public:
    
    void cntNoofnodes(TreeNode* root , int &cnt){
        
        if(root == NULL) return;
        
        cntNoofnodes(root -> left , cnt);
        
        cnt += 1;
        
        cntNoofnodes(root -> right , cnt);
          
    }
    
    bool solve(TreeNode* root , int idx , int nodecount){
        
        if(root == NULL) return true;
        
        bool leftans , rightans;
        
        if(idx >= nodecount){
            
            return false;
        }
        
        else {
            
             leftans = solve(root -> left , 2 * idx + 1 , nodecount );
            
            rightans = solve(root -> right , 2 * idx + 2 , nodecount);
        }
        
        
        return leftans && rightans;
        
    }
    bool isCompleteTree(TreeNode* root) {
        
        int cnt = 0;
        
        cntNoofnodes(root , cnt);
        
        cout<<cnt << endl;
        
        return solve(root , 0, cnt);
        
        
    }
};
