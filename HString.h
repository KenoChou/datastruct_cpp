//
// Created by kenochou on 22-10-12.
//
#include <stdlib.h>
#include <stdio.h>
#ifndef DATASTRUCT_CPP_HSTRING_H
#define DATASTRUCT_CPP_HSTRING_H
#define defaultSize 128
typedef struct {
    char *ch;
    int maxSize;
    int n;
}HString;
void initString(HString& S,int n){
    if(n<defaultSize) n=defaultSize;
    S.ch=(char *) malloc((n+1)*sizeof (char));
    if(S.ch==NULL)exit(1);
    S.maxSize=n;
};
void createHString(HString& S,char c[]){
int i,k;
for(k=0;c[k] !='\0';k++){
    initString(S,k);
    for(i=0;c[i] != '\0';i++){
S.ch[i]=c[i];
    }
    S.n=k;
}
}
void printHString(HString &S){
    for(int i=0;i<S.n;i++){
        if(S.ch[i]=='\0')break;
        else printf("%c",S.ch[i]);
        printf("\n");
    }
}
int Concat(HString&S1,HString& S2){
    int i;
    if(S1.n+S2.n>S1.maxSize){
        S1.maxSize=S1.n+S2.n;
        char *newAddr =(char*) malloc((S1.maxSize+1)*sizeof(char));
        if(!newAddr){ printf("存储分配失败！\n");
            exit(1);}
        for(i=0;i<S1.n;i++){
            newAddr[i]=S1.ch[i];
        }
        free(S1.ch);
        S1.ch=newAddr;
    }
    for (int i = 0; i < S2.n; ++i) {
        S1.ch[i+S1.n]=S2.ch[i];

    }
    S1.ch[i]='\0';S1.n=S1.n+S2.n;
    return 1;
};
#endif //DATASTRUCT_CPP_HSTRING_H
