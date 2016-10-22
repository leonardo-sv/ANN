#ifndef MLP_H
# define MLP_H

#include "includeAll.h"

#define NUM_HIDDENS 1
#define SIZE_INPUT 13
#define SIZE_OUTPUT 1
#define SIZE_HIDDEN 20


typedef struct structNeuron {
  int num_weigths;
  double activation;
  double error;
  double *weights;

} Neuron;

typedef struct structLayer{
  int size;
  int links;
  Neuron *bias;
  Neuron **neurons;
} Layer;

typedef struct structMLP{
  int size_hidden;
  int size_out;
  int size_in;
  int num_hiddens;
  Layer *input_layer;
  Layer *output_layer;
  Layer **hidden_layers;

} MLP;



Neuron *initNeuronRandom(int num_links, double a);
void freeNeuron(Neuron *n);
void printNeuron(Neuron *n);
void printNeuronWeights(Neuron *n);

Layer *initLayerRandom(int size, int links_neurons);
void freeLayer(Layer *l);
void printLayer(Layer *l);
void printLayerWeights(Layer *l);

MLP *initMLP(int in, int out, int hidden, int n_hiddens);
void freeMLP(MLP *mlp);



#endif
