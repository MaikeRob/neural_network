#include <stdio.h>
#include "headers/neural_network.h"


int main(){

    model_t model = create_model(2);
    add_layer(&model, 2, "relu");
    add_exit_layer(&model, 1, SIGMOID);
    destroy_model(&model);
    return 0;
}