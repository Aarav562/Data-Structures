#include<iostream>
#include<stack>
using namespace std;
class Node{
    public:
    Node* left;
    int val;
    Node* right;
};
class BST{
    public:
    Node* root;
    BST(){root = NULL;}
    Node* getRoot(){return root;}
    void iInsert(int key);
    Node* rInsert(Node* p,int key);
    void Inorder(Node* p);
    Node* iSearch(int key);
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
Node* BST::iSearch(int key){
    Node* t = root;
    while(t){
        if (key==t->val){return t;}
        else if(key<t->val){t=t->left;}
        else{t=t->right;}
    }
    return NULL;
}
Node* BST::rSearch(Node*p , int key){
    if(p==NULL){
        return NULL;
    }
    else{
        if(key==p->val){
            return p;
        }
        else if(key<p->val){
            return rSearch(p->left,key);
        }
        else{
            return rSearch(p->right,key);
        }
    }
}
Node* BST::Delete(Node* p,int key){
    Node* q;
    if(p==NULL){
        return NULL;
    }
    if(p->left==NULL && p->right==NULL){
        if(p==root){
            root = NULL;
        }
        delete p;
        return NULL;
    }
    if(key<p->val){
        p->left = Delete(p->left,key);
    }
    else if(key>p->val){
        p->right = Delete(p->right,key);
    }
    else{
        if(Height(p->left)>Height(p->right)){
            q = InPre(p->left);
            p->val = q->val;
            p->left = Delete(p->left,q->val);
        }
        else{
            q=InSuc(p->right);
            p->val = q->val;
            p->right = Delete(p->right,q->val);
        }
    }
    return p;
}
int BST::Height(Node* p){
    int x,y;
    if(p==NULL){
        return 0;
    }
    x = Height(p->left);
    y = Height(p->right);
    return x>y?x+1:y+1;
}
Node* BST::InPre(Node *p) {
    while (p && p->right != nullptr){
        p = p->right;
    }
    return p;
}
Node* BST::InSuc(Node *p) {
    while (p && p->left != nullptr){
        p = p->left;
    }
    return p;
}
void BST::Create(int p[],int n){
    stack<Node*>stk;
    Node* t;
    int i=0;
    root = new Node;
    root->val = p[i++];
    root->left=root->right=NULL;
    Node* pt = root;
    while(i<n){
        if(p[i]<pt->val){
            t = new Node;
            t->val = p[i++];
            t->left=t->right=NULL;
            pt->left = t;
            stk.push(pt);
            pt=t;
        }
        else{
            if(p[i]>pt->val && p[i]<stk.empty()?32767:stk.top()->val){
            t = new Node;
            t->val = p[i++];
            t->left=t->right=NULL;
            pt->left = t;
            pt=t;
            }
            else{
                pt=stk.top();
                stk.pop();
            }
        }
    }
}
int main(){
    BST tree;
    int A[]={50,30,20,40,70,60,80};
    int n = sizeof(A)/sizeof(A[0]);
    for(int i=0;i<n;i++){
        tree.root = tree.rInsert(tree.root,A[i]);
    }
    tree.Inorder(tree.root);
    tree.Delete(tree.root,20);
    tree.Delete(tree.root,70);
    cout<<endl;
    tree.Inorder(tree.root);
    return 0;
}