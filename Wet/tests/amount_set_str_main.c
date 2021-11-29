#include "../amount_set_str.h"
#include "amount_set_str_tests.h"

int main()
{
    RUN_TEST(testAmountSetCreateAndDestory);
    RUN_TEST(testAsCopy);
    RUN_TEST(testAsCopyEmptySet);
    RUN_TEST(testAsGetSize);
    RUN_TEST(testAsGetSizeEmpty);
    RUN_TEST(testAsGetSizeNull);
    RUN_TEST(testAsContains);
    RUN_TEST(testAsContainsEmpty);
    RUN_TEST(testAsContainsNull);
    RUN_TEST(testAsGetAmountItemInSet);
    RUN_TEST(testAsGetAmountItemNotInSet);
    RUN_TEST(testAsGetAmountNullSet);
    RUN_TEST(testAsGetFirst);
    RUN_TEST(testAsGetFirstEmpty);
    RUN_TEST(testAsGetFirstNull);
    RUN_TEST(testAsGetNext);
    RUN_TEST(testAsGetNextEmpty);
    RUN_TEST(testAsGetNextNull);
    RUN_TEST(testAsChangeAmountItemInSet);
    RUN_TEST(testAsChangeAmountItemNotInSet);
    RUN_TEST(testAsChangeAmountNullSet);
    RUN_TEST(testAsChangeAmountNegativeValue);
    RUN_TEST(testAsRegisterInsertToNonEmptySet);
    RUN_TEST(testAsRegisterInsertToEmptySet);
    RUN_TEST(testAsRegisterInsertToNull);
    RUN_TEST(testAsDeleteExistingItem);
    RUN_TEST(testAsDeleteNonExistingItem);
    RUN_TEST(testAsDeleteNullSet);
    RUN_TEST(testAsClearNonEmptySet);
    RUN_TEST(testAsClearEmptySet);
    RUN_TEST(testAsClearNullSet);
}