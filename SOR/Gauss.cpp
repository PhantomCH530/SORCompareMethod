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
	double error,u[m*n],z;
	// Set initial guess to be identically zero 
	for(ij=0;ij<m*n;ij++) u[ij]=0; 
	output_and_error("gsrb_out",u,0);
// Compute Red−Black Gauss−Seidel iteration 
	for(k=1;k<=total_iters;k++) 
	{ 
		for(j=1;j<n-1;j++) 
		{ 
			for(i=1+(j&1);i<m-1;i+=2) 
			{
				ij=i+m*j; 
				u[ij]=(f(i,j)
					+dxxinv*(u[ij-1]+u[ij+1]) 
					+dyyinv*(u[ij-m]+u[ij+m]))*dcent;
			}
		}
	for(j=1;j<n-1;j++) 
	{ 
		for(i=2-(j&1);i<m-1;i+=2) 
		{ 
			ij=i+m*j; 
			u[ij]=(f(i,j)
				+dxxinv*(u[ij-1]+u[ij+1]) 
				+dyyinv*(u[ij-m]+u[ij+m]))*dcent; 
		} 
	} 
	// Save the result and compute error if necessary 
	output_and_error("gsrb_out",u,k);
}
}

