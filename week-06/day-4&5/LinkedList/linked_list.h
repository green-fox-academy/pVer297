//
// Created by Egri Zoltán on 2019. 02. 28..
//

#ifndef LINKEDLIST_LINKED_LIST_H
#define LINKEDLIST_LINKED_LIST_H

#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node* nextNode;
} l_list_node_t;

typedef struct
{
    int hasData : 1;
    l_list_node_t* firstNode;
    l_list_node_t* lastNode;
} l_list_t;

void l_list_print(l_list_t* list);

int l_list_front(l_list_t* list);
int l_list_back(l_list_t* list);
l_list_node_t* l_list_begin(l_list_t* list);
l_list_node_t* l_list_end(l_list_t* list);
int l_list_isEmpty(l_list_t* list);

int l_list_size(l_list_t* list);
void l_list_clear(l_list_t* list);
void l_list_dealloc(l_list_t* list);
l_list_node_t* l_list_search(l_list_t* list, int value);

void l_list_push_back(l_list_t* list, int value);
void l_list_push_front(l_list_t* list, int value);
void l_list_insert(l_list_t* list, int value, int index);

l_list_node_t* l_list_pop_front(l_list_t* list);
l_list_node_t* l_list_pop_back(l_list_t* list);
int l_list_erase_if(l_list_t* list, int value);
#endif //LINKEDLIST_LINKED_LIST_H
