//
// Created by kenochou on 22-10-14.
//
#include <stdio.h>
#include<stdlib.h>
#define leaFnumber 20
#define totalNumber 39
#ifndef DATASTRUCT_CPP_HUFFMAN_H
#define DATASTRUCT_CPP_HUFFMAN_H
typedef  struct {
    char data;
    int weight;
    int parent,lchild,rchild;
}HTNode;
typedef struct {
    HTNode elem[totalNumber];
    int num,root;
}HFTree;
#define maxValue 32767
void createHFTree (HFTree& HT,char value[],int fr[],int n){
    int i,k,S1,S2;int min1,min2;
    for(i=0;i<n;i++){
        HT.elem[i].data=value[i];HT.elem[i].weight=fr[i];
    }
    for(i=0;i<leaFnumber;i++){
        HT.elem[i].parent=HT.elem[i].lchild=HT.elem[i].rchild=-1;
    }
    for(i=n;i<2*n-1;i++){
        min1=min2=maxValue;
        S1=S2=0;
        for(k=0;k<i;k++)
            if(HT.elem[k].parent==-1)
                if(HT.elem[k].weight==-1){
                    min2=min1;S2=S1;
                    min1 =HT.elem[k].weight;
                    S1=k;
                }
        else if (HT.elem[k].weight<min2){
            min2=HT.elem[k].weight;S2=k;
        }
        HT.elem[S1].parent=HT.elem[S2].parent=i;
        HT.elem[i].lchild=S1;HT.elem[i].rchild=S2;
        HT.elem[i].weight=HT.elem[S1].weight+HT.elem[S2].weight;
    }
    HT.num=n;HT.root=2*n-2;
}
#endif //DATASTRUCT_CPP_HUFFMAN_H
