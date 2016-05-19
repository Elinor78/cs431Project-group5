#include <omp.h>
#include <stdio.h>

static long num_steps=100000;
double num_step;
int main(){

	int i; double x, pi, sum =0;
	step =1/(double)num_steps;
	#pragma omp parallel{
	double x;

	#pragma omp parallel for reduction(+:sum)
	

		for(i=0; i<num_steps; i++){
			x= (i+0.5)*step;
			sum= sum+4/(1+x*x);
		}
	}
	pi = step*sum;
}