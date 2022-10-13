//
// Created by kenochou on 22-10-13.
//

#ifndef DATASTRUCT_CPP_BINTREE_H
#define DATASTRUCT_CPP_BINTREE_H

#include <cstdio>
#include <cstdlib>

typedef char TElemType;
#define  maxSzie 10
typedef struct {
    TElemType data[maxSzie];
    int n;
}SeqBtree;
typedef char TelemType;
typedef  struct node{
    TElemType data;
    struct  node* lchild,*rchild;
}BiTnode,*BinTree;
void InOrder_recur(BiTnode * BT)
{
    if(BT != NULL){
        InOrder_recur(BT->lchild);
        printf("%d",BT->data);
        InOrder_recur(BT->rchild);
    }
}
void PreOrder_recur(BiTnode* BT){
    if(BT!=NULL){
        printf("%d",BT->data);
        PreOrder_recur(BT->lchild);
        PreOrder_recur(BT->rchild);
    }
}
void PostOrder_recur(BiTnode * BT){
    if(BT!=NULL){
        PostOrder_recur(BT->lchild);
        PreOrder_recur(BT->rchild);
        printf("%d",BT->data);
    }
}
void CreateBinTree_Pre(BiTnode *&T,TElemType pre[],int & n){
    TElemType ch =pre[n++];
    if(ch==';') return;
    if(ch != '#'){
        T=(BiTnode *) malloc(sizeof(BiTnode));
T->data=ch;
        CreateBinTree_Pre(T->lchild,pre,n);
        CreateBinTree_Pre(T->rchild,pre,n);
    }
    else T=NULL;
};
//创建二叉树
void PrintBinTree(BiTnode *t){
    if(t!=NULL){
        printf("%c",t->data);

    if(t->lchild!=NULL||t->rchild!=NULL){
        printf("(");
        PrintBinTree(t->lchild);
        printf(",");
        PrintBinTree(t->rchild);
        printf(")");
    }
}
}
#endif //DATASTRUCT_CPP_BINTREE_H

