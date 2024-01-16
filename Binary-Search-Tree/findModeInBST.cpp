class Solution {
public:
    void solve(TreeNode* root , map<int,int>& mp){
        
        if(root == NULL) return;
        
        solve(root -> left , mp);
        mp[root->val]++;
        solve(root -> right , mp);
        
    }
    vector<int> findMode(TreeNode* root) {
        
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        map<int,int> mp;
        
        solve(root , mp);
        
        int mini = INT_MIN;
        
        
        for(auto it : mp){
        
            
            if(it.second > mini){
        
                mini = it.second;
            }
        }
        
        for(auto it : mp){
            
            if(it.second == mini){
                
                ans.push_back(it.first);
            }
        }
        
        
        return ans;
        
    }
};
