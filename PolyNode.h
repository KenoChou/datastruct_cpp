//
// Created by kenochou on 22-10-13.
//

#ifndef DATASTRUCT_CPP_POLYNODE_H
#define DATASTRUCT_CPP_POLYNODE_H
typedef struct  node{
    struct  node
            *tlink;
    int exp;
    int tag;
    union {
        char name;
        struct  node *hlink;
        double coef;
    };
}PolyNode;
#endif //DATASTRUCT_CPP_POLYNODE_H
