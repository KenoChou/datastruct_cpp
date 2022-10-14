
//
// Created by kenochou on 22-10-14.
//
#include <stdio.h>
#include<stdlib.h>
#ifndef DATASTRUCT_CPP_PTREE_H
#define DATASTRUCT_CPP_PTREE_H
#define maxSize 50
typedef char TElemType;
typedef struct node{
    TElemType data;
    int parent;
}PTNode;
typedef struct {
    PTNode tnode[maxSize];
    int n;
}PTree;
int FirstChild(PTree& T,int i){
    int j;
    for (int j = i+1; j < T.n; ++j) {
        if(T.tnode[j].parent==i)break;
        if(j<T.n) return j;
        else return -1;
    }
}
int NextSibling (PTree& T,int i,int j){
    int k;
    for(k=j+1;k<T.n;k++){
        if(T.tnode[k].parent==i)break;
        else return -1;
    }
}
int FindParent(PTree& T,int i){
    if(i<T.n&&i>0)return T.tnode[i].parent;
    else return  -1;
}

#endif //DATASTRUCT_CPP_PTREE_H
