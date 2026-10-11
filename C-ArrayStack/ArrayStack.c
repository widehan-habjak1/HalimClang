#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** Stack, int Capacity){
    (*Stack) = malloc(sizeof(ArrayStack));
    (*Stack)->Nodes = malloc(sizeof(Node)*Capacity);

    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = -1;
}

void AS_DestroyStack(ArrayStack* Stack){
    free(Stack->Nodes);
    free(Stack);
}

void AS_Push(ArrayStack* Stack, StackType Data){
    Stack->Top++;
    Stack->Nodes[Stack->Top].Data = Data;
}