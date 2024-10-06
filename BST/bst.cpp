#include<iostream>
using namespace std;
class Node{
    public:
    Node* left;
    int val;
    Node* right;
};
class BST{
    private:
    Node* root;
    public:
    BST(){root = NULL;}
    Node* getRoot(){return root;}
    void iInsert(int key);
    Node* rInsert(Node* p,int key);
    void Inorder(Node* p);
    Node* iSearch(Node* p,int key);
    Node* rSearch(Node* p,int key);
    Node* Delete(Node* p,int key);
    int Height(Node* p);
    Node* InPre(Node* p);
    Node* InSuc(Node* p);
    void Create(int pre[],int n);
};
void BST::iInsert(int key){
    Node* r=NULL;
    Node* t=root;
    Node* p;
    while(t!=NULL){
        r=t;
        if(key==t->val){return;}
        else if(key<t->val){
            t=t->left;
        }
        else{
            t=t->right;
        }
    }
    p = new Node;
    p->val = key;
    p->left=p->right=NULL;
    if(p->val<r->val){
        r->left = p;
    }
    else{
        r->right =p;
    }
}
Node* BST::rInsert(Node* p,int key){
    Node* t;
    if(p==NULL){
        t=new Node;
        t->val = key;
        t->left=t->right = NULL;
        return t;
    }
    else if(key<p->val){
        p->left = rInsert(p->left,key);
    }
    else if(key>p->val){
        p->right = rInsert(p->right,key);
    }
    return p;
}
void BST::Inorder(Node *p){
    if(p){
        Inorder(p->left);
        cout<<p->val<<" ";
        Inorder(p->right);
    }
}
