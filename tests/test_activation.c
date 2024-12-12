#include "unity/unity.h"
#include "../headers/activation.h"

/*----------Testes de funções de ativição --------*/

void test_relu() {
    TEST_ASSERT_EQUAL(10, relu(10));
    TEST_ASSERT_EQUAL(5.45, relu(5.45));
    TEST_ASSERT_EQUAL(111111151515, relu(111111151515));
    TEST_ASSERT_EQUAL(0.0000001, relu(0.0000001));
    TEST_ASSERT_EQUAL(0, relu(-8));
    TEST_ASSERT_EQUAL(0, relu(-0.45548));
    TEST_ASSERT_EQUAL(0, relu(-46548643546));
}

void test_sigmoid() {
    TEST_ASSERT_EQUAL(0.5, sigmoid(0));
    TEST_ASSERT_EQUAL(0.73105857863, sigmoid(1));
    TEST_ASSERT_EQUAL(0.26894142136, sigmoid(-1));
    TEST_ASSERT_EQUAL(0.99987660542, sigmoid(10));
    TEST_ASSERT_EQUAL(0.00012339457, sigmoid(-10));
    TEST_ASSERT_EQUAL(0.99999969409, sigmoid(15));
    TEST_ASSERT_EQUAL(0.00000030590, sigmoid(-15));
    TEST_ASSERT_EQUAL(1, sigmoid(1000));
    TEST_ASSERT_EQUAL(0, sigmoid(-1000));

}

void test_tanh() {
    TEST_ASSERT_EQUAL(0, tanh(0));
    TEST_ASSERT_EQUAL(0.76159415595, tanh(1));
    TEST_ASSERT_EQUAL(-0.76159415595, tanh(-1));
    TEST_ASSERT_EQUAL(0.99999999997, tanh(10));
    TEST_ASSERT_EQUAL(-0.99999999997, tanh(-10));
    TEST_ASSERT_EQUAL(1, tanh(1000));
    TEST_ASSERT_EQUAL(-1, tanh(-1000));
}

void test_get_activation_function() {
    double (*activation)(double);
    activation = get_activation_function(RELU);
    TEST_ASSERT_EQUAL(10, relu(10));
    TEST_ASSERT_EQUAL(5.45, relu(5.45));
    TEST_ASSERT_EQUAL(111111151515, relu(111111151515));
    TEST_ASSERT_EQUAL(0.0000001, relu(0.0000001));
    TEST_ASSERT_EQUAL(0, relu(-8));
    TEST_ASSERT_EQUAL(0, relu(-0.45548));
    TEST_ASSERT_EQUAL(0, relu(-46548643546));

    activation = get_activation_function(SIGMOID);
    TEST_ASSERT_EQUAL(0.5, sigmoid(0));
    TEST_ASSERT_EQUAL(0.73105857863, sigmoid(1));
    TEST_ASSERT_EQUAL(0.26894142136, sigmoid(-1));
    TEST_ASSERT_EQUAL(0.99987660542, sigmoid(10));
    TEST_ASSERT_EQUAL(0.00012339457, sigmoid(-10));
    TEST_ASSERT_EQUAL(0.99999969409, sigmoid(15));
    TEST_ASSERT_EQUAL(0.00000030590, sigmoid(-15));
    TEST_ASSERT_EQUAL(1, sigmoid(1000));
    TEST_ASSERT_EQUAL(0, sigmoid(-1000));

    activation = get_activation_function(TANH);
    TEST_ASSERT_EQUAL(0, tanh(0));
    TEST_ASSERT_EQUAL(0.76159415595, tanh(1));
    TEST_ASSERT_EQUAL(-0.76159415595, tanh(-1));
    TEST_ASSERT_EQUAL(0.99999999997, tanh(10));
    TEST_ASSERT_EQUAL(-0.99999999997, tanh(-10));
    TEST_ASSERT_EQUAL(1, tanh(1000));
    TEST_ASSERT_EQUAL(-1, tanh(-1000));
}

