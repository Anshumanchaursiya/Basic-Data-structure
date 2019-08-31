void bottom(Node* root,int key,map<int,int> &m){
    
    if(root == NULL){
        return;
    }
    m[key] = root->data;
    bottom(root->left,key-1,m);
    
    bottom(root->right,key+1,m);
}

void bottomView(Node *root)
{
   // Your Code Here
    map<int,int> m;
    bottom(root,0,m);
    for(auto it = m.begin();it!=m.end();it++){
        //cout<<it->first<<endl;
        cout<<it->second<<" ";
    }
    //cout<<endl;
  
}
