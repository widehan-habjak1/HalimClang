#include "C_DoublyLinkedList.h"

int main()
{
    Node* List = NULL;
    Node* NewNode = NULL;
    Node* Curr = NULL;

    int i;
    int cnt;

    // ========================================
    // 노드 5개 추가
    // ========================================

    for (i = 0; i < 5; i++)
    {
        NewNode = DLL_CreateNode(i);

        if (NewNode != NULL)
        {
            DLL_AppendNode(&List, NewNode);
        }
    }


    // ========================================
    // 리스트 출력
    // ========================================

    printf("===== Original List =====\n");

    cnt = DLL_GetNodeCount(List);

    for (i = 0; i < cnt; i++)
    {
        Curr = DLL_GetNodeAt(List, i);

        printf("List[%d]: %d\n", i, Curr->Data);
    }


    // ========================================
    // 2번 노드 뒤에 3000 삽입
    // ========================================

    printf("\nInserting 3000 After [2]...\n");

    Curr = DLL_GetNodeAt(List, 2);

    NewNode = DLL_CreateNode(3000);

    if (Curr != NULL && NewNode != NULL)
    {
        DLL_InsertAfter(Curr, NewNode);
    }


    // ========================================
    // 삽입 후 리스트 출력
    // ========================================

    printf("\n===== After Insertion =====\n");

    cnt = DLL_GetNodeCount(List);

    for (i = 0; i < cnt; i++)
    {
        Curr = DLL_GetNodeAt(List, i);

        printf("List[%d]: %d\n", i, Curr->Data);
    }


    // ========================================
    // 각 노드의 Prev / Current / Next 출력
    // ========================================

    printf("\n===== Node Information =====\n");

    cnt = DLL_GetNodeCount(List);

    for (i = 0; i < cnt; i++)
    {
        Curr = DLL_GetNodeAt(List, i);

        PrintNode(Curr);
    }


    // ========================================
    // 리스트 삭제
    // ========================================

    printf("\n===== Destroying List =====\n");

    while (List != NULL)
    {
        Curr = List;

        DLL_RemoveNode(&List, Curr);
        DLL_DestroyNode(Curr);
    }

    printf("List destroyed.\n");

    return 0;
}