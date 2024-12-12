#include <stdio.h>
#include "headers/neural_network.h"
#include "libs/generic_openblas/include/cblas.h"


int main(){

    model_t model = create_model(728);
    add_layer(&model, 3, "relu");
    add_layer(&model, 10, SIGMOID);
    destroy_model(&model);
    return 0;
}