#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdio.h>
#include <stdlib.h>


typedef int StackType;

typedef struct tagNode
{
    StackType Data;
} Node;

typedef struct tagArrayStack
{
    int Capacity;
    int Top;
    Node* Nodes;
} ArrayStack;

void AS_CreateStack(ArrayStack** Stack, int Capacity);
void AS_DestroyStack(ArrayStack* Stack);
void AS_Push(ArrayStack* Stack, StackType Data);
StackType AS_Pop(ArrayStack* Stack);
StackType AS_Top(ArrayStack* Stack);
int AS_KnowSize(ArrayStack* Stack);
int AS_IsEmpty(ArrayStack* Stack);

#endif