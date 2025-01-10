#ifndef MODEL_H
#define MODEL_H
#include <stdbool.h>

typedef struct connection{
    double weight;
} connection_t;

typedef struct neuron{
    double bias;
    unsigned int num_previous_connections;
    connection_t *previous_connections;
} neuron_t;

typedef struct layer{
    neuron_t *neurons;
    unsigned int num_neurons;
    const char *activation;
    double (*activation_function)(double);
} layer_t;

typedef struct model{
    unsigned int input_size;
    layer_t *layers;
    unsigned int num_layers;
    bool is_complete;
} model_t;

#endif