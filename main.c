#include <stdio.h>
#include "headers/neural_network.h"

int main(){

    model_t model = create_model(728);
    add_layer(&model, 3, "relu");
    printf("Activation layer 1: %s\n", model.layers[0].activation);
    add_layer(&model, 10, SIGMOID);
    printf("Activation layer 2: %s\n", model.layers[1].activation);
    destroy_model(&model);
    return 0;
}