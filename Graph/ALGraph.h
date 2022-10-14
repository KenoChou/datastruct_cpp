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
void createALGraph(ALGraph& G,int n,int e,int d){
    int i,j,k;Type val,e1,e2;Weight c;EdgeNode *q,*p;
    G.numVertices=n;G.numEdges=e;
    for(i=0;i<G.numVertices;i++){
        scanf("%c",&val);
        G.VerticesList[i].data=val;
        G.VerticesList[i].adj=NULL;
    }
    i=0;
    while (i<G.numEdges){
        scanf("%c,%c,%d",&e1,&e2,&c);
      j= getVertexPos(G,e1);k= getVertexPos(G,e2);
      if(j!=-1&&k !=-1){
          p=G.VerticesList[j].adj;
          while (p!=NULL&&p->dest !=k)p=p->link;
          if(p==NULL){
              q=(EdgeNode*) malloc(sizeof(EdgeNode));
              q->dest=k;q->cost=c;
              q->link=G.VerticesList[j].adj;
              G.VerticesList[j].adj=q;
              if(d==0){
                  q=(EdgeNode*) malloc(sizeof (EdgeNode));
                  q->dest=j;q->cost=c;
                  q->link=G.VerticesList[k].adj;
                  G.VerticesList[k].adj=q;
              }
              i++;
          }
          else printf("边重复，重新输入！\n");
      }
      else printf("边两端顶点信息有误，重新输入！\n");
    }
}
#endif //DATASTRUCT_CPP_ALGRAPH_H
