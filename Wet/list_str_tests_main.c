#include "list_str_tests.h"

int main()
{
    RUN_TEST(testCreateAndDestory);
    RUN_TEST(testListGetSize);
    RUN_TEST(testListGetSizeEmpty);
    RUN_TEST(testListGetSizeNull);
    RUN_TEST(testListCopy);
    RUN_TEST(testListCopyEmpty);
    RUN_TEST(testListCopyNull);
    RUN_TEST(testCompareList);
    RUN_TEST(testCompareDifferentLists);
    RUN_TEST(testCompareEmptyLists);
    RUN_TEST(testCompareNullLists);
    RUN_TEST(testListClear);
    RUN_TEST(testListRemoveElement);
    RUN_TEST(testListRemoveInsert);
    RUN_TEST(testListSetAmountOfElement);
    RUN_TEST(testListSetAmountOfElementEmpty);
    RUN_TEST(testListReturnAmountOfElementNotEmptyList);
    RUN_TEST(testListReturnAmountOfElementEmptyList);
    RUN_TEST(testListReturnNameOfElementEmptyList);
    RUN_TEST(testListReturnNameOfElementEmptyList);
    return 0;
}