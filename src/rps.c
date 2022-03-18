#include "../rps.h"

void ic(const gsl_rng *, int *);
void op(int , int *);

int main(int argc, char **argv){
	int i, j, t, n, nb, gd, ac, ps, temp;
	// n= numerar arquivo;
	//nb= vizinho;
	//gd= grid= rede;
	//ac= ativo;
	//ps= passivo;
	//temp= temporário; 
	int *phi;
	double at; //at= ação;

	phi= (int *) calloc(Nx*Ny, sizeof(int));

	gsl_rng_default_seed= (argc == 2) ? atoi(argv[1]) : time(NULL);
	gsl_rng *w= gsl_rng_alloc(gsl_rng_taus);

	n= 0;
	ic(w, phi);
	op(n++, phi);

	for(t= 1; t<= NG; t++){
		gd= 0;
		while(gd < Nx*Ny){
			i= gsl_rng_uniform(w)*Nx; //sorteia um ponto x da rede
			j= gsl_rng_uniform(w)*Ny;
			ac= j*Nx+i; //é a posição no vetor;
			if(phi[ac] != 0){
				nb= gsl_rng_uniform(w)*4;
				switch(nb){
					case 0:
						ps= ((j+1)%Ny)*Nx+i;
					break;
					case 1:
						ps= ((j-1+Ny)%Ny)*Nx+i;
					break;
					case 2:
						ps= j*Nx+(i+1)%Nx;
					break;
					default:
						ps= j*Nx+(i-1+Nx)%Nx;
				}
				at= gsl_rng_uniform(w);
				if(at < pm){
					temp= phi[ac];
					phi[ac]= phi[ps]; //mobilidade
					phi[ps]= temp;
					gd++;
				}else{
					if(at > pm && at < (pm+pp)){
						if((phi[ac]%NS) == (phi[ps]-1)){ //seleção
							phi[ps]= 0;
							gd++;
						}
					}else{
						if(phi[ps] == 0){
							phi[ps]= phi[ac]; //reprodução
							gd++;
						}
					}
				}
			}
		}
		if(t % 20 == 0){
			op(n++, phi);
		}
	}

	free(phi);
	gsl_rng_free(w);
	return 0;
}
