//
// Created by kenochou on 22-10-12.
//
#include <stdio.h>
#ifndef UNTITLED2_SEQDEUEUE_H
#define UNTITLED2_SEQDEUEUE_H
#define maxSzie 100
typedef int DQElemType;

typedef struct {
    DQElemType elem[maxSzie];
    int end1,end2;
    
}SeqDeque;
int EnQueueHead(SeqDeque &Q,DQElemType x){
    if(Q.end2+1 % maxSzie==Q.end1) return 0;
    Q.end1=(Q.end1-1+maxSzie) % maxSzie;
    Q.elem[Q.end1]=x;
    return 1;
};
int DeQueueHead(SeqDeque&Q,DQElemType&x){
    if(Q.end1==Q.end2)return 0;
    x=Q.elem[Q.end1];
    Q.end1=(Q.end1+1)%maxSzie;
    return 1;
};
int GetHead(SeqDeque &Q,DQElemType &x){
    if(Q.end1==Q.end2)return 0;
    x=Q.elem[Q.end1];
    return 1;
};
int EnQueueTail(SeqDeque&Q,DQElemType&x){
    if(Q.end2+1%maxSzie==Q.end1) return 0;
    Q.elem[Q.end2]=x;
    x=Q.elem[Q.end2];
    return 1;
}
int DeQueueTail(SeqDeque&Q,DQElemType&x){
    if(Q.end1==Q.end2)return 0;
    Q.end2=(Q.end2-1+maxSzie)%maxSzie;
    x=Q.elem[Q.end2];
    return 1;
};
int GetTail(SeqDeque&Q,DQElemType&x){
    if(Q.end1==Q.end2)return 0;
    x=Q.elem[(Q.end2-1+maxSzie)%maxSzie];
    return 1;
};
#endif //UNTITLED2_SEQDEUEUE_H
