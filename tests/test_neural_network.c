#include "unity/unity.h"
#include "../headers/neural_network.h"

/*----------Testes da criação de modelo --------*/

void test_create_model_small_input() {
    model_t model = create_model(2);
    TEST_ASSERT_EQUAL(2, model.input_size);
    TEST_ASSERT_EQUAL(0, model.num_layers);
    TEST_ASSERT_NULL(model.layers);
}

void test_create_model_big_input() {
    model_t model = create_model(728);
    TEST_ASSERT_EQUAL(728, model.input_size);
    TEST_ASSERT_EQUAL(0, model.num_layers);
    TEST_ASSERT_NULL(model.layers);
    TEST_ASSERT_EQUAL(false, model.is_complete);
}

/*----------Testes da adição de camadas --------*/

void test_add_fist_layer() {
    model_t model = create_model(728);
    add_layer(&model, 3, RELU);
    TEST_ASSERT_EQUAL("relu", model.layers[0].activation);
    TEST_ASSERT_EQUAL(1, model.num_layers);
    TEST_ASSERT_EQUAL(3, model.layers[0].num_neurons);
    TEST_ASSERT_EQUAL(2184, model.layers[0].num_connections);
    TEST_ASSERT_EQUAL(false, model.is_complete);
}

void test_add_second_layer() {
    model_t model = create_model(728);
    add_layer(&model, 10, RELU);
    add_layer(&model, 5, SIGMOID);
    TEST_ASSERT_EQUAL(SIGMOID, model.layers[1].activation);
    TEST_ASSERT_EQUAL(2, model.num_layers);
    TEST_ASSERT_EQUAL(5, model.layers[1].num_neurons);
    TEST_ASSERT_EQUAL(50, model.layers[1].num_connections);
    TEST_ASSERT_EQUAL(false, model.is_complete);
}
    
void test_add_third_layer() {
    model_t model = create_model(728);
    add_layer(&model, 10, RELU);
    add_layer(&model, 5, SIGMOID);
    add_layer(&model, 3, RELU);
    TEST_ASSERT_EQUAL(RELU, model.layers[2].activation);
    TEST_ASSERT_EQUAL(3, model.num_layers);
    TEST_ASSERT_EQUAL(3, model.layers[2].num_neurons);
    TEST_ASSERT_EQUAL(15, model.layers[2].num_connections);
    TEST_ASSERT_EQUAL(false, model.is_complete);
}

void test_add_last_layer() {
    model_t model = create_model(728);
    add_layer(&model, 10, RELU);
    add_layer(&model, 5, SIGMOID);
    add_layer(&model, 3, RELU);
    add_exit_layer(&model, 10, TANH);
    TEST_ASSERT_EQUAL(TANH, model.layers[3].activation);
    TEST_ASSERT_EQUAL(4, model.num_layers);
    TEST_ASSERT_EQUAL(10, model.layers[3].num_neurons);
    TEST_ASSERT_EQUAL(30, model.layers[3].num_connections);
    TEST_ASSERT_EQUAL(true, model.is_complete);
}
