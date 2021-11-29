#ifndef AMOUNT_SET_STR_TESTS_H_
#define AMOUNT_SET_STR_TESTS_H_
#include <stdbool.h>

bool testAmountSetCreateAndDestory();
bool testAsCopy();
bool testAsCopyEmptySet();
bool testAsGetSize();
bool testAsGetSizeEmpty();
bool testAsGetSizeNull();
bool testAsContains();
bool testAsContainsEmpty();
bool testAsContainsNull();
bool testAsGetAmountItemInSet();
bool testAsGetAmountItemNotInSet();
bool testAsGetAmountNullSet();
bool testAsGetFirst();
bool testAsGetFirstEmpty();
bool testAsGetFirstNull();
bool testAsGetNext();
bool testAsGetNextEmpty();
bool testAsGetNextNull();
bool testAsChangeAmountItemInSet();
bool testAsChangeAmountItemNotInSet();
bool testAsChangeAmountNullSet();
bool testAsChangeAmountNegativeValue();
bool testAsRegisterInsertToNonEmptySet();
bool testAsRegisterInsertToEmptySet();
bool testAsRegisterInsertToNull();
bool testAsDeleteExistingItem();
bool testAsDeleteNonExistingItem();
bool testAsDeleteNullSet();
bool testAsClearNonEmptySet();
bool testAsClearEmptySet();
bool testAsClearNullSet();


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

#endif /* AMOUNT_SET_STR_TESTS_H_ */