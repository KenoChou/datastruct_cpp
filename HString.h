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

    }
}
}
#endif //DATASTRUCT_CPP_HSTRING_H
