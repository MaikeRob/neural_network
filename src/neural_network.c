#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../headers/model.h"
#include "../headers/activation.h"
#include "../headers/neural_network.h"


model_t create_model(unsigned int input_size) {

    // TODO: Validate input

    model_t model;
    model.input_size = input_size;
    model.num_layers = 0;
    model.layers = NULL;
    model.is_complete = false;

    return model;
}

void destroy_model(model_t *model) {

    // TODO: Validate input

    if (model->layers != NULL) {
        for(unsigned int i = 0; i < model->num_layers; i++) {
            unsigned int num_neurons = model->layers[i].num_neurons;

            for(unsigned int j = 0; j < num_neurons; j++){
                free(model->layers[i].neurons[j].previous_connections);
            }

            free(model->layers[i].neurons);
        }
        free(model->layers);
    }
}

void add_layer(model_t *model, unsigned int num_neurons, const char *activation){

    // TODO: Validate input

    unsigned int last_layer_size;
    if(model->num_layers == 0) {
        last_layer_size = model->input_size;
    } else {
        last_layer_size = model->layers[model->num_layers - 1].num_neurons;
    }

    layer_t *updated_layers = (layer_t*)realloc(model->layers, (model->num_layers + 1) * sizeof(layer_t));
    if(updated_layers == NULL) {
        //TODO Handle error
        printf("Error reallocating memory\n");
        exit(1);
    }
    model->layers = updated_layers;

    layer_t *new_layer = &model->layers[model->num_layers];

    new_layer->num_neurons = num_neurons;
    new_layer->neurons = (neuron_t*)malloc(num_neurons * sizeof(neuron_t));
    if(new_layer->neurons == NULL) {
        //TODO Handle error
        printf("Error allocating memory\n");
        exit(1);
    }


    unsigned int num_previous_connections = last_layer_size;

    for(unsigned int i = 0; i < num_neurons; i++){
        new_layer->neurons[i].bias = 0.0;

        new_layer->neurons[i].previous_connections = (connection_t*)malloc(num_previous_connections * sizeof(connection_t));
        if(new_layer->neurons[i].previous_connections == NULL){
            //TODO Handle error
            printf("Error allocating memory\n");
            exit(1);
        }

        for(unsigned int j = 0; j < num_previous_connections; j++){

            new_layer->neurons[i].previous_connections[i].weight = 0.0;
        }
    }

    new_layer->activation = activation;
    new_layer->activation_function = get_activation_function(activation);
    model->num_layers++;
}

void add_exit_layer(model_t *model, unsigned int num_neurons, const char *activation){

    // TODO Validate input

    add_layer(model, num_neurons, activation);
    // TODO Handle possible error

    model->is_complete = true;
}

double *predict(model_t model, double *input) {

    // TODO Validate input

    double *output = (double*)malloc(model.layers[model.num_layers - 1].num_neurons * sizeof(double));
    if(output == NULL) {
        //TODO Handle error
        printf("Error allocating memory\n");
        exit(1);
    }

    for(unsigned int i; i < model.num_layers; i++) {

        double current_inputs[model.layers[i-1].num_neurons];
        for(unsigned int j; j < model.layers[i-1].num_neurons; j++){

            double current_wheights[model.layers[i-1].num_neurons];
        }

    }

}