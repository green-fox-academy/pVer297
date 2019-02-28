//
// Created by Egri Zoltán on 2019. 02. 28..
//

#include "linked_list.h"

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

void l_list_print(l_list_t* list)
{
    if (!list->hasData) {
        printf("Empty");
        return;
    }

    l_list_node_t* iterator = list->firstNode;
    while (iterator != NULL) {
        printf("%d\n", iterator->data);
        iterator = iterator->nextNode;
    }
}
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
    l_list_node_t* iter = list->firstNode;
    while(iter != 0){
        l_list_node_t* nextNode = iter->nextNode;
        free(iter);
        iter = nextNode;
    }
    list->hasData = 0;
}
void l_list_push_front(l_list_t* list, int value)
{
    l_list_node_t* newNode = (l_list_node_t*) malloc(sizeof(l_list_node_t));

    if(!list->hasData){
        list->hasData = 1;
        newNode->nextNode = NULL;
        list->lastNode = newNode;
    } else {
        newNode->nextNode = list->firstNode;
    }

    newNode->data = value;
    list->firstNode = newNode;
}