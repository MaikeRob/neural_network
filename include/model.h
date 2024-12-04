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
    connection_t *connections;
    int num_neurons;
    int num_connections;
    const char *activation;
} layer_t;

typedef struct model{
    int input_size;
    layer_t *layers;
    int num_layers;
} model_t;

#endif