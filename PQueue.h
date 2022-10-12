//
// Created by kenochou on 22-10-12.
//
#include <stdlib.h>
#ifndef UNTITLED2_PQUEUE_H
#define UNTITLED2_PQUEUE_H
#define maxPQSize 50
typedef int PQElemType;
typedef struct{
    PQElemType elem[maxPQSize];
    int n;
}PQueue;
int PQInsert(PQueue&PQ,PQElemType x){
    if(PQ.n==maxPQSize)return 0;
    PQ.elem[PQ.n++]=x;
    return 1;
};
int PQRemove(PQueue&PQ,PQElemType&x){
    if(PQ.n==0)return 0;
    PQElemType min=PQ.elem[0];int k=0;
    for(int i=1;i<PQ.n;i++) {
        if (PQ.elem[i] < min) {
            min = PQ.elem[i];
            k = i;
        }
    }
    x=PQ.elem[k];PQ.n--;
    PQ.elem[k]=PQ.elem[PQ.n];
    return 1;
}
#endif //UNTITLED2_PQUEUE_H
