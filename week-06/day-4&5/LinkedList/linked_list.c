//
// Created by Egri Zoltán on 2019. 02. 28..
//

#include "linked_list.h"

//////////////////////////PRINT//////////////////////////////////////

void l_list_print(l_list_t* list)
{
    if (!list->hasData) {
        puts("Empty");
        return;
    }

    l_list_node_t* iterator = list->firstNode;
    while (iterator != NULL) {
        printf("%d\n", iterator->data);
        iterator = iterator->nextNode;
    }
}

/////////////////////////GETTERS/////////////////////////////////////

int l_list_front(l_list_t* list)
{
    return list->firstNode->data;
}
int l_list_back(l_list_t* list)
{
    return list->lastNode->data;
}
l_list_node_t* l_list_begin(l_list_t* list)
{
    return list->firstNode;
}
l_list_node_t* l_list_end(l_list_t* list)
{
    return list->lastNode;
}
int l_list_isEmpty(l_list_t* list)
{
    return (list->hasData != 0);
}

//////////////////////////////UTILITY////////////////////////////////

int l_list_size(l_list_t* list)
{
    int count = 0;
    l_list_node_t* iter = list->firstNode;
    while (iter != 0) {
        count++;
        iter = iter->nextNode;
    }
    return count;
}
void l_list_dealloc(l_list_t* list)
{
    if (!list->hasData) {
        return;
    }
    l_list_node_t* iter = list->firstNode;
    while (iter != 0) {
        l_list_node_t* nextNode = iter->nextNode;
        free(iter);
        iter = nextNode;
    }
    list->hasData = 0;
}

void l_list_clear(l_list_t* list)
{
    l_list_dealloc(list);
}

l_list_node_t* l_list_search(l_list_t* list, int value)
{
    if (!list->hasData) {
        puts("No nodes in list!");
        return NULL;
    }

    l_list_node_t* iter = list->firstNode;
    while (iter != NULL) {
        if (iter->data == value) {
            break;
        }
        iter = iter->nextNode;
    }
    return iter;
}

///////////////////////////INSERT///////////////////////////////////

void l_list_push_front(l_list_t* list, int value)
{
    l_list_node_t* newNode = (l_list_node_t*) malloc(sizeof(l_list_node_t));

    if (!list->hasData) {
        list->hasData = 1;
        newNode->nextNode = NULL;
        list->lastNode = newNode;
    } else {
        newNode->nextNode = list->firstNode;
    }

    newNode->data = value;
    list->firstNode = newNode;
}

void l_list_push_back(l_list_t* list, int value)
{
    l_list_node_t* newNode = (l_list_node_t*) malloc(sizeof(l_list_node_t));

    if (!list->hasData) {
        list->hasData = 1;
        list->firstNode = newNode;
    } else {
        list->lastNode->nextNode = newNode;
    }

    list->lastNode = newNode;
    list->lastNode->data = value;
    list->lastNode->nextNode = NULL;
}

void l_list_insert(l_list_t* list, int value, int index)
{
    int listSize = l_list_size(list);
    if (listSize < index) {
        puts("No such index!");
        return;
    }
    if (index == 0) {
        l_list_push_front(list, value);
        return;
    }
    if (listSize == index) {
        l_list_push_back(list, value);
        return;
    }

    l_list_node_t* newNode = (l_list_node_t*) malloc(sizeof(l_list_node_t));
    l_list_node_t* iter = list->firstNode;
    for (int i = 0; i < index - 1; i++) {
        iter = iter->nextNode;
    }
    newNode->data = value;
    newNode->nextNode = iter->nextNode;
    iter->nextNode = newNode;

}

////////////////////////////DELETE//////////////

l_list_node_t* l_list_pop_front(l_list_t* list)
{
    if (!list->hasData) {
        puts("No nodes in list!");
        return NULL;
    }
    if (l_list_size(list) == 1) {
        l_list_clear(list);
        return NULL;
    }

    l_list_node_t* newHead = list->firstNode->nextNode;
    free(list->firstNode);
    list->firstNode = newHead;
    return newHead;
}

l_list_node_t* l_list_pop_back(l_list_t* list)
{
    if (!list->hasData) {
        puts("No nodes in list!");
        return NULL;
    }

    if (l_list_size(list) == 1) {
        l_list_clear(list);
        return NULL;
    }

    l_list_node_t* iter = list->firstNode;
    for (int i = 0; i < l_list_size(list) - 2; i++) {
        iter = iter->nextNode;
    }

    free(list->lastNode);
    list->lastNode = iter;
    list->lastNode->nextNode = NULL;
    return iter;
}

int l_list_erase_if(l_list_t* list, int value)
{
    if (!list->hasData) {
        puts("No nodes in list!");
        return 0;
    }
    int initialSize = l_list_size(list);

    if (initialSize == 1) {
        l_list_clear(list);
        return 1;
    }

    int counter = 0;
    l_list_node_t* prevNode = NULL;
    l_list_node_t* currentNode = list->firstNode;

    while (currentNode != NULL) {
        if (currentNode->data == value) {
            if (prevNode != NULL) {
                prevNode->nextNode = currentNode->nextNode;
            } else {
                list->firstNode = currentNode->nextNode;
            }
            counter++;
            free(currentNode);
        } else {
            prevNode = currentNode;
        }
        if (prevNode == NULL) {
            currentNode = list->firstNode;
        } else {
            currentNode = prevNode->nextNode;
        }
    }
    if (initialSize == counter) {
        l_list_clear(list);
    }
    return counter;
}


//////////////////////////////////////SORT//////////////////

l_list_node_t* l_list_sort(l_list_t* list)
{
    int length = l_list_size(list);
    for (int i = 0; i < length; i++) {
        l_list_node_t* iter = list->firstNode;
        for (int j = 0; j < length - 1 - i; j++) {
            if (iter->data > iter->nextNode->data) {
                l_list_swap(iter, iter->nextNode);
            }
            iter = iter->nextNode;
        }
    }
    return NULL;
}

void l_list_swap(l_list_node_t* first, l_list_node_t* second)
{
    int temp = second->data;
    second->data = first->data;
    first->data = temp;
}