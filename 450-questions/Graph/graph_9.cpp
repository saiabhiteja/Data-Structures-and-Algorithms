/*
 clone a graph
*/
//using BFS
Node* cloneGraph(Node* node) {
        if(!node) return node ;

        queue<pair<Node*,Node*>> q ;//first->orginal,second->duplicate
        unordered_map<int,Node*> mp ;//for storing new graph nodes
        Node* new_node = new Node(node->val) ;//since 1st val will be value always
        mp[1] = new_node ;
        Node* result = new_node ;

        q.push({node,new_node});

        while(q.size()!=0){ //using BREADTH FIRST SEARCH
            auto t = q.front();
            q.pop();
            Node* old = t.first ;
            Node* news = t.second ;
            for(auto it :old->neighbors){
                if(mp.find(it->val) == mp.end()){
                    //node not formed
                    Node* temp = new Node(it->val) ;
                    mp[it->val] = temp ;
                    news->neighbors.push_back(temp);
                    q.push({it,temp}) ;
                }
                else{
                    //node already fromed
                    Node* temp = mp[it->val] ;
                    news->neighbors.push_back(temp);
                }
            }
            
        }
        return result ;//returning answer

        /*
        Time : O(V+E)
        Space : O(V)
        */
        
}



    unordered_map<int,Node*> mp ;
    void dfs(Node* old,Node* news){
        for(auto it :old->neighbors){
                if(mp.find(it->val) == mp.end()){
                    //node not formed
                    Node* temp = new Node(it->val) ;
                    mp[it->val] = temp ;
                    news->neighbors.push_back(temp);
                    dfs(it,temp) ;
                }
                else{
                    //node already fromed
                    Node* temp = mp[it->val] ;
                    news->neighbors.push_back(temp);
                }
            }
        
    }

    Node* cloneGraph(Node* node) {
        if(!node) return node ;
        
        Node* new_node = new Node(node->val) ;//since 1st val will be value always
        mp[1] = new_node ;
        Node* result = new_node ;
        dfs(node,new_node) ;
        
        return result ;//returning answer

        /*
        Time : O(V+E)
        SPace : O(V)
        */
        
    }


