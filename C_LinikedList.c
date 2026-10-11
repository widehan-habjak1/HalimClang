#include "C_LinkedList.h"

//노드 생성
Node* SLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    return NewNode;
}

//노드 소멸
void SLL_DestroyNode(Node* Node)
{
    free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
    //헤드가 널이면 새로운 노드가 헤드가 된다
    if ((*Head) == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        // 테일을 찾아 뉴노드를 연결한다
        Node* Tail = (*Head);
        while (Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }
        
        Tail->NextNode = NewNode;
    }
}

// 노드 삽입
void SLL_InsertNode(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead)
{
    if ( (*Head) == NULL )
    {
        *Head = NewHead;
    }
    else
    {
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
}

//노드 제거
void SLL_RemoveNode(Node** Head, Node* Remove)
{
    if ( (*Head) == Remove )
    {
        *Head = Remove->NextNode;
    }
    else
    {
        Node* Current = *Head;
        while (Current != NULL && Current->NextNode != Remove)
        {
            Current = Current->NextNode;
        }
        
        if (Current != NULL)
            Current->NextNode = Remove->NextNode;
    }
}

// 노드 탐색
Node* SLL_GetNodeAt(Node* Head, int location){
    Node* Current = Head;
    while (Current != NULL && (--location) >= 0)
    {
        Current = Current->NextNode;
    }
    return Current;
}

int SLL_GetNodeCount(Node* Head){
    int count = 0;
    Node* Current = Head;
    while (Current != NULL)
    {
        Current = Current->NextNode;
        count++;
    }
    
    return count;
}