//
// Created by kenochou on 22-10-14.
//

#ifndef DATASTRUCT_CPP_ALGRAPH_H
#define DATASTRUCT_CPP_ALGRAPH_H
#include <stdlib.h>
#include<stdio.h>
#define maxVertices 30
#define  maxEdges 450
typedef  char Type;
typedef  int Weight ;
#define impossibleValue '#'
#define  impossibleWeight -1
typedef struct  Enode{
    int dest;
    Weight cost;
    struct Enode *link;
}EdgeNode;
typedef struct  Vnode{
    Type data;
    struct Enode *adj;
}VertexNode;
typedef struct  {
    VertexNode VerticesList[maxVertices];
    int numVertices,numEdges;
}ALGraph;
int getVertexPos(ALGraph&G,Type v){
    int i=0;
    while (i<G.numVertices&&G.VerticesList[i].data!=v)i++;
    if(i<G.numVertices) return i;
    else return  -1;
}
int NumberOfVertices(ALGraph& G){
    return G.numVertices;
}
int NumberOfEdges(ALGraph &G){
    return G.numEdges;
}
int FirstNeighbor(ALGraph& G,int v){
    if(v!=-1){
        EdgeNode *p =G.VerticesList[v].adj;
        if(p!=NULL)return p->dest;
    }
    return -1;
}
int NextNeighbor(ALGraph& G,int v,int w){
    if(v!=-1){
        EdgeNode *p=G.VerticesList[v].adj;
        while (p!=NULL&&p->dest != w)p=p->link;
        if(p!=NULL&&p->link!=NULL)return  p->link->dest;
    }
    return -1;
}
Type getValue(ALGraph&G,int v){
    if(v!=-1) return G.VerticesList[v].data;
    else return impossibleValue;
}
Weight getWeight(ALGraph& G,int v,int w){
    EdgeNode *p =G.VerticesList[v].adj;
    while(p!=NULL&&p->dest !=w)p=p->link;
    if(p!=NULL)return p->cost;
    else return impossibleWeight;
}

#endif //DATASTRUCT_CPP_ALGRAPH_H
