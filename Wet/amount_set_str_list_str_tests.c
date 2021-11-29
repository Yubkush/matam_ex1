#include "amount_set_str_list_str.h"
#include "amount_set_str_list_str_tests.h"
#include <string.h>
#include <stdlib.h>
#define NAMES 3
#define DEMO_AMOUNT 10
#define NULL_POINTER -1

static List listCreateDemo()
{
    List demo = listCreate();
    if(demo == NULL){
        return NULL;
    }
    char *names[NAMES] = {"rice","milk","bread"};
    for(int i = 0; i < NAMES; i++)
    {
        listInsertLexicographic(demo, names[i]);
        listSetAmountOfElement(demo, DEMO_AMOUNT, names[i]);
    }
    return demo;
}

bool testCreateAndDestory()
{
    List created_list = listCreate();
    if(created_list == NULL){
        return false;
    }
    listDestroy(created_list);
    return true;
}

bool testListGetSize()
{
    List demo = listCreateDemo();
    int size = listGetSize(demo);
    listDestroy(demo);
    return size == NAMES;
}
bool testListGetSizeEmpty()
{
    List demo = listCreate();
    int size = listGetSize(demo);
    listDestroy(demo);
    return size == 0;
}
bool testListGetSizeNull()
{
    List demo = NULL;
    int size = listGetSize(demo);
    return size == NULL_POINTER;
}

bool testListCopy()
{
    List demo = listCreateDemo();
    List copy = listCopy(demo);
    bool are_equal = false;
    listCompare(demo, copy, &are_equal);
    listDestroy(demo);
    listDestroy(copy);
    return are_equal;
}
bool testListCopyEmpty()
{
    List demo = listCreate();
    List copy = listCopy(demo);
    bool are_equal = false;
    listCompare(demo, copy, &are_equal);
    listDestroy(demo);
    listDestroy(copy);
    return are_equal;
}
bool testListCopyNull()
{
    List demo = NULL;
    List copy = listCopy(demo);
    return copy == NULL;
}

bool testCompareList()
{
    List demo1 = listCreateDemo();
    List demo2 = listCreateDemo();
    bool are_equal = false;
    if(listCompare(demo1, demo2, &are_equal) != LIST_SUCCESS){
        return false;
    }
    listDestroy(demo2);
    listDestroy(demo1);
    return are_equal;
}
bool testCompareEmptyLists()
{
    List demo1 = listCreate();
    List demo2 = listCreate();
    bool are_equal = false;
    if(listCompare(demo1, demo2, &are_equal) != LIST_SUCCESS){
        return false;
    }
    listDestroy(demo2);
    listDestroy(demo1);
    return are_equal;
}
bool testCompareDifferentLists()
{
    List demo1 = listCreateDemo();
    List demo2 = listCreate();
    bool are_equal = false;
    if(listCompare(demo1, demo2, &are_equal) != LIST_SUCCESS){
        return false;
    }
    listDestroy(demo2);
    listDestroy(demo1);
    return !are_equal;
}
bool testCompareNullLists()
{
    List demo1 = NULL;
    List demo2 = NULL;
    bool are_equal = false;
    if(listCompare(demo1, demo2, &are_equal) != LIST_NULL_ARGUMENT){
        return false;
    }
    return true;
}

bool testListClear()
{
    List demo1 = listCreateDemo();
    listClear(demo1);
    List demo2 = listCreate();
    bool are_equal = false;
    listCompare(demo1, demo2, &are_equal);
    listDestroy(demo2);
    listDestroy(demo1);
    return are_equal;
}

bool testListRemoveElement()
{
    List demo = listCreateDemo();
    char* name = "milk";
    listRemoveElement(demo, name);
    int size = listGetSize(demo);
    listDestroy(demo);
    return size==2;
}

bool testListRemoveInsert()
{
    List demo = listCreateDemo();
    const char* name = "bread";
    listRemoveElement(demo, name);
    name = "a";
    listInsertLexicographic(demo, name);
    char* element_name = malloc(sizeof(*element_name));
    if(element_name == NULL){
        return false;
    }
    strcpy(element_name ,listReturnNameOfElement(listGetNext(demo)));
    listDestroy(demo);
    bool result = strcmp(name, element_name) == 0;
    free(element_name);
    return result;
}

bool testListSetAmountOfElement()
{
    List demo1 = listCreateDemo();
    List demo2 = listCreateDemo();
    const char* name = "bread";
    listSetAmountOfElement(demo2, 1, name);
    bool are_equal = true;
    listCompare(demo1, demo2, &are_equal);
    listDestroy(demo2);
    listDestroy(demo1);
    return !are_equal;
}

bool testListSetAmountOfElementEmpty()
{
    const char* name = "bread";
    List demo = listCreate();
    ListResult result = listSetAmountOfElement(demo, 1, name);
    listDestroy(demo);
    return result == LIST_ELEMENT_NOT_IN_LIST;
}

bool testListReturnAmountOfElementNotEmptyList()
{
    List demo = listCreateDemo();
    listDestroy(demo);
    return listReturnAmountOfElement(listGetNext(demo)) == DEMO_AMOUNT;
}
bool testListReturnAmountOfElementEmptyList()
{
    List demo = listCreate();
    listDestroy(demo);
    return listReturnAmountOfElement(listGetNext(demo)) == NULL_POINTER;
}

bool testListReturnNameOfElementNotEmptyList()
{
    List demo = listCreateDemo();
    listDestroy(demo);
    return strcmp(listReturnNameOfElement(listGetNext(demo)), "bread") == 0;
}
bool testListReturnNameOfElementEmptyList()
{
    List demo = listCreate();
    listDestroy(demo);
    return listReturnNameOfElement(listGetNext(demo)) == NULL;
}