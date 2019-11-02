// Load common routines and constants

#include "stdafx.h"
#include <cstdio> 
#include <cstdlib> 
#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <math.h>
#include "test.h"
// Common output and error routine

void Gauss() 
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

void Jacobi() 
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

int main() 
{ 
	int i,j,ij,k; 
	double error,u[m*n],z; 
	// Set initial guess to be identically zero 
	for(ij=0;ij<m*n;ij++) u[ij]=0; 
	output_and_error("sor_out",u,0);
	// Compute SOR Red−Black iterations
	for(k=1;k<=total_iters;k++) { 
		for(j=1;j<n-1;j++) { 
			for(i=1+(j&1);i<m-1;i+=2) { 
				ij=i+m*j;
				u[ij]=u[ij]*(1-omega)+omega*(f(i,j) 
					+dxxinv*(u[ij-1]+u[ij+1]) 
					+dyyinv*(u[ij-m]+u[ij+m]))*dcent;
		}
	}
	for(j=1;j<n-1;j++) {
		for(i=2-(j&1);i<m-1;i+=2) {
			ij=i+m*j; u[ij]=u[ij]*(1-omega)
				+omega*(f(i,j) 
				+dxxinv*(u[ij-1]+u[ij+1])
				+dyyinv*(u[ij-m]+u[ij+m]))*dcent;
		}
	}
	// Save the result and compute error if necessary 
	output_and_error("sor_out",u,k);
	}
	Gauss();
	Jacobi();
}


