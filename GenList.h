//
// Created by kenochou on 22-10-13.
//
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#ifndef DATASTRUCT_CPP_GENLIST_H
#define DATASTRUCT_CPP_GENLIST_H
typedef char ELemType;
typedef struct node{
    int tag;
    struct node * tlink;
    union {
        char ref;
        ELemType value;
        struct node * hlink;

    }info;
}GenListNode,*GenList;

#endif //DATASTRUCT_CPP_GENLIST_H
