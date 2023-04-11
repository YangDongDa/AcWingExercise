#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode ;
typedef struct BiTree{
    BiTNode *root;

    
}BiTree;
void init(BiTree *T){
    T->root = NULL;
}
void preOrder(BiTNode *T){
    if(T == NULL){
        return;
    }
    cout << T->data;
    preOrder(T->lchild);
    preOrder(T->rchild);
}
void inOrder(BiTNode *T){
    if(T == NULL){
        return;
    }
    inOrder(T->lchild);
    printf("%c ", T->data);
    inOrder(T->rchild);
}
BiTNode *createBiTree(){
    char ch;
    ch = getchar();
    if(ch == '#'){
        return NULL;
    }
    BiTNode *T = new BiTNode;
    T->data = ch;
    T->lchild = createBiTree();
    T->rchild = createBiTree();
    return T;
}
int main (int argc, char *argv[])

{
    // abc##de#g##f###
    BiTree T;
    init(&T);
    BiTNode *p = T.root;
    p = createBiTree();
    // preOrder(p);
    inOrder(p);
    cout<<endl;
    



    return 0;
}
