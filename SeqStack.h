//
// Created by kenochou on 22-10-11.
//

#ifndef UNTITLED2_SEQSTACK_H
#define UNTITLED2_SEQSTACK_H

#include <cstdlib>
#include <iostream>
typedef int SElemType;
#define initSize 20
typedef struct {
    SElemType *elem;
    int maxSize;
    int top;
}SeqStack;
void Reverse(SElemType A[],int n){

}
void InitStack(SeqStack& S){
    S.elem=(SElemType*) malloc(initSize*sizeof (SElemType));
    if(S.elem==NULL){std::cout<<"存储分配失败"<<std::endl;
        exit(1);}
    S.maxSize=initSize;S.top=-1;
}
template<typename T>
int Push(SeqStack & S,T x){
    if(S.top==S.maxSize-1) return 0;
    S.elem[++S.top]=x;
    return  1;
}
int Pop(SeqStack &S,SElemType&x){
    if(S.top=-1)return  0;
    x=S.elem[S.top--];
    return 1;
}
int GetTop(SeqStack S,SElemType&x){
    if(S.top==-1) return 0;
    x=S.elem[S.top];
    return 1;
};
int StackEmpty(SeqStack &S){
    return S.top==-1;
};
int StackFull(SeqStack & S){
    return S.top ==S.maxSize;
};
int StackSize(SeqStack& S){
    return S.top+1;
}
#endif //UNTITLED2_SEQSTACK_H
