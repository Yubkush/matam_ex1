#include "../amount_set_str.h"
#include "amount_set_str_tests.h"
#include <string.h>
#include <stdlib.h>
#define NAMES 3
#define DEMO_AMOUNT 10
#define NULL_POINTER -1
#define NEW_AMOUNT 6.0
#define PRODUCT_NAME_1 "bread"
#define PRODUCT_NAME_2 "milk"
#define PRODUCT_NAME_3 "rice"
#define PRODUCT_NOT_IN_SET "corn"

static AmountSet amountSetCreateDemo()
{
    AmountSet demo = asCreate();
    if(demo == NULL){
        return NULL;
    }
    char *names[NAMES] = {PRODUCT_NAME_2,PRODUCT_NAME_3,PRODUCT_NAME_1};
    for(int i = 0; i < NAMES; i++)
    {
        asRegister(demo, names[i]);
        asChangeAmount(demo, names[i], DEMO_AMOUNT);
    }
    return demo;
}

bool testAmountSetCreateAndDestory()
{
    AmountSet created_set = asCreate();
    if(created_set == NULL){
        return false;
    }
    asDestroy(created_set);
    return true;
}

bool testAsCopy(AmountSet set)
{
    AmountSet demo = amountSetCreateDemo();
    AmountSet copy = asCopy(demo);
    bool are_equal = false;
    asCompare(demo, copy, &are_equal);
    asDestroy(demo);
    asDestroy(copy);
    return are_equal;
}
bool testAsCopyEmptySet(AmountSet set)
{
    AmountSet demo = asCreate();
    AmountSet copy = asCopy(demo);
    bool are_equal = false;
    asCompare(demo, copy, &are_equal);
    asDestroy(demo);
    asDestroy(copy);
    return are_equal;
}
bool testAsCopyNull()
{
    AmountSet demo = NULL;
    AmountSet copy = asCopy(demo);
    return copy == NULL;
}

bool testAsGetSize()
{
    AmountSet demo = amountSetCreateDemo();
    int size = asGetSize(demo);
    asDestroy(demo);
    return size == NAMES;
}
bool testAsGetSizeEmpty()
{
    AmountSet demo = asCreate();
    int size = asGetSize(demo);
    asDestroy(demo);
    return size == 0;
}
bool testAsGetSizeNull()
{
    AmountSet demo = NULL;
    int size = asGetSize(demo);
    return size == NULL_POINTER;
}

bool testAsContains()
{
    AmountSet demo = amountSetCreateDemo();
    char* name = PRODUCT_NAME_1;
    bool contains = asContains(demo, name);
    asDestroy(demo);
    return contains;
}
bool testAsContainsEmpty()
{
    AmountSet demo = asCreate();
    char* name = PRODUCT_NAME_2;
    bool contains = asContains(demo, name);
    asDestroy(demo);
    return !contains;
}
bool testAsContainsNull()
{
    AmountSet demo = NULL;
    char* name = PRODUCT_NAME_2;
    bool contains = asContains(demo, name);
    return !contains;
}

bool testAsGetAmountItemInSet()
{
    AmountSet demo = amountSetCreateDemo();
    char* name = PRODUCT_NAME_2;
    double amount = 0;
    if(asGetAmount(demo, name, &amount) != AS_SUCCESS){
        return false;
    }
    bool result = (amount == DEMO_AMOUNT);
    asDestroy(demo);
    return result;
}
bool testAsGetAmountItemNotInSet()
{
    AmountSet demo = amountSetCreateDemo();
    char* name = PRODUCT_NOT_IN_SET;
    double amount = 0;
    if(asGetAmount(demo, name, &amount) == AS_ITEM_DOES_NOT_EXIST){
        asDestroy(demo);
        return true;
    }
    asDestroy(demo);
    return false;
}
bool testAsGetAmountNullSet()
{
    AmountSet demo = NULL;
    char* name = PRODUCT_NAME_1;
    double amount = 0;
    if(asGetAmount(demo, name, &amount) == AS_NULL_ARGUMENT){
        return true;
    }
    return false;
}

bool testAsGetFirst()
{
    AmountSet demo = amountSetCreateDemo();
    char* name = PRODUCT_NAME_1;
    bool result = (strcmp(name, asGetFirst(demo))==0);
    asDestroy(demo);
    return result;
}
bool testAsGetFirstEmpty()
{
    AmountSet demo = asCreate();
    bool result = (asGetFirst(demo) == NULL);
    asDestroy(demo);
    return result;
}
bool testAsGetFirstNull()
{
    AmountSet demo = NULL;
    bool result = (asGetFirst(demo) == NULL);
    return result;
}

