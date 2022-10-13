//
// Created by kenochou on 22-10-12.
//
#include <cstdio>

#define maxSize 256
#ifndef datastruct_cpp_SEQSTRING_H
#define datastruct_cpp_SEQSTRING_H
typedef struct {
    char ch[maxSize];
    int n;
}SeqString;
void createSeqString(SeqString& s,char c[]){
    int i=0;
    while(i<maxSize&&c[i] !='\0'){ s.ch[i]=c[i];i++;}
    s.n=i;
    if(i==maxSize){
        printf("串空间不足以容纳输入的字符串！");
        for(i=0;c[i] != '\0';i++)printf("%c",c[i]);
        printf("\n");
    }
}
void printSeqString(SeqString &s){
    for(int i=0;i<s.n;i++)
        if(s.ch[i]=='\0')break;
    else printf("%c",s.ch[i]);
    printf("\n");
}
int Concat(SeqString& S1,SeqString &S2){
    if(S1.n+S2.n<maxSize){
        for(int i=0;i<S2.n;i++)S1.ch[i+S1.n]=S2.ch[i];
        S1.n=S1.n+S2.n;S1.ch[S1.n]='\0';
    } else if(S1.n<maxSize){
        int m =maxSize-S1.n;
        for(int  i=0;i<m;i++){
            S1.ch[i+S1.n]=S2.ch[i];
            S1.n=maxSize;S1.ch[maxSize]='\0';

        }
        return 0;
    }
    else return 0;
}
#endif //datastruct_cpp_SEQSTRING_H
