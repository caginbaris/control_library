#ifndef __phaseLockedLoop_h
#define __phaseLockedLoop_h


typedef struct pll_parameters{

		float Vd;
		float Vdf;
		float Iout;
	
	struct {
		
		float ts;	
		
	}input;	

}pll_parameters;

void PLL_initialization(pll_parameters* pll, float ts);

#define PLL_THETA(Vpll,theta,pll) theta=PLL_theta (Vpll,theta,pll_parameters* pll)

#endif


