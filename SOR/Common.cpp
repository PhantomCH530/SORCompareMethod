#include "stdafx.h"
#include <cstdio> 
#include <cstdlib> 
#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <math.h>
#include "test.h"

// Input function 
inline double f(int i,int j) 
{ 
	double x=xmin+i*dx,y=ymin+j*dy; 
	return abs(x)>0.5||abs(y)>0.5?0:1; 
} 

// Common output and error routine
void output_and_error(char* filename,double *a,const int sn) 
{ 
	// Computes the error if sn%error every==0 
	if(sn%error_every==0) 
	{
		double z,error=0;int ij; 
		for(int j=1;j<n-1;j++) 
		{ 
			for(int i=1;i<m-1;i++) {
			ij=i+m*j; 
			z=f(i,j)-a[ij]*(2*dxxinv+2*dyyinv) 
				+dxxinv*(a[ij-1]+a[ij+1]) 
				+dyyinv*(a[ij-m]+a[ij+m]); 
			error+=z*z;
		}
	}
	cout << sn << " " << error*dx*dy << endl;

	}
	// Saves the matrix if sn<=save iters 
	if(sn<=save_iters) { 
		int i,j,ij=0,ds=sizeof(float); 
		float x,y,data_float;
		const char *pfloat;
		pfloat=(const char*)&data_float;
		ofstream outfile; 
		static char fname[256]; 
		sprintf(fname,"%s.%d",filename,sn); 
		outfile.open(fname,fstream::out |fstream::trunc|fstream::binary); 

		data_float=m;outfile.write(pfloat,ds); 
		for(i=0;i<m;i++) 
		{ 
			x=xmin+i*dx; 
			data_float=x;
			outfile.write(pfloat,ds); 
		}
		for(j=0;j<n;j++) 
		{ 
			y=ymin+j*dy; 
			data_float=y; 
			outfile.write(pfloat,ds); 
			for(i=0;i<m;i++) 
			{ 
				data_float=a[ij++]; 
				outfile.write(pfloat,ds); 
			} 
		} 
		outfile.close();
	}
}
