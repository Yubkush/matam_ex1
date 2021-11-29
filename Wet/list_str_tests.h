#ifndef LIST_STR_TESTS_H_
#define LIST_STR_TESTS_H_
#include <stdio.h>
#include <stdbool.h>

bool testCreateAndDestory();
bool testListGetSize();
bool testListGetSizeEmpty();
bool testListGetSizeNull();
bool testListCopy();
bool testListCopyEmpty();
bool testListCopyNull();
bool testCompareList();
bool testCompareEmptyLists();
bool testCompareDifferentLists();
bool testCompareNullLists();
bool testListClear();
bool testListRemoveElement();
bool testListRemoveInsert();
bool testListSetAmountOfElement();
bool testListSetAmountOfElementEmpty();
bool testListReturnAmountOfElementNotEmptyList();
bool testListReturnAmountOfElementEmptyList();
bool testListReturnNameOfElementNotEmptyList();
bool testListReturnNameOfElementEmptyList();


/**
 * Macro to run a test function and print its result.
 * 
 * @param test A test function that returns true if the test passed
 * and false if it failed
 */
#define RUN_TEST(test) \
do { \
  printf("Running " #test "... "); \
  if (test()) { \
    printf("[OK]"); \
  } \
  printf("\n"); \
} while(0)

#endif /* LIST_STR_TESTS_H_ */

