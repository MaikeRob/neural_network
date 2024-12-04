#include "include/neural_network.h"

int main(){

    model_t model = create_model(2);
    add_layer(&model, 3, "relu");
    add_layer(&model, 10, SIGMOID);
    destroy_model(&model);
    return 0;
}