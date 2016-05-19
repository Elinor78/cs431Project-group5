#include <stdio.h>
#include <omp.h>

	static long num_steps=100000;
	double step;
	#define NUM_THREAD 2
	#define PAD 8 //eliminate false sharing by padding the sum array
void main()
{
	int i, nthreads;
	double pi, sum[NUM_THREAD][PAD];
	step =1.0/(double)num_steps;
	omp_set_num_threads(NUM_THREAD);
	#pragma omp parallel
	{
	int i, id, nthrds;
	double x;
	id = omp_get_thread_num();
	nthrds=omp_get_num_threads();
	if(id==0) nthreads= nthrds;

	for(i=id,sum[id]=0.0; i<num_steps; i=i+nthrds){
		x=(i+0.5)*step;
		sum[id][0] +=4.0/(1.0+x*x);
	}
}
for(i=0, pi=0.0; i<nthreads; i++)
pi += step*sum[i][0];

}