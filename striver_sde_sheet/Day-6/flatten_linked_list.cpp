/*
    Flattening the linked list with next and bottom pointers
    if we try to remove and store all next link pointers
    problem boils down to merge k sorted linked ists
*/

Node* merge_2(Node* head1,Node* head2){
    if(!head1) return head2;
    if(!head2) return head1 ;
    Node* result = NULL ;
    //just making sure everytime we have head1 pointing less value
    if(head2->data<head1->data){
        swap(head2,head1) ;
    }
    result = head1 ;
    while(head1 && head2){
        Node* prev = NULL ;
        while(head1 && head1->data<=head2->data){
            prev = head1;
            head1 = head1->bottom;
        }
        prev->bottom = head2 ;
        swap(head1,head2);
    }
    return result ;
    /*
    Time : O(l1+l2)
    Space : O(1)
    */
}
    Node *flatten(Node *root){
        
        if(!root) return root ;
        vector<Node*> roots ;
        Node* temp = root ;
        while(temp){
            Node* prev = temp ;
            roots.push_back(prev);
            temp = temp->next ;
            prev->next = NULL ;
        }
        
        int n = roots.size();
        //cout<<n<<endl;
        for(int i = n-1;i>0;i--){
            roots[i-1] = merge_2(roots[i-1],roots[i]);
        }
        
        return roots[0];
        /*
        stroing roots
        Time : O(N*M)
        Space : O(M)
        */
    
    }

    Node *flatten(Node *root){
        
        if(!root) return root ;
        Node* curr = flatten(root->next) ;
        
        return merge_2(root,curr);
        /*
        using recursion
        Time : O(N*M)
        Space : O(N)+O(N)
        
        */
    
    }