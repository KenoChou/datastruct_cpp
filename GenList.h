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
#include <ctype.h>
#define DefaultSzie 50
void CreteList(char *S,int & i,GenListNode *& h,char L1[],GenList L2[],int &k){
GenListNode *p;char nam,ch;
nam=ch;ch=S[i++];
    printf("%c",ch);
    if(isupper(ch)){
        h=(GenListNode*) malloc(sizeof (GenListNode));
        p->tag=2;
        nam=ch;ch=S[i++];
        if(ch=='('){
            p=(GenListNode*) malloc(sizeof (GenListNode));
            p->tag=0;p->info.ref=1;
            h->info.hlink=p;
            L1[k]=nam;L2[k++]=p;
            if(ch=='('){
                p=(GenListNode*) malloc(sizeof(GenListNode));
                p->tag=0;p->info.ref=1;
                h->info.hlink=p;
                L1[k]=nam;L2[k++]=p;
            if(S[i]=='#'){p->tlink=NULL;i++;}
                CreteList(S,i,p->tlink,L1,L2,k);
            nam =ch;ch=S[i++];
                printf("%c",ch);
                if(ch==',')CreteList(S,i,h->tlink,L1,L2,k);
                else if (ch==')')h->tlink=NULL;
            }
        }

    }
    else if(islower(ch)){
        h=(GenListNode*) malloc(sizeof(GenListNode));
        h->tag=1;h->info.value=ch;
        nam=ch;ch=S[i++];
        if(ch==',')CreteList(S,i,h->tlink,L1,L2,k);
        else if(ch==')') h->tlink=NULL;
    }
}
void CreateGenList(char *S,GenList& Gl,char Ls1[],GenList Ls2[],int& count){
    int i=0;count =0;
    CreteList(S,i,Gl,Ls1,Ls2,count);
    GenListNode  *p =Gl->info.hlink;
    free(Gl);Gl=p;
}

#endif //DATASTRUCT_CPP_GENLIST_H
