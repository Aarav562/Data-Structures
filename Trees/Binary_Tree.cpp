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
    void Height(Node *root);
};
void Tree::CreateTree(){
    Node *p,*t;
    int x;
    queue<Node*> q;
    cout<<"Enter the Value in root: "<<endl;
    cin>>x;
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
