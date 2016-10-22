#include "../include/mlp.h"
#include "../include/openMatrixFile.h"


Neuron *initNeuronRandom(int links, double a){
  Neuron *new;
  int i;

  new = malloc(sizeof(Neuron));
  new->num_weigths = links;
  new->activation = a;
  new->error = 0.0;
  if(links != 0){
    new->weights =  malloc(sizeof(double) * links);
  }
  else
  {
        new->weights = NULL;
  }


  for(i = 0; i < links; i++){
    new->weights[i] = (double)(rand() % 200 - 100) / 100;
  }

  return new;
}

Layer *initLayerRandom(int s, int links_neurons){
  Layer *new;
  int i;

  new = malloc(sizeof(Layer));
  new->size = s;
  new->links =links_neurons;
  new->bias = initNeuronRandom(links_neurons, 1.0);
  new->neurons =  malloc(sizeof(Neuron)*s);

  for(i = 0; i < s;i++){
    new->neurons[i] = initNeuronRandom(links_neurons,0);
  }
  return new;

}

MLP *initMLP(int in, int out, int hidden, int n_hiddens){

	MLP		*mlp;
	int		i;

	mlp = malloc(sizeof(MLP));
  mlp->size_in = in;
  mlp->size_out = out;
  mlp->size_hidden = hidden;
  mlp->num_hiddens = n_hiddens;

  mlp->input_layer = initLayerRandom(in, hidden);
  mlp->output_layer = initLayerRandom(out,0);

  mlp->hidden_layers = malloc(sizeof(Layer)*n_hiddens);
  for(i = 0; i < n_hiddens;i++)
    mlp->hidden_layers[i] = initLayerRandom(hidden,(i == n_hiddens-1?out:hidden));

  return mlp;

}

void freeNeuron(Neuron *n){
  free(n->weights);
  free(n);

}

void freeLayer(Layer *l){
  int i;
  freeNeuron(l->bias);
  for (i = 0; i < l->size; i++)
		freeNeuron(l->neurons[i]);
	free(l->neurons);
}

void freeMLP(MLP *mlp){
  int i;

  freeLayer(mlp->input_layer);
  freeLayer(mlp->output_layer);

  for(i = 0; i < mlp->num_hiddens;i++)
    freeLayer(mlp->hidden_layers[i]);

  free(mlp);
}

void setErrorNeuron(double value, Neuron *n){
  n->error = value;
}
void setActivationNeuron(double value, Neuron *n){
  n->activation = value;
}

void setWeigthsNeuron(double *values, Neuron *n){
  int i;
  for(i = 0;i < n->num_weigths;i++)
    n->weights[i] = values[i];

}

void printNeuron(Neuron *n){
  printf("%2.3f\n\n",n->activation);
}


void printNeuronWeights(Neuron *n){
  int i;
  printf("-----------------------\n");
  for(i = 0;i < n->num_weigths;i++)
    printf("%2.3f ",n->weights[i]);

  printf("\n-----------------------\n");

}

void setLayer(Layer *l, double *values){
  int i;
  for(i = 0; i < l->size;i++){
     setActivationNeuron(values[i],l->neurons[i]);
  }

}

void printLayer(Layer *l){
  int i;
  printf("----------------------------\n");
  printf("bias ");
  printNeuron(l->bias);
  for(i = 0;i < l->size;i++)
    printNeuron(l->neurons[i]);
  printf("----------------------------\n");
}


void printLayerWeights(Layer *l){
  int i;
  printf("\n--------------Bias---------\n");
  printNeuronWeights(l->bias);
  for(i = 0;i < l->size;i++)
    printNeuronWeights(l->neurons[i]);
  printf("\n--------------End---------\n");
}

void printValuesMLP(MLP *mlp){
  int i;
  printf("\n--------InputLayer---------\n");
  printLayer(mlp->input_layer);

  printf("\n------HiddenLayers---------\n");
  for(i = 0; i < mlp->num_hiddens; i++)
    printLayer(mlp->hidden_layers[i]);

  printf("\n------OutputLayer---------\n");
    printLayer(mlp->output_layer);
  printf("\n---------End---------------\n");
}

main() {
  int i;

  double **mat = createMatrix(NUM_ROWS, NUM_COLUMNS);
  MLP *mlp = initMLP(SIZE_INPUT, SIZE_OUTPUT, SIZE_HIDDEN, NUM_HIDDENS);


  readFileMatrix(mat, NUM_ROWS, NUM_COLUMNS);
  setLayer(mlp->input_layer,mat[0]);

  printValuesMLP(mlp);
  //printMatrix(mat, NUM_ROWS, NUM_COLUMNS);

  freeMatrix(mat, NUM_ROWS);
  freeMLP(mlp);


  return 0;
}
