#include "C_DoublyLinkedList.h"

// 노드 생성
Node* DLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    if (NewNode == NULL)
    {
        printf("메모리 할당 실패\n");
        return NULL;
    }

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}


// 노드 소멸
void DLL_DestroyNode(Node* Node)
{
    free(Node);
}


// 노드 추가
void DLL_AppendNode(Node** Head, Node* NewNode)
{
    if (*Head == NULL)
    {
        *Head = NewNode;
        return;
    }

    // 마지막 노드 찾기
    Node* Tail = *Head;

    while (Tail->NextNode != NULL)
    {
        Tail = Tail->NextNode;
    }

    // Tail <-> NewNode 연결
    Tail->NextNode = NewNode;
    NewNode->PrevNode = Tail;
}


// 특정 노드 뒤에 삽입
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
    if (Current == NULL || NewNode == NULL)
    {
        return;
    }

    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if (Current->NextNode != NULL)
    {
        Current->NextNode->PrevNode = NewNode;
    }

    Current->NextNode = NewNode;
}


// 노드 제거
void DLL_RemoveNode(Node** Head, Node* Remove)
{
    if (*Head == NULL || Remove == NULL)
    {
        return;
    }

    // Remove가 첫 번째 노드인 경우
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;

        if (*Head != NULL)
        {
            (*Head)->PrevNode = NULL;
        }
    }
    else
    {
        // 앞쪽 노드 연결
        if (Remove->PrevNode != NULL)
        {
            Remove->PrevNode->NextNode = Remove->NextNode;
        }

        // 뒤쪽 노드 연결
        if (Remove->NextNode != NULL)
        {
            Remove->NextNode->PrevNode = Remove->PrevNode;
        }
    }

    // 제거한 노드의 연결 끊기
    Remove->PrevNode = NULL;
    Remove->NextNode = NULL;
}


// 노드 탐색
Node* DLL_GetNodeAt(Node* Head, int Location)
{
    Node* Curr = Head;

    int i;

    if (Location < 0)
    {
        return NULL;
    }

    for (i = 0; i < Location && Curr != NULL; i++)
    {
        Curr = Curr->NextNode;
    }

    return Curr;
}


// 노드 개수 세기
int DLL_GetNodeCount(Node* Head)
{
    int Count = 0;

    Node* Curr = Head;

    while (Curr != NULL)
    {
        Count++;
        Curr = Curr->NextNode;
    }

    return Count;
}


// 노드 출력
void PrintNode(Node* Node)
{
    if (Node == NULL)
    {
        return;
    }

    if (Node->PrevNode == NULL)
    {
        printf("Prev: NULL");
    }
    else
    {
        printf("Prev: %d", Node->PrevNode->Data);
    }

    printf(" | Current: %d", Node->Data);

    if (Node->NextNode == NULL)
    {
        printf(" | Next: NULL\n");
    }
    else
    {
        printf(" | Next: %d\n", Node->NextNode->Data);
    }
}