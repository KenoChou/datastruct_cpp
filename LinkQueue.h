//
// Created by kenochou on 22-10-11.
//

#ifndef UNTITLED2_LINKQUEUE_H
#define UNTITLED2_LINKQUEUE_H

#include <cstdio>
#include <cstdlib>

typedef int QElemType;
typedef struct Node{
    QElemType data;
    struct Node *link;
}LinkNode;
typedef struct {
    LinkNode *front,*rear;
}LinkQueue;
void InitQueue(LinkQueue & Q){
    Q.front=Q.rear= NULL;
};
int EnQueue(LinkQueue& Q,QElemType x){
    LinkNode *s=(LinkNode*)malloc(sizeof (LinkNode));
    s->data=x;s->link=NULL;
}

#endif //UNTITLED2_LINKQUEUE_H
