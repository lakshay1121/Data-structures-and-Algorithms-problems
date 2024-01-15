class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       
        if(root == NULL) return "";
        
        queue<TreeNode*> q;
        string s ="";
        
        q.push(root);
        
        while(!q.empty()){
            
            TreeNode* currNode = q.front();
            q.pop();
            
            if(currNode == NULL) s.append("X,");
            else s.append(to_string(currNode -> val)+',');
            
            if(currNode != NULL){
                
                q.push(currNode -> left);
                q.push(currNode -> right);
            }
        }
        
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size() == 0) return NULL;
        
        queue<TreeNode*> q;
        
        stringstream s(data);
        
        string str;
        
        getline(s , str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        
        q.push(root);
        
        while(!q.empty()){
            
            TreeNode* node = q.front();
            
            q.pop();
            
            //iterating the stringstream getting left child.
            
            getline(s , str, ',');
            
            if(str == "X"){
                
                node -> left = NULL;
            }
            
            else{
                
                TreeNode* leftNode = new TreeNode(stoi(str));
                
                node -> left = leftNode;
                
                q.push(leftNode);
            }
            
            //iterating the stringstream getting the right child.
            
            getline(s , str, ',');
            
            if(str == "X"){
                
                node -> right = NULL;
            }
            
            else{
                
                TreeNode* rightNode = new TreeNode(stoi(str));
                
                node -> right = rightNode;
                
                q.push(rightNode);
            }
        }
        
        return root;
        
    }
};
