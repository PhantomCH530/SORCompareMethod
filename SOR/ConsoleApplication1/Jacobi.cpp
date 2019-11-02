#include "stdafx.h"
#include <cstdio> 
#include <cstdlib> 
#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <math.h>
#include "test.h"
int main() 
{ 
	int i,j,ij,k; 
	double error,u[m*n],v[m*n],z; 
	double *a,*b; 
	// Set initial guess to be identically zero 
	for(ij=0;ij<m*n;ij++) u[ij]=v[ij]=0; 
	output_and_error("jacobi_out",u,0);
	// Carry out Jacobi iterations 
	for(k=1;k<=total_iters;k++) 
	{ 
		// Alternately flip input and output matrices 
		if (k%2==0) 
		{
			a=u;b=v;
		} 
		else 
		{
			a=v;
			b=u;
		} 
		// Compute Jacobi iteration 
		for(j=1;j<n-1;j++) 
		{ 
			for(i=1;i<m-1;i++) 
			{ ij=i+m*j; a[ij]=(f(i,j)
			+dxxinv*(b[ij-1]+b[ij+1]) 
			+dyyinv*(b[ij-m]+b[ij+m]))*dcent; 
			} 
		} 
		// Save and compute error if necessary 
		output_and_error("jacobi_out",a,k); }
}