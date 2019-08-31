
int count_node_l_subtree(Node *root){
    
    if(root == NULL){
        return 0;
    }
    if(root->left==NULL and root->right==NULL){
        return 1;
    }
    return 1+count_node_l_subtree(root->left)+count_node_l_subtree(root->right);
    
    
}

int greattest_node_right_st(Node* root){
    
    Node* temp = root;
    while(temp->right!=NULL ){
        temp = temp->right;
    }
    return temp->data;
}

int KthSmallestElement(Node *root, int k)
{
    //add code here.
    
    int left_count=count_node_l_subtree(root->left);
    //cout<<"132"<<endl;
    if(k==left_count+1){
        return root->data;
    }
    else if(k==left_count){
        //cout<<"136";
        return greattest_node_right_st(root->left);
    }
    else if(k<left_count){
        return KthSmallestElement(root->left,k);
    }
    else{
        return KthSmallestElement(root->right,k-left_count-1);
    }
    
}
