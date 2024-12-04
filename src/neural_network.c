#include <stdlib.h>
#include "../include/model.h"
#include "../include/activation.h"
#include "../include/neural_network.h"


model_t create_model(int input_size) {

    model_t *model = (model_t *)malloc(sizeof(model_t));

    if(model == NULL) {
        //TODO: Handle error    
        exit(1);
    }

    model->input_size = input_size;
    model->num_layers = 0;
    model->layers = NULL;

    return *model;
}

void destroy_model(model_t *model) {
    if (model->layers != NULL) {
        free(model->layers);
    }
    free(model);
}

void add_layer(model_t *model, int num_neurons, const char *activation){

    layer_t *layer = (layer_t*)malloc(sizeof(layer_t));
    if(layer == NULL) {
        //TODO Handle error
        exit(1);
    }

    int last_layer_size;
    if(model->layers == NULL) {
        last_layer_size = model->input_size;
        
        model->layers = (layer_t*)malloc(sizeof(layer_t));

        model->layers[0] = *layer;
    } else {
        last_layer_size = model->layers[model->num_layers - 1].num_neurons;

        model->layers = (layer_t*)realloc(model->layers, model->num_layers * sizeof(layer_t));

        model->layers[model->num_layers - 1] = *layer;
    }
    
    layer->num_neurons = num_neurons;
    layer->neurons = (neuron_t*)malloc(num_neurons * sizeof(neuron_t));
    if(layer->neurons == NULL) {
        //TODO Handle error
        exit(1);
    }
    for(int i = 0; i < num_neurons; i++) {
        layer->neurons[i].bias = 0.0;
    }

    layer->num_connections = num_neurons * last_layer_size;
    layer->connections = (connection_t*)malloc(num_neurons * sizeof(connection_t));
    if(layer->connections == NULL) {
        //TODO Handle error
        exit(1);
    }
    for(int i = 0; i < num_neurons; i++) {
        layer->connections[i].weight = 0.0;
    }

    layer->activation = activation;
    model->num_layers++;
}