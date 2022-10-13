//
// Created by kenochou on 22-10-13.
//

#ifndef DATASTRUCT_CPP_BINTREE_H
#define DATASTRUCT_CPP_BINTREE_H

#include <cstdio>

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
#endif //DATASTRUCT_CPP_BINTREE_H

