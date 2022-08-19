class Solution
{
    public:
    
    pair<bool,int> SumTree(Node* root){
        
        //if node is null. 
        
        if(root == NULL) {
            
            pair<bool,int> p = make_pair(true,0);
            
            return p;
        }
        
        //in the case of leaf node. we have to skip leaf nodes.
        
        if(root ->left == NULL && root -> right == NULL){
            
            pair<bool,int> p = make_pair(true, root->data);
            
            return p;
        }
        
        pair<bool,int> leftsum = SumTree(root -> left);
        
        pair<bool,int> rightsum = SumTree(root -> right);
        
        
        bool leftAns = leftsum.first;
        
        bool rightAns = rightsum.first;
        
        bool sumCheck = root -> data == (leftsum.second + rightsum.second);
        
        
        pair<bool,int> ans;
        
        if(leftAns && rightAns && sumCheck){
            
            ans.first = true;
            
            ans.second = (root -> data + leftsum.second + rightsum.second);
            
        }
        
        else{
            
            ans.first = false;
        }
        
        
        return ans;
        
        
        
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         
         return SumTree(root).first;
         
         
    }
};


//tc = O(N)
//sc = O(N)
