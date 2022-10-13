//
// Created by kenochou on 22-10-13.
//

#ifndef DATASTRUCT_CPP_THREADNODE_H
#define DATASTRUCT_CPP_THREADNODE_H
#include <stdio.h>
#include<stdlib.h>
typedef int TElemType;
typedef struct TRNode{
    int ltag,rtag;
    struct TRNode *lchild,*rchild;
    TElemType data;
}ThreadNode;
typedef ThreadNode *InThbinTree;
ThreadNode *inFirst(InThbinTree t){
    while (t->ltag==0)t=t->lchild;
    return t;
}
ThreadNode * inNext(InThbinTree t){
    if(t->rtag==0)return inFirst(t->rchild);
    else return t->rchild;
}
void Inorder(InThbinTree t){
    for(ThreadNode *p = inFirst(t);p!=NULL;p= inNext(p))
        printf("%d",p->data);
    printf("\n");
}
typedef ThreadNode *InThredTree;
void InThreaded (ThreadNode*p,ThreadNode *& pre){
    if(p!=NULL){
        InThreaded(p->lchild,pre);
        if(p->lchild==NULL){
            p->lchild=pre;p->ltag=1;
            if(pre!=NULL&&pre->rchild==NULL){
       pre->rchild=p;pre->rtag=1;
            }
            pre=p;
            InThreaded(p->rchild,pre);
        }
    }
}
void CreateInthread(InThredTree T){
    ThreadNode *pre =NULL;
    if(T !=NULL){
    InThreaded(T,pre);
    pre->rchild=NULL;pre->rtag=1;
}}
#endif //DATASTRUCT_CPP_THREADNODE_H
