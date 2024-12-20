#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "../headers/model.h"
#include "../headers/activation.h"


model_t create_model(unsigned int input_size); // TODO

void destroy_model(model_t *model); // TODO

void add_layer(model_t *model, unsigned int num_neurons, const char *activation); // TODO

void train(); // TODO

void predict(model_t model, double *input); // TODO

#endif