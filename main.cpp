#include <iostream>
#include "tree/BinTree.h"
int main() {
BiTnode root,r1;
root.data=1;
root.rchild=NULL;
//std::cout<<root.data<<"123"<<std::endl;
    root.lchild=&r1;
    r1.data=3;
    r1.lchild=r1.rchild=NULL;
//int n=2;
     //TElemType *pre;
  // CreateBinTree_Pre(root, pre, n);
   // PrintBinTree(root);
    InOrder_recur(&root);
    return 0;
}
