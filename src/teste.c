#include "../include/includeAll.h"
#include <math.h>
double tes(){
   return 1/(1+exp(-1));
}

main() {
  double z = tes();
  printf("%f\n",z);
  return 0;
}