bool testAsGetNext()
{
    AmountSet demo = amountSetCreateDemo();
    char* name = PRODUCT_NAME_1;
    bool result = (strcmp(name, asGetNext(demo))==0);
    asDestroy(demo);
    return result;
}
bool testAsGetNextEmpty()
{
    AmountSet demo = asCreate();
    bool result = (asGetNext(demo) == NULL);
    asDestroy(demo);
    return result;
}
bool testAsGetNextNull()
{
    AmountSet demo = NULL;
    bool result = (asGetNext(demo) == NULL);
    return result;
}

bool testAsChangeAmountItemInSet()
{
    AmountSet demo = amountSetCreateDemo();
    if(asChangeAmount(demo, PRODUCT_NAME_3, NEW_AMOUNT) != AS_SUCCESS){
        return false;
    }
    double output = 0;
    if(asGetAmount(demo, PRODUCT_NAME_3, &output) != AS_SUCCESS){
        return false;
    }
    asDestroy(demo);
    return output == NEW_AMOUNT + DEMO_AMOUNT;
}
bool testAsChangeAmountItemNotInSet()
{
    AmountSet demo = amountSetCreateDemo();
    AmountSetResult output = asChangeAmount(demo, PRODUCT_NOT_IN_SET, NEW_AMOUNT);
    bool result = output == AS_ITEM_DOES_NOT_EXIST;
    asDestroy(demo);
    return result;
}
bool testAsChangeAmountNullSet()
{
    AmountSet demo = NULL;
    AmountSetResult output = asChangeAmount(demo, PRODUCT_NAME_1, NEW_AMOUNT);
    bool result = output == AS_NULL_ARGUMENT;
    return result;
}
bool testAsChangeAmountNegativeValue()
{
    AmountSet demo = amountSetCreateDemo();
    AmountSetResult output = asChangeAmount(demo, PRODUCT_NAME_2, -10.1);
    bool result = output == AS_INSUFFICIENT_AMOUNT;
    asDestroy(demo);
    return result;
}

bool testAsRegisterInsertToNonEmptySet()
{
    const char* item_to_add = PRODUCT_NOT_IN_SET;
    AmountSet demo = amountSetCreateDemo();
    if(asRegister(demo, item_to_add) != AS_SUCCESS){
        return false;
    }
    if(!asContains(demo, item_to_add)){
        return false;
    }
    asGetFirst(demo);
    if(strcmp(asGetNext(demo),item_to_add) != 0){
        return false;
    }
    asDestroy(demo);
    return true;
}
bool testAsRegisterInsertToEmptySet()
{
    const char* item_to_add = PRODUCT_NOT_IN_SET;
    AmountSet demo = asCreate();
    if(asRegister(demo, item_to_add) != AS_SUCCESS){
        return false;
    }
    if(!asContains(demo, item_to_add)){
        return false;
    }
    asDestroy(demo);
    return true;
}
bool testAsRegisterInsertToNull()
{
    const char* item_to_add = PRODUCT_NOT_IN_SET;
    AmountSet demo = NULL;
    if(asRegister(demo, item_to_add) != AS_NULL_ARGUMENT){
        return false;
    }
    if(asContains(demo, item_to_add)){
        return false;
    }
    return true;
}

bool testAsDeleteExistingItem()
{
    AmountSet demo = amountSetCreateDemo();
    const char* item_to_delete = PRODUCT_NAME_2;
    if(asDelete(demo, item_to_delete) != AS_SUCCESS){
        return false;
    }
    if(asContains(demo, item_to_delete)){
        return false;
    }
    asDestroy(demo);
    return true;
}
bool testAsDeleteNonExistingItem()
{
    AmountSet demo = amountSetCreateDemo();
    const char* item_to_delete = PRODUCT_NOT_IN_SET;
    if(asDelete(demo, item_to_delete) != AS_ITEM_DOES_NOT_EXIST){
        asDestroy(demo);
        return false;
    }
    asDestroy(demo);
    return true;
}
bool testAsDeleteNullSet()
{
    AmountSet demo = NULL;
    const char* item_to_delete = PRODUCT_NOT_IN_SET;
    if(asDelete(demo, item_to_delete) != AS_NULL_ARGUMENT){
        return false;
    }
    return true;
}

bool testAsClearNonEmptySet()
{
    AmountSet demo = amountSetCreateDemo();
    asClear(demo);
    bool result = (asGetFirst(demo) == NULL);
    asDestroy(demo);
    return result;
}
bool testAsClearEmptySet()
{
    AmountSet demo = asCreate();
    asClear(demo);
    bool result = (asGetFirst(demo) == NULL);
    asDestroy(demo);
    return result;
}
bool testAsClearNullSet()
{
    AmountSet demo = NULL;
    if(asClear(demo) != AS_NULL_ARGUMENT){
        return false;
    }
    return true;
}