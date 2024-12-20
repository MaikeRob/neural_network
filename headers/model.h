#ifndef MODEL_H
#define MODEL_H


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
} layer_t;

typedef struct model{
    unsigned int input_size;
    layer_t *layers;
    unsigned int num_layers;
} model_t;

#endif