#include <iostream>
#include <fstream>
#include <string>
#include <cmath> 
#include <stdio.h> 
#include <stdlib.h>     
#include <string>
using namespace std;
// default size of our dynamic coefficient array
const size_t DEFAULTPOLY = 50;    
class Poly
{
private:
  // Data members 
 int size;
double *coeff;     // dynamic array
public:

  // Default Class constructor
  // Allocate an array of DEFAULTPOLY elements and initializes it to the constant 0.
  Poly (){
  			coeff =new double[DEFAULTPOLY];
			for(int i=0; i<DEFAULTPOLY; i++)
			{
				coeff[i]=0;
			}
  };

  // Non-default Class constructor
  // Allocate an array of 'size' elements and initializes it to the constant 0.
  Poly (int size2){
  	size = size2;
  	coeff = new double[size2];
  			for(int i=0; i<size2; i++)
			{
				coeff[i]=0;
			}
  	
  };

  // Copy constructor
  // Construct a new Poly that is a copy of an existing Poly.
  Poly (const Poly& aPoly){
			int size2 = aPoly.GetSize();
			if(size2>0)
			{
				coeff=new double[size2];
				for(int i=0; i<size2; i++)
				{
					coeff[i]=aPoly.coeff[i];
				}
			}	
  };

  // Destructor
  // Destroy a poly object by freeing the dynamically allocated array
  ~Poly (){
  	delete[] coeff;
  };

  // Assignment operator
  // Assign rhs Poly object to 'this' Poly object
  const Poly& operator= (const Poly& rhs){
  	if (&rhs == this) return *this;
  	
  	delete [] coeff;
  	int size3 = rhs.GetSize();
  	if(size3>0){
  		coeff = new double[size3];
  		for(int i=0;i<size3;i++){
  			coeff[i] = rhs.coeff[i];
		  }
	  }
	  else{cout<<"Error: Out of Range"<<endl; exit(1);}
			return *this;
  };

// function returning the "size" of array
int GetSize() const{
	return size;
}

// coefft array's "index"'th element is set to double "value" 
void setCoeff (double value, int index){
	coeff[index] =  value;
};

// evaluate function with value x 
// so return f(x)
  double evaluate (double x) const{
  	
double mux = 1;
double son;
double res = 0;
  
  for(int i=0; i<size; i++){
  	for(int j=0 ; j<i ; j++){
  		mux = x*mux ;
	  }
	  son = coeff[size-i-1] * mux ;
	  res = res + son;
	  mux = 1;
  }
  return res;
  };


// takes coefficient vector as input and assign them to coeff vector.
	void setall (double length, double *vector){
		
		for(int i = 0; i< length; i++){
		    	 (*this).setCoeff(vector[i],i);
		}
	}
	
// bisection method
// iter is number of iterations.
// algorithm is given in book.	
	double bisection ( double tol, double *tahm){
		double a = tahm[0] ;
		double b = tahm[1];
		int iter = 0;
		while(1){
		if((b-a) > tol){
			double m = a + (b-a)/2;
			iter = iter +1;
			if((*this).evaluate(a) * (*this).evaluate(m) > 0){
				a = m;
			}
				else
				b = m;
		}
		else if((b-a) < tol){
			cout << "number of iteration of bisection method : "<< iter<< endl;
			return a ; 
			break;
		}
	}
	}
	
	
// secant method
// iter is number of iterations.
// algorithm is given in book.
	double secant (double tol, double *tahm){
		double a = tahm[0] ;
		double b = tahm[1];
		double xk1;
		int iter = 0;
		
		while(1){
				if(abs((*this).evaluate(b))> tol){
					xk1 = b - ((*this).evaluate(b)*(b-a))/ ((*this).evaluate(b) - (*this).evaluate(a));
					a = b;
					iter = iter +1;
					b = xk1;
				}
				else if(abs((*this).evaluate(b)) < tol){
					cout << "number of iteration of secant method : " << iter << endl;
					return b;
					break;
				}
		}
	}
	
// hybrid method where I start with bisection method for the first two iterations and 
// then continue with secant method for the rest of the iterations	
	double hybrid (double tol, double *tahm){
		double a = tahm[0] ;
		double b = tahm[1];
		int iter = 0;
		double xk1;
		int i = 2;

		while(i>0){
				if((b-a) > tol){
				double m = a + (b-a)/2;
	
			if((*this).evaluate(a) * (*this).evaluate(m) > 0){
				a = m;
			}
				else{
				b = m;	
			}
		}
			else if((b-a) < tol){
			return a ; 
			break;	
		}		
			i--;
		}
			while(1){
				if(abs((*this).evaluate(b)) > tol){
					xk1 = b - ((*this).evaluate(b)*(b-a))/ ((*this).evaluate(b) - (*this).evaluate(a));
					a = b;
					b = xk1;
					iter = iter +1;
				}
				else if(abs((*this).evaluate(b)) < tol){
					cout << "number of iteration of hybrid method : "  << iter+2  <<endl;
					return b;
					break;
				}
		}
	}
};

int main(int argc, char* argv[]){
	// create a double array in order store parameters
double * matrix = new double[100];

// sizeof returns the size of the array argv 
int size = sizeof(argv) +1;

// get the values from parameters into matrix
for(int i = 1; i<=sizeof(argv);i++){
	matrix[i-1] = atof(argv[i]);
	}

// cofactors and initial guesses arrays
double *cofactors = new double[size-4];
double *tahmin = new double[2];

// load the arrays
for(int j=0; j< size-4 ; j++){
	cofactors[j] = matrix[j];
}
for(int j= 0 ;j<2 ; j++){
	tahmin[j] = matrix[size-4+j];
}

double tolerance = matrix [size-2];

Poly MyMat(size-4);
// set the coefficients
MyMat.setall(size-4,cofactors);
// use 3 different algorithms
cout << "the result from bisection method : "<< MyMat.bisection(tolerance,tahmin) << endl;
cout << "the result from secant method : " <<MyMat.secant(tolerance,tahmin) << endl;
cout << "the result from hybrid method : "<< MyMat.hybrid(tolerance,tahmin) << endl;

// delete dynamical allocated arrays
	delete [] matrix;
	delete [] cofactors;
	delete [] tahmin;
return 0;
}

// AYDIN UZUN
// 2015401210
