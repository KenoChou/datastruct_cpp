//
// Created by kenochou on 22-10-14.
//
#include <stdio.h>
#include <stdlib.h>
#ifndef DATASTRUCT_CPP_MINHEAP_H
#define DATASTRUCT_CPP_MINHEAP_H
#define heapSize 40
typedef int HElemType;
typedef struct {
    HElemType elem[heapSize];
    int curSize;
}minHeap;

void SiftDown(minHeap &h, int i, int i1);

void SiftUp(minHeap &H, int start);

void creatMinHeap(minHeap&H, HElemType arr[], int n){
    int i;


        for(i=(H.curSize-2)/2;i>=0;i--){
            H.curSize=n;
            SiftDown(H,i,H.curSize-1);
        }
    }

void SiftDown(minHeap &H, int start, int m) {
int i,j;i=start;
HElemType temp=H.elem[i];
for(j=2*i+1;j<m;j=2*j+1){
    if(j<m&&H.elem[j]>H.elem[j+1])j++;
    if(temp<=H.elem[j])break;
    else { H.elem[i]=H.elem[j];i=j;}
}
H.elem[i]=temp;
}
int Insert(minHeap& H, HElemType x){
    if(H.curSize==heapSize)return 0;
    H.elem[H.curSize]=x;
    SiftUp(H,H.curSize);
    H.curSize++;
    return 1;
}

void SiftUp(minHeap &H, int start) {

HElemType temp=H.elem[start];int j=start,i=(j-1)/2;
    while (j>0){
        if(H.elem[i]<=temp)break;
        else {H.elem[j]=H.elem[i];i=i;i=(i-1)/2;}
    }
    H.elem[j]=temp;
}
int Remove(minHeap& H,HElemType &x){
    if(H.curSize==0) return 0;
    x=H.elem[0];H.elem[0]=H.elem[H.curSize-1];
    H.curSize--;
    SiftDown(H,0,H.curSize-1);
    return 1;
}
#endif //DATASTRUCT_CPP_MINHEAP_H
