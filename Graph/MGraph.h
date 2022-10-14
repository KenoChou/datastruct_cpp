//
// Created by kenochou on 22-10-11.
//

#ifndef datastruct_cpp_MGRAPH_H
#define datastruct_cpp_MGRAPH_H
#include<stdio.h>
#include<stdlib.h>
#define maxVertices 30
#define maxEdges 900
#define  maxWeight 32767
#define  impossibleValue '#'
#define  impossibleWeight -1
typedef  char Type;
typedef int Weight;
typedef struct {
    int numVertices,numEdges;
    Type VerticeList[maxVertices];
    Weight  Edge[maxVertices][maxVertices];
} Mgraph;
int getVertexPos (Mgraph& G,Type x){
    for(int i=0;i<G.numVertices;i++){
        if(G.VerticeList[i]==x) return i;
    }
    return -1;
}
int FirstNeighbor(Mgraph& G,int v){
    if(v!=-1){
        for(int j=0;j<G.numVertices;j++){
            if(G.Edge[v][j]>0&&G.Edge[v][j]<maxVertices){
                return j;
            }
        }
    }
    return  -1;
}
int NextNeightbor(Mgraph& G,int v,int w){
    if(v!=-1&&w!=-1){
        for(int j=w+1;j<G.numVertices;j++){
            if(G.Edge[v][j]>0&&G.Edge[v][j]<maxVertices)return j;
        }
    }
    return -1;
}
int NumberOfVertices(Mgraph & G){
    return  G.numVertices;
}
int NumberOfEdgees(Mgraph &G){
    return  G.numEdges;
}
Type GetValue(Mgraph & G,int v){
    if(v!=-1) return G.VerticeList[v];
    else
        return impossibleValue;
}
Weight getWeight(Mgraph & G,int v,int w){
    if(v!=-1&& w!=-1) return  G.Edge[v][w];
    else return impossibleWeight;
}
void CreateMGraph(Mgraph& G,int n,int e,int d){

    G.numVertices=n;G.numEdges=e;
    int i,j,k;Type val,e1,e2;Weight cost;
    for(i=0;i<G.numVertices;i++){
        scanf("%c",&val);G.VerticeList[i]=val;
        for(j=0;j<G.numVertices;j++){
            G.Edge[i][j]=(i==j)?0:maxWeight;
        }
    }
    k=0;
    while(k<G.numVertices){
        scanf("%c,%c,%d",&e1,&e2,&cost);
        i= getVertexPos(G,e1);
        j= getVertexPos(G,e2);
        if(i!= -1 &&j != -1){
            G.Edge[i][j]=cost;
            if(d==0)G.Edge[j][i]=cost;
            k++;
        } else printf("边两端顶点信息有误，重新输入！\n");
    }
}

#endif //datastruct_cpp_MGRAPH_H
