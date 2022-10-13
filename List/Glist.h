//
// Created by kenochou on 22-10-13.
//
#include<stdio.h>
#include<stdlib.h>
#ifndef DATASTRUCT_CPP_GLIST_H
#define DATASTRUCT_CPP_GLIST_H
typedef char ElemType;
typedef struct node{
    int tag;
    int mark;
    struct node * tlink;
    union {
        ElemType data;
        struct node * hlink;
    }val;

}GLNode,*Glist;
void CreateGlist(char * S,int & i,GLNode * & g) {
    char ch = S[i++];
    if (ch != '\0') {
        if (ch == '(') {
            if (S[i] == ')') {g = NULL;i++;}
        else {
            g = (GLNode *) malloc(sizeof(GLNode));
            g->tag = 1;
            g->mark = 0;
            CreateGlist(S, i, g->val.hlink);
        }
    }
        else if (ch == ')')g = NULL;
        else if (ch == ',') {
            g = (GLNode *) malloc(sizeof(GLNode));
            g->tag = 1;
            g->mark = 0;
            CreateGlist(S, i, g->val.hlink);
            CreateGlist(S, i, g->tlink);
        } else {
            g = (GLNode *) malloc(sizeof(GLNode));
            g->tag = 0;
            g->mark = 0;
            g->val.data = ch;
        }
    }
}
#endif //DATASTRUCT_CPP_GLIST_H
