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
#endif //datastruct_cpp_MGRAPH_H
