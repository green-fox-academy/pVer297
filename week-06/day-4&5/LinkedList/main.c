#include <stdio.h>
#include "linked_list.h"

int main()
{
    l_list_t list;
    for (int i = 0; i < 5; i++) {
        l_list_push_back(&list, i * 2);
    }

    l_list_push_front(&list, 99);

    l_list_print(&list);

    l_list_dealloc(&list);
    return 0;
}