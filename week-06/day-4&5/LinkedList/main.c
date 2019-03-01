#include <stdio.h>
#include "linked_list.h"

int main()
{
    l_list_t list;/*
    for (int i = 0; i < 5; i++) {
        l_list_push_back(&list, i * 2);
    }

    l_list_push_front(&list, 99);

    l_list_insert(&list, 50, 1);
    l_list_push_back(&list, 30);
    l_list_push_back(&list, 30);
    l_list_push_back(&list, 30);
    l_list_push_back(&list, 30);
    l_list_push_back(&list, 28);
    l_list_push_back(&list, 30);
    l_list_push_back(&list, 30);
    l_list_push_back(&list, 30);
    l_list_push_back(&list, 50);

    int searchValue = 24;
    if(l_list_search(&list, searchValue)){
        printf("Found %d!\n", searchValue);
    } else {
        printf("No node with %d\n", searchValue);
    }

    l_list_print(&list);

    l_list_pop_front(&list);
    //l_list_pop_back(&list);

    l_list_erase_if(&list, 30);

    puts("");
    l_list_print(&list);

    l_list_erase_if(&list, 50);
    puts("");
    l_list_print(&list);

    l_list_dealloc(&list);

    printf("\n\n\n\n");
*/
    for(int i = 20; i > 0; i--){
        l_list_push_back(&list, i);
    }

    l_list_print(&list);
    l_list_sort(&list);
    puts("");
    l_list_print(&list);
    l_list_dealloc(&list);
    return 0;
}