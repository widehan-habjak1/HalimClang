#include "C_RoundDoublyLinkedList.h"


Node* RLL_CreateNode(ElementType NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->NextNode = NULL;
    NewNode->PrevNode = NULL;

    return NewNode;
}

void RLL_DestroyNode(Node* Node){
    free(Node);
}

void RLL_AppendNode(Node** Head, Node* NewNode){
    //헤드 노드가 없으면 (NULL) 새로운 노드가 헤드가 된다.
    if((*Head) == NULL){
        *Head = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PrevNode = *Head;
    } else{
        //테일과 헤드 사이에 NewNode를 삽입
        Node* Ekor = (*Head)->PrevNode;

        Ekor->NextNode->PrevNode = NewNode;
        Ekor->NextNode = NewNode;

        NewNode->NextNode = (*Head);
        NewNode->PrevNode = Ekor; // 새로운 테일의 PrevNode가 기존의 테일을 가리킨다.
    }
}

void RLL_InsertAfter(Node* Current, Node* NewNode){
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if(Current->NextNode != NULL){
        Current->NextNode->PrevNode = NewNode;
        Current->NextNode = NewNode;
    }
}


void RLL_RemoveNode(Node** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        // 노드가 하나뿐인 경우
        if (Remove->NextNode == Remove)
        {
            *Head = NULL;
        }
        else
        {
            Remove->PrevNode->NextNode = Remove->NextNode;
            Remove->NextNode->PrevNode = Remove->PrevNode;

            *Head = Remove->NextNode;
        }
    }
    else
    {
        Remove->PrevNode->NextNode = Remove->NextNode;
        Remove->NextNode->PrevNode = Remove->PrevNode;
    }

    Remove->PrevNode = NULL;
    Remove->NextNode = NULL;
}

Node* RLL_GetNodeAt(Node* Head, int Location){
    Node* curr = Head;
    while (curr != NULL && (--Location) >=0)    
    {
        curr = curr->NextNode;
    }
    
    return curr;
}

int RLL_GetNodeCount(Node* Head){
    unsigned int cnt = 0;
    Node* curr = Head;

    while (curr != NULL)
    {
        curr = curr->NextNode;
        cnt++;

        if(curr == Head) break;
    }


    return cnt;
}

void PrintNode(Node* prnode){
    if(prnode->PrevNode == NULL) printf("Prev: NULL");
    else printf("Prev: %d", prnode->PrevNode->Data);

    printf("Current: %d", prnode->Data);

    if(prnode->NextNode == NULL) printf("Next: NULL\n");
    else printf("Next: %d\n", prnode->NextNode->Data);
}