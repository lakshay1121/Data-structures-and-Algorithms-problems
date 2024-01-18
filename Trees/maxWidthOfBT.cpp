class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
       unsigned long long maxWidth = 0;
        
        queue<pair<TreeNode* , unsigned long long>> q;
        
        q.push(make_pair(root , 0));
        
        while(!q.empty()){
            
            int n = q.size();
            
          unsigned  long long  L = q.front().second;
          unsigned  long long  R = q.back().second;
            
            maxWidth = max(maxWidth , R - L + 1);
            
            while(n--){
                
                TreeNode* currNode = q.front().first;
               unsigned long long idx = q.front().second;
                
                q.pop();
                
                if(currNode -> left) q.push(make_pair(currNode -> left , 2*idx+1));
                
                if(currNode -> right) q.push(make_pair(currNode -> right , 2*idx+2));
                
            }
        }
        
        return maxWidth;
        
    }
};
