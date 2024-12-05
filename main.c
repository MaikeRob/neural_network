#include <stdio.h>
#include "headers/neural_network.h"

int main(){

    model_t model = create_model(728);
    add_layer(&model, 3, "relu");
    printf("Connections layer 1: %i\n", model.layers[0].num_connections);
    add_layer(&model, 10, SIGMOID);
    printf("Connections layer 1: %i\n", model.layers[1].num_connections);
    destroy_model(&model);
    return 0;
}