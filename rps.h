#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <gsl/gsl_rng.h>

#define Nx 500   // tamanho da rede em x
#define Ny 500   // tamanho da rede em y
#define NG 10000 // n. de gerações
#define NS 3     // n. de espécies
// pm+pp+pr = 1.0
#define pm 0.80
#define pp 0.10
#define pr 0.10
