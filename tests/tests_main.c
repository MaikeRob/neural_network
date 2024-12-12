#include "unity/unity.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

// neural_network tests
extern void test_create_model_small_input();
extern void test_create_model_big_input();
extern void test_add_fist_layer();
extern void test_add_second_layer();
extern void test_add_third_layer();

// activation tests
extern void test_relu();
extern void test_sigmoid();
extern void test_tanh();
extern void test_get_activation_function();

void main(){
    UNITY_BEGIN();

    // neural_network tests
    RUN_TEST(test_create_model_small_input);
    RUN_TEST(test_create_model_big_input);
    RUN_TEST(test_add_fist_layer);
    RUN_TEST(test_add_second_layer);
    RUN_TEST(test_add_third_layer);

    // activation tests
    RUN_TEST(test_relu);
    RUN_TEST(test_sigmoid);
    RUN_TEST(test_tanh);
    RUN_TEST(test_get_activation_function);

    return UNITY_END();
}