/*  Binary Tree traversal breadth first,depth first   */


/*
Binary Tree Traversal:
    1. Breadth first   a.ka.  Level-Order (we implement Queue(FIFO) to traverse)
    2. Depth first  
        1. Pre-Order  (DLR) ( root- left - right )
        2. In-Order   (LDR) ( left- root- right )
        3. Post-Order (LRD) ( left- right- data )
*/


/*Breadth first  -Level Order*/

#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};


Node* GetNewNode(int x){
    Node* temp=new Node;
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

Node* Insert(Node* root,int x){
    if(root==NULL){
        root=GetNewNode(x);
    }
    else if(x<root->data){
        root->left=Insert(root->left,x);
    }
    else{
        root->right=Insert(root->right,x);
    }
    return root;
}

//LevelOrder ftn using Queue stl
void LevelOrder(Node* root){
    if(root==NULL) return;
    queue<Node*>Q; //from STL
    Q.push(root);
    //while atleast one discovered node
    while(!Q.empty()){
        Node* current=Q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL) Q.push(current->left);
        if(current->right!=NULL)Q.push(current->right);
        Q.pop(); //removing element at front
    }
}


int main()
{
    Node * root= NULL;  //keeping root as local variable
    int range,x;
    cout<<"how many elements :";
    cin>>range;
    for(int i=0;i<range;i++){
        cout<<"enter element: ";
        cin>>x;
        root=Insert(root,x);
    }

    LevelOrder(root);

    return 0;
}

