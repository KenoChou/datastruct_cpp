//
// Created by kenochou on 22-10-11.
//

#ifndef UNTITLED2_LINKSTACK_H
#define UNTITLED2_LINKSTACK_H

#include <cstdlib>

typedef int SElemType;
typedef struct node{
    SElemType data;
    struct node *link;
}LinkNode,*LinkStack;
void InitStack(LinkStack& S){
    S=NULL;
};
int Push(LinkStack& S,SElemType x){
    LinkNode  *p =(LinkNode*)malloc(sizeof (LinkNode));
    p->data=x;p->link=S;S=p;
    return 1;
}
int Pop(LinkStack&S,SElemType& x){
    if(S==NULL)return 0;
    LinkNode *p=S;x=p->data;
    S=p->link;
    free(p);
    return 1;
}
int GetTop(LinkStack &S,SElemType& x){
    if(S==NULL)return  0;
    x=S->data;return 1;
};
int StackEmpty(LinkStack &S){
    return S==NULL;
};
int StackSize(LinkStack &S){
    LinkNode *p=S; int k=0;
    while (p!=NULL){ p=p->link;k++;}
    return k;
}
#endif //UNTITLED2_LINKSTACK_H
