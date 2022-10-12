#include <iostream>
#include "SeqStack.h"
int main() {
    SeqStack S;
    InitStack(S);
    Push(S,4);
Push(S,3);
    //Pop(S,0);
   std::cout<<S.elem[1]<<std::endl;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
