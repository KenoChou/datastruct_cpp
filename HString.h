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
int Find(HString & T,HString& P){
    int i,j,k;
    for(i=0;i<=T.n-P.n;i++){
        for (int k = i; k < P.n; ++k,j++) {
            if(T.ch[k] !=P.ch[j])break;
            if (i==P.n)return i;
        }
    }
    return  -1;
}
int fastFind(HString& T,HString& P,int next[]){
int j=0,i=0;
    while (j<P.n&&j<T.n){
        if(j==-1||P.ch[i]==T.ch[i]){
            j++;i++;
        }else{
            j=next[j];
        }
    }
    if(j<P.n)return -1;
    else return i-P.n;
};
void getNext(HString& P,int next[]){
    int j=0,k=-1;next[0]=-1;
    while (j<P.n){
        while (k>=0&&P.ch[j] !=P.ch[k])k=next[k];
        j++;k++;
        if(P.ch[j]==P.ch[k]) next[j]=next[k];
        else
            next[j]=k;
    }
};

#endif //DATASTRUCT_CPP_HSTRING_H
