#ifndef LIST_STR_H_
#define LIST_STR_H_

#include <stdbool.h>

/** Type for defining the list */
typedef struct List_t *List;

/** Type used for returning error codes from list functions */
typedef enum ListResult_t {
	LIST_SUCCESS,
	LIST_NULL_ARGUMENT,
	LIST_ELEMENT_NOT_IN_LIST,
	LIST_OUT_OF_MEMORY,
} ListResult;

/**
* Allocates a new List.
*
* Creates a new empty list.
* @return
* 	NULL - if one of the parameters is NULL or allocations failed.
* 	A new List in case of success.
*/
List listCreate();

/**
* listDestroy: Deallocates an existing list. Clears all elements by using the
* stored free function.
*
* @param list Target list to be deallocated. If list is NULL nothing will be
* done
*/
void listDestroy(List list);

/**
* Creates a copy of target list.
*
* The new copy will contain all the elements from the source list in the same
* order.
*
* @param list The target list to copy
* @return
* NULL if a NULL was sent or a memory allocation failed.
* A List containing the same elements with same order as list otherwise.
*/
List listCopy(List list);

/**
* Returns the number of elements in a list
*
* @param list The target list which size is requested.
* @return
* -1 if a NULL pointer was sent.
* Otherwise the number of elements in the list.
*/
int listGetSize(List list);

/**
 * Inserts element at the start of the list 
 * 
 * @param list Target list to add element
 * @param element Element to add to the list
 * @return 
 * LIST_NULL_ARGUMENT - if a NULL pointer was sent.
 * LIST_SUCCESS - Otherwise. 
 */
ListResult listInsertFirst(List list, const char* element);

/**
* Adds a new element to the list with amount 0, the new element will inserted in a way that keeps
* the list sorted in a lexicographic order.
*
* @param list The list for which to add an element in its start
* @param element The element to insert. A copy of the element will be inserted
* @return
* LIST_NULL_ARGUMENT if a NULL was sent as list
* LIST_OUT_OF_MEMORY if an allocation failed (Meaning the function for copying
* an element failed)
* LIST_SUCCESS the element has been inserted successfully
*/
ListResult listInsertLexicographic(List list, const char* element);

/**
 * Changes the amount of the target element in the target list to the targeted amount.
 * 
 * @param list The that contains the element to change its amount 
 * @param amount The new amount for the target element
 * @param element The element to change its amount
 * @return 
 * LIST_NULL_ARGUMENT if a NULL was sent as list
 * LIST_ELEMENT_NOT_IN_LIST if element was not found in list
 * LIST_SUCCESS the element has been inserted successfully
 */
ListResult listSetAmountOfElement(List list, double amount, const char* element);

/**
* Removes the given element from the list
*
* @param list The list for which the current element will be removed
* @return
* LIST_NULL_ARGUMENT if list is NULL
* LIST_SUCCESS the current element was removed successfully
*/
ListResult listRemoveElement(List list, const char* element);

/**
* Removes all elements from target list.
*
* All of the elements are deallocated.
* @param list Target list to remove all element from
* @return
* LIST_NULL_ARGUMENT - if a NULL pointer was sent.
* LIST_SUCCESS - Otherwise.
*/
ListResult listClear(List list);

/**
 * compares list1 to list2 
 * 
 * @param list1 First list to compare 
 * @param list2 Second list to compare
 * @param result Stores the result of the comparsion. 
 * true - if lists are equal, false - Otherwise
 * @return 
 * LIST_NULL_ARGUMENT - if a NULL pointer was sent.
 * LIST_SUCCESS - Otherwise 
 */
ListResult listCompare(List list1, List list2, bool* result);

/**
 * Returns amount of given element.
 * 
 * @param element - element its amount will be returned 
 * @return 
 * -1 if element is NULL
 * amount of element otherwise 
 */
double listReturnAmountOfElement(List element);

/**
 * Returns name of given element
 * 
 * @param element - element name to return
 * @return
 * NULL if element is NULL 
 * element name otherwise
 */
const char* listReturnNameOfElement(List element);

/**
 * Returns a pointer to the next element of list
 * 
 * @param list - list its next will be returned
 * NULL if list is NULL or empty
 * pointer to list's next element otherwise
 * 
 */
List listGetNext(List list);


#endif /* LIST_STR_H_ */
