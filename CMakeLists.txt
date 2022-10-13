cmake_minimum_required(VERSION 3.23)
project(datastruct_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(datastruct_cpp main.cpp Stack/SeqStack.h Stack/DblStack.h Stack/LinkStack.h Queue/CireQueue.h MGraph.h List/ListSet.h List/List.h List/CircList.h List/dbList.h List/Polynomial.h Stack/LinkQueue.h Queue/SeqDeueue.h Queue/PQueue.h String/SeqString.h String/HString.h List/Glist.h List/GenList.h Queue/PolyNode.h tree/BinTree.h ThreadNode.h)
