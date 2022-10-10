//
// Created by kenochou on 22-10-11.
//

#ifndef UNTITLED2_DBLSTACK_H
#define UNTITLED2_DBLSTACK_H
#define m 20
typedef int SElemType;
typedef struct{
    int top[20],bot[20];
    SElemType v[m];
}DblStack;
void InitStack(DblStack & S){
    S.top[0]= S.bot[0]=-1;S.top[1]=S.bot[1]=m;
}
int Push(DblStack& S,SElemType x,int  i){
    if(S.top[0]+1==S.top[1])return  0;
    if(i==0)S.v[++S.top[0]]=x;
    else S.v[--S.top[1]]==x;
    return 1;

}
int Pop(DblStack& S,int i,SElemType &x){
    if(S.top[i]==S.bot[i]) return 0;
if(i==0)x=S.v[S.top[0]--];
else x= S.v[S.top[1]++];
    return 1;
}
#endif //UNTITLED2_DBLSTACK_H
