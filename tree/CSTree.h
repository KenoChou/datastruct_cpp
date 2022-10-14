//
// Created by kenochou on 22-10-14.
//
#include <stdio.h>
#include <stdlib.h>
#include "Ptree.h"

#ifndef DATASTRUCT_CPP_CSTREE_H
#define DATASTRUCT_CPP_CSTREE_H
#define  maxSize 50
typedef char TElemType;
typedef  struct  Node{
    TElemType data;
    struct Node *lchild, * rsibling;
}CSNode,*CSTree;
CSNode  *FindParent(CSNode* t,CSNode *p){
    CSNode *S,*q=t->lchild;
    while (q!=NULL){
        if(q==p)return t;
        S= FindParent(q,p);
  if(S==NULL) q=p->rsibling;
  else return  S;
    }
    return NULL;
}
void PreOrder(CSNode *p){
    CSNode *t=p->lchild;
    if(p!=NULL){
        printf("%c",t->data);
        for(;t!=NULL;t=t->rsibling){
            PreOrder(t);
        }
    }
}
void PostOrder(CSNode *p){
    if(p!=NULL){
        for(CSNode *t=p->lchild;t!=NULL;t=t->rsibling){
            PostOrder(t);
            printf("%c",t->data) ;
        }

    }
}
#define qSize 20
void LeverlOreder(CSNode *t){
    if(t==NULL) return;
    CSNode * Q[qSize];int front =0,rear=0;
    CSNode *p,*s;
    rear =(rear+1)%qSize;Q[rear]=t;
    while (rear!= front){
        front=(front+1) % qSize;p=Q[front];
        printf("%c",p->data);
        for(s=p->lchild;s!=NULL;s=s->rsibling){
            rear=(rear+1)%qSize;Q[rear]=s;
        }
    }
}
typedef  char DataType;
#define  stackSize 20
void CreatePTree(PTree& T,TElemType G[]){
    DataType  S[stackSize];int top=-1;
    int i,j,k=-1;DataType  ch;
    for( i=0;G[i] !=';';i++){
        ch=G[i];
        switch (ch) {
            case '(': S[++top]=k;
                break;
            case ')':j=S[top--];
                break;
            case ',':
                break;
            default:T.tnode[++k].data=ch;
            if(top==-1)T.tnode[k].parent=-1;
            else{j=S[top];T.tnode[k].parent=j;}

        }
    }
    T.n=k+1;
}

#endif //DATASTRUCT_CPP_CSTREE_H
