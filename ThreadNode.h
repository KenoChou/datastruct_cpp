//
// Created by kenochou on 22-10-13.
//

#ifndef DATASTRUCT_CPP_THREADNODE_H
#define DATASTRUCT_CPP_THREADNODE_H
#include <stdio.h>
#include<stdlib.h>
typedef int TElemType;
typedef struct TRNode{
    int ltag,rtag;
    struct TRNode *lchild,*rchild;
    TElemType data;
}ThreadNode;
typedef ThreadNode *InThreadTree;
ThreadNode *inFirst(InThreadTree t){
    while (t->ltag==0)t=t->lchild;
    return t;
}
#endif //DATASTRUCT_CPP_THREADNODE_H
