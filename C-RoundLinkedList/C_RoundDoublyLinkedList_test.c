#include "C_RoundDoublyLinkedList.h"

int main(void)
{
    int i = 0;
    int Count = 0;

    Node* List = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;

    // 노드 5개 추가
    for (i = 0; i < 5; i++)
    {
        NewNode = RLL_CreateNode(i);
        RLL_AppendNode(&List, NewNode);
    }

    // 리스트 출력
    Count = RLL_GetNodeCount(List);

    printf("===== Initial List =====\n");

    for (i = 0; i < Count; i++)
    {
        Current = RLL_GetNodeAt(List, i);

        if (Current != NULL)
        {
            printf("List[%d] : %d\n", i, Current->Data);
        }
    }

    // 리스트의 세 번째 노드 뒤에 3000 삽입
    printf("\n===== Inserting 3000 After [2] =====\n\n");

    Current = RLL_GetNodeAt(List, 2);
    NewNode = RLL_CreateNode(3000);

    if (Current != NULL)
    {
        RLL_InsertAfter(Current, NewNode);
    }

    // 리스트 출력
    Count = RLL_GetNodeCount(List);

    for (i = 0; i < Count; i++)
    {
        Current = RLL_GetNodeAt(List, i);

        if (Current != NULL)
        {
            printf("List[%d] : %d\n", i, Current->Data);
        }
    }

    // Prev / Current / Next 확인
    printf("\n===== Node Information =====\n");

    Count = RLL_GetNodeCount(List);

    for (i = 0; i < Count; i++)
    {
        Current = RLL_GetNodeAt(List, i);

        printf("List[%d] : ", i);
        PrintNode(Current);
    }

    // 모든 노드 삭제
    printf("\n===== Destroying List =====\n");

    while (List != NULL)
    {
        Current = List;

        RLL_RemoveNode(&List, Current);
        RLL_DestroyNode(Current);
    }

    return 0;
}