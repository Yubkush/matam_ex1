#include "list_str.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define NULL_POINTER -1

struct List_t
{
    char *name;
    double amount;
    struct List_t *next;
};

List listCreate()
{
	List new_list = malloc(sizeof(*new_list));
	if(!new_list) {
		return NULL;
	}
	new_list->name = NULL;
	new_list->amount = 0;
    new_list->next = NULL;
	return new_list;
}

static List listCreateElement(const char *element)
{
    List new_list = listCreate();
    if(new_list == NULL){
        return NULL;
    }
    new_list->name = malloc(sizeof(element));
    if(new_list->name == NULL){
        return NULL;
    }
    strcpy(new_list->name, element);
    return new_list;
}

void listDestroy(List list)
{
	while(list) {
		List to_delete = list;
		list = list->next;
        free(to_delete->name);
		free(to_delete);
	}
}

static List copyElement(List element)
{
    if(element->name == NULL){
        return NULL;
    }
    List copy;
    copy = listCreateElement(element->name);
    if(copy == NULL){
        return NULL;
    }
    copy->amount = element->amount;
    return copy;
}

List listCopy(List list)
{
    if(list == NULL){
        return NULL;
    }
    // copy list head
    List list_copy = listCreate();
    if(list_copy == NULL){
        return NULL;
    }
    List list_tmp = list->next;
    List list_copy_pointer = list_copy;
    // copy rest of the list
    while(list_tmp){
        List list_element_copy = copyElement(list_tmp);
        if(list_element_copy == NULL){
            listDestroy(list_copy);
            return NULL;
        }
        list_copy_pointer->next = list_element_copy;
        list_copy_pointer = list_copy_pointer->next;
        list_tmp = list_tmp->next;
    }
    return list_copy;
}

int listGetSize(List list)
{
    if(!list){
        return NULL_POINTER;
    }
    int size = 0;
    List copy = list->next;
    while(copy){
        size++;
        copy = copy->next;
    }
    return size;
}

ListResult listRemoveElement(List list, const char* element)
{
    if(!list){
        return LIST_NULL_ARGUMENT;
    }
    List copy = list->next;
    List before_copy = list;
    // remember the element before the iterator, so we can unlink the element 
    while(!copy && strcmp(copy->name, element)!=0){
        before_copy = copy;
        copy = copy->next;
    }
    // unlinking
    if(copy){
        before_copy->next = copy->next;
    }
    else{
        before_copy->next = NULL;
    }
    free(copy->name);
    free(copy);
    return LIST_SUCCESS;
}

ListResult listInsertFirst(List list, const char* element)
{
    if(list == NULL){
        return LIST_NULL_ARGUMENT;
    }
    List new_element = listCreateElement(element);
    if(new_element == NULL){
        return LIST_OUT_OF_MEMORY;
    }
    new_element->next = list->next;
    list->next = new_element;
    return LIST_SUCCESS;
}

ListResult listInsertLexicographic(List list, const char* element)
{
    if(!list){
        return LIST_NULL_ARGUMENT;
    }
    if(list->next == NULL){
        return listInsertFirst(list, element);
    }
    List new_element = listCreateElement(element);
    if(!new_element){
        return LIST_OUT_OF_MEMORY;
    }
    //if the element to be inserted is the smallest in lexicographic order
    if(strcmp(list->next->name, element)>=0){
        new_element->next = list->next;
        list->next = new_element;
        return LIST_SUCCESS;
    }
    List copy = list->next;
    List previous = list;
    //run till we need to add element
    while(!copy && strcmp(copy->name, element)<0){
        previous = copy;
        copy = copy->next;
    }
    //add element
    previous->next = new_element;
    new_element->next = copy;
    return LIST_SUCCESS;
}

ListResult listSetAmountOfElement(List list, double amount, const char* element)
{
    if(list == NULL){
        return LIST_NULL_ARGUMENT;
    }
    List copy = list->next;
    while(copy && strcmp(element, copy->name) != 0){
        copy = copy->next;
    }
    if(copy == NULL){
        return LIST_ELEMENT_NOT_IN_LIST;
    }
    copy->amount = amount;
    return LIST_SUCCESS;
}

ListResult listClear(List list)
{
    if(list == NULL){
        return LIST_NULL_ARGUMENT;
    }
    listDestroy(list->next);
    list->next = NULL;
    return LIST_SUCCESS;
}

ListResult listCompare(List list1, List list2, bool* result)
{
    if(!list1 || !list2){
        return LIST_NULL_ARGUMENT;
    }
    *result = true;
    List copy1 = list1->next, copy2 = list2->next;
    while(copy1 && copy2)
    {
        if (strcmp(copy1->name,copy2->name)!=0 || (copy1->amount != copy2->amount))
        {
            *result = false;
            break;
        }
        copy1 = copy1->next;
        copy2 = copy2->next;
    }
    if((!copy1 && copy2) || (copy1 && !copy2)){
        *result = false;
    }
    return LIST_SUCCESS;
}

double listReturnAmountOfElement(List element)
{
    if(element == NULL){
        return NULL_POINTER;
    }
    return element->amount;
}

const char* listReturnNameOfElement(List element)
{
    if(element == NULL){
        return NULL;
    }
    return element->name;
}

List listGetNext(List list)
{
    if(list == NULL){
        return NULL;
    }
    return list->next;
}