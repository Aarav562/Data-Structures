#include<iostream>
using namespace std;
class Node{
    Node* left;
    int data;
    int height;
    Node* right;
};
class AVL{
    private:
    Node* root;
    public:
    AVL(){root = nullptr;}
    Node* rInsert(Node* p,int key);
    int NodeHeight(Node* p);
    int BalanceFactor(Node* p);
    Node* LLRotation(Node* p);
    Node* RRRotation(Node* p);
    Node* LRRotation(Node* p);
    Node* RLRotation(Node* p);
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
    p->left=plr->right;    Node* pl = p->left;
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
    Node* pr = p->rchild;
    Node* prl = pr->lchild;
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
    prl->rchild = pr;
    prl->lchild = p;
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
        t->val = key;
        t->height=1;
        t->left=t->right = NULL;
        return t;
    }
    else if(key<p->val){
        p->left = rInsert(p->left,key);
    }
    else if(key>p->val){
        p->right = rInsert(p->right,key);
    }
    p->height = NodeHeight(p);
    if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1){
        return LLRotation(p);
    }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1){
        return LRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->left)==-1){
        return RRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->left)==1){
        return RLRotation(p);
    }
    return p;
}
int main(){

}