#include "stdafx.h"
#include <cstdio> 
#include <cstdlib> 
#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <math.h>


#define TEST_H
using namespace std;
// Set grid size and number of iterations 
const int save_iters=20;
const int total_iters=200; 
const int error_every=2; 
const int m=33,n=33; 
const double xmin= -1, xmax= 1; 
const double ymin= -1, ymax=1; 

// Compute useful constants
const double pi=3.1415926535897932384626433832795; 
const double omega=2/(1+sin(2*pi/n)); 
const double dx=(xmax-xmin)/(m-1); 
const double dy=(ymax-ymin)/(n-1); 
const double dxxinv=1/(dx*dx); 
const double dyyinv=1/(dy*dy); 
const double dcent=1/(2*(dxxinv+dyyinv)); 


// Input function 
inline double f(int i,int j);
// Common output and error routine
extern void output_and_error(char* filename,double *a,const int sn);
