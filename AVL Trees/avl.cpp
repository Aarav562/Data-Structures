#include<iostream>
using namespace std;
class Node{
    public:
    Node* left;
    int data;
    int height;
    Node* right;
};
class AVL{
    public:
    Node* root;

    AVL(){root = nullptr;}
    Node* rInsert(Node* p,int key);
    int NodeHeight(Node* p);
    int BalanceFactor(Node* p);
    Node* LLRotation(Node* p);
    Node* RRRotation(Node* p);
    Node* LRRotation(Node* p);
    Node* RLRotation(Node* p);
    Node* InPre(Node* p);
    Node* InSuc(Node* p);

    void Inorder(Node* p);
    Node* getRoot(){return root;}
    Node* Delete(Node* p,int key);
};
int AVL::NodeHeight(Node* p){
    int hl,hr;
    hl = p && p->left?p->left->height:0;
    hr = p && p->right?p->right->height:0;

    return hl>hr?hl+1:hr+1;
}
int AVL::BalanceFactor(Node* p){
    int hl,hr;
    hl = p && p->left?p->left->height:0;
    hr = p && p->right?p->right->height:0;
    return hl-hr;
}
Node* AVL::LLRotation(Node* p){
    Node* pl = p->left;
    Node* plr = p->right;
    pl->right = p;
    p->left = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    if(root==p){
        root = pl;
    }
    return pl;
}
Node* AVL::LRRotation(Node* p){
    Node* pl=p->left;
    Node* plr = pl->right;
    pl->right = plr->left;
    p->left=plr->right;    
    plr->left = pl;
    plr->right = p;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);
    if(root==p){
        root = pl;
    }
    return plr;
}
Node* AVL::RRRotation(Node* p){
    Node* pr = p->right;
    Node* prl = p->left;
    pr->left = p;
    p->right = prl;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    if(root==p){
        root = pr;
    }
    return pr;
}
Node* AVL::RLRotation(Node* p){
    Node* pr = p->right;
    Node* prl = pr->left;
    pr->left = prl->right;
    p->right = prl->left;
    prl->right = pr;
    prl->left = p;
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);
    if (root == p){
        root = prl;
    }
    return prl;
}
Node* AVL::rInsert(Node* p,int key){
    Node* t;
    if(p==NULL){
        t=new Node;
        t->data = key;
        t->height=1;
        t->left=t->right = NULL;
        return t;
    }
    else if(key<p->data){
        p->left = rInsert(p->left,key);
    }
    else if(key>p->data){
        p->right = rInsert(p->right,key);
    }
    p->height = NodeHeight(p);
    if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1){
        return LLRotation(p);
    }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1){
        return LRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==-1){
        return RRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==1){
        return RLRotation(p);
    }
    return p;
}
Node* AVL::InPre(Node *p) {
    while (p && p->right != nullptr){
        p = p->right;
    }
    return p;
}
Node* AVL::InSuc(Node *p) {
    while (p && p->left != nullptr){
        p = p->left;
    }
    return p;
}
void AVL::Inorder(Node* p){
    if(p){
        Inorder(p->left);
        cout<<p->data<<" ";
        Inorder(p->right);
    }
}
Node* AVL::Delete(Node* p,int key){
    if(p==nullptr){
        return nullptr;
    }
    if(p->left==nullptr && p->right==nullptr){
        if(p==root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
    if(key<p->data){
        p->left = Delete(p->left,key);
    }
    else if(key>p->data){
        p->right = Delete(p->right,key);
    }
    else{
        Node* q;
        if(NodeHeight(p->left) > NodeHeight(p->right)){
            q = InPre(p->left);
            p->data =q->data;
            p->left = Delete(p->left,q->data);
        }
        else{
            q = InSuc(p->right);
            p->data = q->data;
            p->right =Delete(p->right,q->data);
        }
    }
    p->height = NodeHeight(p);
    if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1){
        return LLRotation(p);
    }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1){
        return LRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==-1){
        return RRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==1){
        return RLRotation(p);
    }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==0){
        return LLRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==0){
        return RRRotation(p);
    }
    return p;
}
int main(){
    AVL tree;
    int A[] = {10, 20, 30, 25, 28, 27, 5};
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        tree.root = tree.rInsert(tree.root, A[i]);
    }
    tree.Inorder(tree.root);
    cout << endl;
    tree.Delete(tree.root, 28);
    tree.Inorder(tree.root);
    cout << endl;
    return 0;
}