#ifndef ACTIVATION_H
#define ACTIVATION_H

#define RELU "relu"
#define SIGMOID "sigmoid"
#define TANH "tanh"

double relu(double x); //TODO

double sigmoid(double x); //TODO

double tanh(double x); //TODO

double (*get_activation_function(const char *activation))(double); //TODO

#endif