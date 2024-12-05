#include <stdlib.h>
#include "../headers/model.h"
#include "../headers/activation.h"
#include "../headers/neural_network.h"


model_t create_model(unsigned int input_size) {

    if(input_size <= 0) {
        // TODO: Handle error
        exit(1);
    }

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
        for(unsigned int i = 0; i < model->num_layers; i++) {
            free(model->layers[i].neurons);
            free(model->layers[i].previous_connections);
        }
        free(model->layers);
    }
    free(model);
}

void add_layer(model_t *model, unsigned int num_neurons, const char *activation){

    unsigned int last_layer_size;
    if(model->num_layers == 0) {
        last_layer_size = model->input_size;
    } else {
        last_layer_size = model->layers[model->num_layers - 1].num_neurons;
    }

    layer_t *updated_layer = (layer_t*)realloc(model->layers, (model->num_layers + 1) * sizeof(layer_t));
    if(updated_layer == NULL) {
        //TODO Handle error
        exit(1);
    }
    model->layers = updated_layer;

    layer_t *new_layer = &model->layers[model->num_layers];

    new_layer->num_neurons = num_neurons;
    new_layer->neurons = (neuron_t*)malloc(num_neurons * sizeof(neuron_t));
    if(new_layer->neurons == NULL) {
        //TODO Handle error
        exit(1);
    }
    for(unsigned int i = 0; i < num_neurons; i++) {
        new_layer->neurons[i].bias = 0.0;
    }

    unsigned int num_connections = num_neurons * last_layer_size;
    new_layer->num_connections = num_connections;
    new_layer->previous_connections = (connection_t*)malloc(num_connections * sizeof(connection_t));
    if(new_layer->previous_connections == NULL) {
        //TODO Handle error
        exit(1);
    }
    for(unsigned int i = 0; i < new_layer->num_connections; i++) {
        new_layer->previous_connections[i].weight = 0.0;
    }

    new_layer->activation = activation;
    model->num_layers++;
}