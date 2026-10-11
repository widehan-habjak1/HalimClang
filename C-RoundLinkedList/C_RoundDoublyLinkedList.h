#ifndef ROUND_DOUBLY_LINKED_LIST_H
#define ROUND_DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct tagNode
{
    ElementType Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;

Node* RLL_CreateNode(ElementType NewData);
void RLL_DestroyNode(Node* Node);
void RLL_AppendNode(Node** Head, Node* NewNode);
void RLL_InsertAfter(Node* Current, Node* NewNode);
void RLL_RemoveNode(Node** Head, Node* Remove);
Node* RLL_GetNodeAt(Node* Head, int Location);
int RLL_GetNodeCount(Node* Head);

#endif