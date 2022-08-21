class Solution {
  public:
    vector <int> bottomView(Node *root) {
        
        // Your Code Here
        
        
        vector<int> ans;
        
        map<int,int> topNode;
        
        queue<pair<Node* , int>> q;
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            
            pair<Node* , int> temp = q.front();
            
            q.pop();
            
            Node* frontNode = temp.first;
            
            int horiDis = temp.second;
            
            
            topNode[horiDis] = frontNode -> data;
            
            if(frontNode -> left) 
            
               q.push(make_pair(frontNode -> left , horiDis - 1));
               
            if(frontNode -> right)
            
               q.push(make_pair(frontNode -> right , horiDis + 1));
        }
        
        for(auto it: topNode){
            
            ans.push_back(it.second);
        }
        
        
        return ans;
    }
};
