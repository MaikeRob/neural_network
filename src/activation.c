#include "../headers/activation.h"
#include "../headers/neural_network.h"
#include <math.h>
#include <string.h>

double relu(double x) {
    if(x > 0) return x;    
    return 0;
}

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double tanh(double x) {
    return (exp(2 * x) - 1) / (exp(2 * x) + 1);
}

double (*get_activation_function(const char *activation))(double) {
    if(strcmp(activation, RELU) == 0){
        return &relu;
    } else if(strcmp(activation, SIGMOID) == 0){
        return &sigmoid;
    } else if(strcmp(activation, TANH) == 0){
        return &tanh;
    } else {
        return NULL;
    }
}