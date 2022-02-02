cmake_minimum_required(VERSION 3.0.0)
project(ex1 VERSION 0.1.0 LANGUAGES C)

set(MTM_FLAGS_DEBUG "-std=c99 --pedantic-errors -Wall -Werror")
set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

set(CMAKE_C_FLAGS ${MTM_FLAGS_DEBUG})

add_executable(list_tests Wet/amount_set_str_list_str.c Wet/amount_set_str_list_str_tests.c Wet/amount_set_str_list_str_tests_main.c)
# add_executable(tests_extended Wet/matamikya.c Wet/matamikya_product.c Wet/matamikya_order.c Wet/matamikya_print.c Wet/tests/extra/biadsy_tests/biadsy_matamikya_tests.c)
# target_link_libraries(tests_extended ${CMAKE_SOURCE_DIR}/Wet/libas.a ${CMAKE_SOURCE_DIR}/Wet/libmtm.a)