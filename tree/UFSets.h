//
// Created by kenochou on 22-10-14.
//

#ifndef DATASTRUCT_CPP_UFSETS_H
#define DATASTRUCT_CPP_UFSETS_H

#include <cstdio>

#define size 100
typedef struct {
    int parent[size];
}UfSets;
void Initial(UfSets& S){
    for (int i=0;i<size;i++) {
S.parent[i]=-1;
    }
}
int Find(UfSets& S,int X){
    while (S.parent[X]>=0) X=S.parent[X];
    return X;
}
void Merge(UfSets&S,int R1,int R2){
    if(R1==R2)return;
    S.parent[R1]=S.parent[R1]+S.parent[R2];
    S.parent[R2]=R1;
}
void MergeByWeight(UfSets& S,int R1,int R2){
    int i= Find(S,R1),j= Find(S,R2);
    if(i==j) return;
    int temp=S.parent[i]+S.parent[j];
    if(S.parent[j]<S.parent[i]){
        S.parent[i]=j;S.parent[j]=temp;
    }else { S.parent[j]=i;S.parent[i]=temp;}
}
int CollapsingFind(UfSets& S,int i){
    int k,temp;
    for(k=i;S.parent[k]>=0;k=S.parent[k]);
    while (i!=k){
        temp=S.parent[i];S.parent[i]=k;i=temp;
    }
    return k;
}
void Queue(int chese[],int i){
    int j,k;
    if(i==8){
        for(j=0;j<8;j++){
            printf("%d row,%d,column\n",j+1,chese[j]+1);
            return;
        }
        for(j=0;j<8;j++){
            chese[i]=j;
            for(k=0;k<i;k++){
                if(chese[i] != chese[k]&&i-k!= chese[i]-chese[k]&&k-i!=chese[k]-chese[i]){
                    Queue(chese,i+1);

                }
            }
        }
    }
}
#endif //DATASTRUCT_CPP_UFSETS_H
