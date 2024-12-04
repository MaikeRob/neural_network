#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "../include/model.h"
#include "../include/activation.h"


model_t create_model(int input_size); // TODO

void destroy_model(model_t *model); // TODO

void add_layer(model_t *model, int num_neurons, const char *activation); // TODO

void train(); // TODO

void predict(); // TODO

#endif