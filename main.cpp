#include<iostream>

#include "Stack/SeqStack.h"
#include "List/List.h"


using namespace std;
int main(){
SeqList L;
DataType x[10]={0,1,233,4,5,6,7,8,9};
    initList(L);
  for(int i=0;i<=10;i++) {


      Insert(L, i, x[i]);
  }

  DataType e=-1;
  if(Remove(L,2,e))
  {
   cout<<e;
  }
  else{
      cout<<"cuowu";
  }
//cout<<    Search(L,x[3]);


    /*while (!StackEmpty(S)){
        Pop(S,i);
        return i;
    }*/
}
