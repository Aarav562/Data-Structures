#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    Node *lchild;
    int data;
    Node *rchild;
};
class Tree{
    public:
    Node *root;
    Tree(){root = NULL;}
    void CreateTree();
    void Preorder(Node *p);
    void Postorder(Node *p);
    void Inorder(Node *p);
    void Lvlorder(Node *p);
    int Height(Node *root);
};
void Tree::CreateTree(){
    Node *p,*t;
    int x;
    queue<Node*> q;
    cout<<"Enter the Value in root: "<<endl;
    cin>>x;
    if(x==-1){
        return;
    }
    root = new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.push(root);
    while(!q.empty()){
        p = q.front();
        q.pop();
        cout<<"Enter the left child: "<<endl;
        cin>>x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        cout<<"Enter the right child: "<<endl;
        cin>>x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild=NULL;
            p->rchild = t;
            q.push(t);
        }
    }
}
void Tree::Preorder(Node *p){
    if(p){
        cout<<p->data<<" "<<flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Tree::Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<" "<<flush;
        Inorder(p->rchild);
    }
}
void Tree::Postorder(Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" "<<flush;
    }
}
void Tree::Lvlorder(Node *p){
    queue<Node*> q;
    cout << root->data << ", " << flush;
    q.emplace(root);
    while (!q.empty()){
        p = q.front();
        q.pop();
        if (p->lchild){
            cout << p->lchild->data << ", " << flush;
            q.emplace(p->lchild);
        }
        if (p->rchild){
            cout << p->rchild->data << ", " << flush;
            q.emplace(p->rchild);
        }
    }
}
int Tree::Height(Node *p){
    int l=0;
    int r=0;
    if(p==NULL){
        return 0;
    }
    l = Height(p->lchild);
    r = Height(p->rchild);
    if(l>r){
        return l+1;
    }
    else{
        return r+1;
    }
}
int main(){
    Tree tq;
    tq.CreateTree();
    tq.Postorder(tq.root);
    return 0;
}