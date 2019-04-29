
#include "clib.h"


#define fo_lp_a 0.9950f //fc=20 for 25e3
#define fo_lp_b 0.0025f //fs/2=>fc/2

#define Kp 100.0f
#define _2pi 6.283185307179586476925286766559f
#define wt (_2pi*50.0f)


void PLL_initialization(pll_parameters* pll, float ts){

	pll=0;
	pll->input.ts=ts;

}


float PLL_theta (float Vpll, float theta,pll_parameters* pll){

	float Vd_pll=0.0f;

	Vd_pll= Vpll*cosf(theta);

	pll->Vdf=pll->Vdf*(fo_lp_a)+(Vd_pll + pll->Vd)*fo_lp_b;
	pll->Vd=Vd_pll;

	pll->Iout+=pll->input.ts*((pll->Vdf * Kp)+wt);//only Kp

	if(pll->Iout>_2pi){pll->Iout = _2pi;}
	if(pll->Iout<0.0f){pll->Iout = 0.0f;}

	return pll->Iout;

}


