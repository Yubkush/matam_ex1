#include "amount_set.h"
#include "matamikya.h"
#include "set.h"
#include <stdlib.h>
#include <string.h>
#define RETURN_IF_NULL(pointer, return_value)\
        if(pointer == NULL){\
            return return_value;\
        }\

typedef struct product_t
{
    char* name;
    unsigned int id;
    MtmProductData product_data;
    MtmCopyData product_data_copy_function;
    MtmFreeData product_data_free_function;
    MtmGetProductPrice product_data_get_price;
    MatamikyaAmountType amount_type;
}*Product;

static ASElement createProduct(const char* name, const unsigned int id, 
                            MtmProductData product_data, MatamikyaAmountType amount_type,
                            MtmCopyData copy_function, MtmFreeData free_function,
                            MtmGetProductPrice price_function)
{
    Product product = malloc(sizeof(*product));
    RETURN_IF_NULL(product, NULL);
    product->name = malloc(sizeof(*name));
    if(product->name == NULL){
        free(product);
        return NULL;
    }
    strcpy(product->name, name);
    product->id = id;
    product->product_data = copy_function(product_data);
    if(product->product_data == NULL){
        free(product->name);
        free(product);
        return NULL;
    }
    product->product_data_copy_function = copy_function;
    product->product_data_free_function = free_function;
    product->product_data_get_price = price_function;
    product->amount_type = amount_type;
    return (ASElement)product;
}

static ASElement copyProduct(ASElement product)
{
    Product product_copy = malloc(sizeof(*product_copy));
    RETURN_IF_NULL(product_copy, NULL);
    product_copy->name = malloc(sizeof(*(((Product)product)->name)));
    if(product_copy->name == NULL){
        free(product);
        return NULL;
    }
    strcpy(product_copy->name, ((Product)product)->name);
    product_copy->id = ((Product)product)->id;
    product_copy->product_data = ((Product)product)->
                                product_data_copy_function(((Product)product)->product_data);
    if(product_copy->product_data == NULL){
        free(product_copy->name);
        free(product_copy);
        return NULL;
    }
    product_copy->product_data_copy_function = ((Product)product)->product_data_copy_function;
    product_copy->product_data_free_function = ((Product)product)->product_data_free_function;
    product_copy->product_data_get_price = ((Product)product)->product_data_get_price;
    product_copy->amount_type = ((Product)product)->amount_type;
    return (ASElement)product_copy;
}

static void freeProduct(ASElement product)
{
    free(((Product)product)->name);
    ((Product)product)->product_data_free_function(((Product)product)->product_data);
    free(product);
}

static int compareProduct(ASElement product1, ASElement product2)
{
    return ((Product)product1)->id - ((Product)product2)->id;
}

typedef struct order_t
{
    unsigned int id;
    AmountSet products;
}*Order;

static SetElement createOrder(const unsigned int id, CopyASElement product_copy_function, 
                        FreeASElement product_free_function, CompareASElements product_compare_function)
{
    Order order = malloc(sizeof(*order));
    RETURN_IF_NULL(order, NULL);
    order->id = id;
    order->products = asCreate(product_copy_function, product_free_function, product_compare_function);
    return (SetElement)order;
}

static SetElement copyOrder(SetElement order)
{
    Order order_copy = malloc(sizeof(*order_copy));
    RETURN_IF_NULL(order_copy, NULL);
    order_copy->id = ((Order)order)->id;
    order_copy->products = asCopy(((Order)order)->products);
    if(order_copy->products == NULL){
        free(order_copy);
        return NULL;
    }
    return (SetElement)order_copy;
}

static void freeOrder(SetElement order)
{
    asDestroy(((Order)order)->products);
    free(order);
}

static int compareOrder(SetElement order1, SetElement order2)
{
    return ((Order)order1)->id - ((Order)order2)->id;
}

struct Matamikya_t
{
    AmountSet storage;
    Set orders;
    AmountSet profit;
    unsigned int next_order_id;
};

Matamikya matamikyaCreate()
{
    Matamikya matamikya = malloc(sizeof(*matamikya));
    RETURN_IF_NULL(matamikya, NULL);
    matamikya->storage = NULL;
    matamikya->orders = NULL;
    matamikya->profit = NULL;
    matamikya->next_order_id = 1;
    return matamikya;
}

void matamikyaDestroy(Matamikya matamikya)
{
    RETURN_IF_NULL(matamikya,);
    asDestroy(matamikya->storage);
    setDestroy(matamikya->orders);
    asDestroy(matamikya->profit);
    free(matamikya);
}

MatamikyaResult mtmNewProduct(Matamikya matamikya, const unsigned int id, const char *name,
                              const double amount, const MatamikyaAmountType amountType,
                              const MtmProductData customData, MtmCopyData copyData,
                              MtmFreeData freeData, MtmGetProductPrice prodPrice)
{
    RETURN_IF_NULL(matamikya, MATAMIKYA_NULL_ARGUMENT);
    Product product_to_add = createProduct(name, id, customData, amountType, copyData);
    RETURN_IF_NULL(product_to_add, NULL);
    ProductCopyData (product_copy_function)(product_to_add, copyData) = copyProduct;
    if(matamikya->storage == NULL){
        matamikya->storage = asCreate();
    }
}

unsigned int mtmCreateNewOrder(Matamikya matamikya)
{
    if(matamikya->orders == NULL){
        matamikya->orders = setCreate(product_copy_function,
                                product_free_function, product_compare_function);
    }
    Order new_order = createOrder(matamikya->next_order_id, );
    setAdd(matamikya->orders, new_order);
}