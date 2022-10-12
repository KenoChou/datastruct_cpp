//
// Created by kenochou on 22-10-11.
//

#ifndef datastruct_cpp_LINKQUEUE_H
#define datastruct_cpp_LINKQUEUE_H

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
    if(Q.rear==NULL)Q.front=Q.rear=s;
    else{Q.rear->link=s;Q.rear=s;}
    return 1;
}
int Dequeue(LinkQueue&Q,QElemType& x){
    if(Q.front==NULL) return 0;

}
#endif //datastruct_cpp_LINKQUEUE_H
