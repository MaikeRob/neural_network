#include "../headers/inicialization.h"
#include "activation.h"

double he(model_t *model){
    
}

double xavier(model_t *model){

}

double inicializate(model_t *model, const char *activation){
    if(strcmp(activation, RELU) == 0){
        return he(model);
    } else {
        return xavier(model);
    }
}