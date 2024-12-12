#ifndef MODEL_H
#define MODEL_H
#include <stdbool.h>

typedef struct connection{
    double weight;
} connection_t;

typedef struct neuron{
    double bias;
} neuron_t;

typedef struct layer{
    neuron_t *neurons;
    connection_t *previous_connections;
    unsigned int num_neurons;
    unsigned int num_connections;
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