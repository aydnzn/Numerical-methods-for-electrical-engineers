#include <iostream>
#include <fstream>
#include <string>
#include <cmath> 
#include <stdio.h> 
#include <stdlib.h>     
using namespace std;

class MyMatrix {
	public :
		double *mat;
		int rownum,colnum;
		// default constructor
		MyMatrix(){
		mat=0; 
		rownum=colnum=0;
		}
		// Parameterized constructor
		MyMatrix(int mat_row, int mat_column)
		{
			rownum=mat_row;
			colnum=mat_column;
			int size= mat_row * mat_column;
			mat =new double[size];
			for(int i=0; i<size; i++)
			{
				mat[i]=0;
			}
		}
		// Copy constructor
		MyMatrix(const MyMatrix& X)
		{
			mat=0;
			rownum=X.GetRows();
			colnum=X.GetColumns();
		
			int size=X.GetRows() * X.GetColumns();
			if(size>0)
			{
				mat=new double[size];
				for(int i=0; i<size; i++)
				{
					mat[i]=X.mat[i];
				}
			}	
		}
		
			MyMatrix& operator=(const MyMatrix& X)
		{
			if(&X==this) return *this;
			
			delete[] mat;
			mat=0;
			int size=0;
			colnum = X.GetColumns();
			rownum =  X.GetRows();
			size=X.GetRows()*X.GetColumns();
			
			if(size>0)
			{
				mat=new double[size];
				for(int i=0; i<size; i++)
				{mat[i]=X.mat[i];}
			}
			else{cout<<"Error: Out of Range"<<endl; exit(1);}
			return *this;
		}
		
		// Destructor
		~MyMatrix(){delete[] mat;}
		
		int GetRows() const {
		return rownum;
		} // Return number of rows
		
		int GetColumns() const {
		return colnum;
		} // Return number of columns
		
		// Return position in array
		// [ 0,1,2,3;
		//   4,5,6,7
		//   8,9,10,11
		//   12,13,14,15] for a 4x4 matrix
		int Index(int m, int n) const 
		{
			if(m>0 && m<= rownum  && n>0 && n<= colnum) 
			{
				return (n-1)+(m-1)*colnum;
			}
			else {cout<<"Error: out of range"<<endl; exit(1);}
		}
		
	// calculate the number of rows in a text file.
	// the same algorithm as in the first project
		int number_of_rows(const char * filename){
			ifstream dummy (filename);
    string line;
    int n = 0;
    if(dummy.is_open()){
        while(!dummy.eof()){
            getline(dummy,line);
            n = n+1;
        }
    }
    else
        cout << "Can not open the file.";
    dummy.seekg(0,ios::beg);
    return n;
		}
		
// subtraction operator overloading
MyMatrix operator-(const MyMatrix &Xnew)
		{ 
		int row = Xnew.GetRows(); 
		int col = Xnew.GetColumns();
		
			if(rownum == row && colnum == col)
			{	  
				int size =row*col;
				MyMatrix Temp(row, col);
				for(int i=0; i<size; i++)
				{
					Temp.mat[i]=mat[i]-Xnew.mat[i];
				}
				return Temp;
			}
		else 
		{
			cout<<"matrices not the same size"<<endl;
			exit (1);
		}
		}
		
// Transpose 
		MyMatrix Transpose() const
		{
			MyMatrix Temp(colnum,rownum);
			for (int i=1; i<=Temp.GetRows();i++)
			{
				for(int j=1; j<=Temp.GetColumns();j++)
				{
					Temp.mat[Temp.Index(i,j)] = mat[Index(j,i)];
				}
			}
			return Temp;
		}
		
		// reading a matrix into a class matrix.
		MyMatrix Read(double *mat2) const
		{
			MyMatrix Temp(rownum,colnum);
			for(int i=1; i<=rownum;i++){
				for(int j=1; j<=colnum;j++){
					Temp.mat[Temp.Index(i,j)] = mat2[Index(i,j)];
					}
			}
			return Temp;
		}

	// Multiplication operator overloading
	MyMatrix operator*(const MyMatrix &x)
		{ 
			int a = rownum;
			int b =x.GetColumns(); 
			int c =x.GetRows();
				
				MyMatrix Temp1(a,b);
				
				for(int i=1;i<=a;i++) 
				{	for(int j=1; j<=b;j++)  
				{ for( int k=1; k<=c;k++) 
				{
				Temp1.mat[Temp1.Index(i,j)] =Temp1.mat[Temp1.Index(i,j)] + (*this).mat[Index(i,k)] * x.mat[x.Index(k,j)];
				}
				}
				}
				return Temp1;
			
		
		}
		
		
		
		//find the vector norm at infinity, vector norm at infinity is maximum of the absolute values of its components.
		double vect_norm_at_inf(MyMatrix Dum) const
{
			double res = 0;
				for (int i=1; i<=Dum.rownum;i++)
			{
				for(int j=1; j<=Dum.colnum;j++)
				{
					if(res < fabs(Dum.mat[Dum.Index(i,j)])){
						res = fabs(Dum.mat[Dum.Index(i,j)]);
					}
				}
			}			
			return res;
}
// dividies a matrix by scalar.
MyMatrix Division(MyMatrix Dum, double norm) 
{
	
	for(int i=1; i <= Dum.rownum; i++){
	
		for( int j=1; j <= Dum.colnum; j++)
		{
			Dum.mat[Dum.Index(i,j)] = 	Dum.mat[Dum.Index(i,j)] / norm;
		}
	}
	return Dum;
		
}
// multiplies a matrix by a scalar.
MyMatrix Mult(MyMatrix Dum, double norm) 
{
	
	for(int i=1; i <= Dum.rownum; i++){
	
		for( int j=1; j <= Dum.colnum; j++)
		{
			Dum.mat[Dum.Index(i,j)] = 	Dum.mat[Dum.Index(i,j)] * norm;
		}
	}
	return Dum;
		
}


double Determinant(MyMatrix Dum,double tolerance)
{	
	// first make Dum upper triangular.
	// The same algorithm in the project 1.
	// then find determinant.
	
	int column=1;
    // indicate the instantaneous column number
    int line =1;
    // indicate the instantaneous row number
    int max_index=0;
    int line_number = Dum.rownum;
   
   // create two arrays and use to store rows.
    double max_row[1][line_number];
    double current_row[1][line_number];
    
    // s is the number of row operations.
    int s=0;
    
    // indicate the instantaneous row number
  while (line <= line_number){
        // first I initialize the maximum value of the instantaneous column.
        // The initialization is always on the diagonal.
      
      double  max= Dum.mat[Dum.Index(line,line)]; 
        
        //rearrangement of the matrix
        for ( int i=line; i<=line_number; i++){
            // I am going to examine every column. I have to find the the row index with max value.          	
            // I search for the maximum value row by row in the beginning for 1st column.
            // I store the index in max_index
                 if (fabs(max) <= fabs( Dum.mat[Dum.Index(i,column)])) {
                
             		max = Dum.mat[Dum.Index(i,column)];
                	max_index=i;
            }
            else {
            }
        }
        
        if(max_index!= line){
        	s++;
        	// this s counts the number of row operations. 
		}
		
        // I found the index of row with max. value of n(here my n is column variable)th column.
        // Then I store the whole row with max. index in max_row row.
        for (int j=1; j<=line_number; j++){
        		max_row [0][j] = Dum.mat[Dum.Index(max_index,j)];
        }
       // store the instantaneous row in current_row row.
        for (int j=1; j<=line_number; j++){
     
        	current_row [0][j] = Dum.mat[Dum.Index(column,j)];
       
        }
        //I am going to replace current row with max row
        for (int j=1; j<=line_number; j++){
        	
       
			Dum.mat[Dum.Index(line,j)] = max_row [0][j];
        	Dum.mat[Dum.Index(max_index,j)] = current_row [0][j];        	
       
        }
        // Now I am done with the reordering of matrix.
	
   
		//This function makes zero all the values in n(here variable column)th column under n(here variable line)th line.
        Dum = Dum.elimination(Dum,line_number,line,column,max);
    

    line=line+1;
	// increase instantaneous row number by one
    column=column+1;
	// increase instantaneous column number by one
	max_index = line;
	// initialize the max_index.
	}
	
	// check if there is a value smaller than tolerance if so make it 0.
	for(int i=1;i<=Dum.rownum;i++){
		for(int j=1;j<=Dum.colnum;j++){
		if(fabs(Dum.mat[Dum.Index(i,j)])<tolerance){
				Dum.mat[Dum.Index(i,j)]= 0;
			}
		}
	}

// now I have a upper triangular matrix. The determinant of a upper triangular matrix is the multiplication of its diagonal elements.
// I should also consider the row operations I made. Each operation multiplies my determinant by -1.

	double mux = 1;
	for(int i=1;i<=Dum.colnum;i++){
	//	mux = mux * Dum.mat[Index1(i,i,Dum.colnum)];
	mux = mux * Dum.mat[Dum.Index(i,i)];
	}
	mux = mux * pow(-1,s);
	return mux;
	
}

MyMatrix Minor(MyMatrix Dum,int a,int b){
	
//ignore the values on row a  and column b.
//output is the remaining values. It is called Coft matrix. It's size is row number of Dum -1 * column number of Dum -1.
	
		int i,j;

	MyMatrix Coft(Dum.colnum-1,Dum.rownum-1);

	int row_new=0;
	int col_new=0;
	
	for(i=1; i <= Dum.colnum; i++) 
	{
		if(i == a)	
		continue;
			else{

			row_new = row_new + 1;	
			col_new=0;
	
			for(j=1; j <= Dum.rownum; j++)
			{	
				if(j == b)	{
				continue;
			}
			else{
				col_new = col_new +1;
	
			Coft.mat[Coft.Index(row_new,col_new)] = Dum.mat[Dum.Index(i,j)];
			}
		}
	}
}
	
	return Coft;
}

MyMatrix Cofactor(MyMatrix Dum2,double tolerance){
	
	// Temp is used to store matrix of minors.
	MyMatrix Temp(Dum2.rownum-1,Dum2.colnum-1);
	MyMatrix Out(Dum2.rownum,Dum2.colnum);

	for(int i=1;i<=Dum2.colnum;i++){
		for(int j=1;j<=Dum2.rownum;j++){
			//ignore the values on the current row i and column j.
			Temp=Temp.Minor(Dum2,i,j);
			//calculate the determinant of the remaining values
			// store the values in matrix Out.
			// det(Minor(i,j)) = Out(i,j);
		Out.mat[Out.Index(i,j)]=Temp.Determinant(Temp,tolerance);
		}
	}
	
	// Out is now Matrix of Minors.
	
	// create from matrix of minors the matrix of cofactors.
	for(int i=1;i<=Out.colnum;i++){
		for(int j=1; j<= Out.colnum;j++){
			if((i+j)%2 == 1){
			Out.mat[Out.Index(i,j)] = - Out.mat[Out.Index(i,j)];
			}
		}
	}
	
	// Transpose to make the Adjugate
	Out =  Out.Transpose();
		
	return Out;
	
}

// elimination function used to find upper triangular function in order to calculate determinant.
MyMatrix elimination(MyMatrix Dum,int line_number,int line, int column, int max){

	double k=0;
	MyMatrix Temp(line_number,line_number);
	Temp = Dum ;
	// k is the coefficient used for making the element of matrix 0 which is below the pivot.
    for (int i=line+1; i<=line_number; i++){
        // start with the next row. Check until the last row.
        // in the beginning my cursor is at matrix [0][0]. I want to make matrix [1][0] , matrix [2]
        //[0],matrix[3][0].....matrix[size][0] =0
        // this is the algorithm I used.
        //check every line and make the corresponding value zero.
		 if ( Temp.mat[Temp.Index(i,column)] != 0 ){        	
              k = Temp.mat[Temp.Index(i,column)] / Temp.mat[Temp.Index(column,column)];
            for (int j=1; j<=line_number; j++){
                if (k<0){
                	Temp.mat[Temp.Index(i,j)] = (Temp.mat[Temp.Index(i,j)] - (k*Temp.mat[Temp.Index(line,j)]));
                }
                else{
                	Temp.mat[Temp.Index(i,j)] = Temp.mat[Temp.Index(i,j)] - (k*Temp.mat[Temp.Index(line,j)]);
                }
            }
        }
        
    }
    
    return Temp;

}
// makes matrix Dum a identity Matrix.
MyMatrix Identity(MyMatrix Dum){
	for(int i=1; i <= Dum.rownum; i++){

		for(int j=1; j <= Dum.colnum; j++){
		
		if(i==j){
	Dum.mat[Dum.Index(i,j)]=1;
		}
		else
		Dum.mat[Dum.Index(i,j)]=0;
}
}

return Dum;
}

 //ignore the 1st row and 1st column to get matrix Temp(Dum.rownum-1)(Dum.colnum-1) 
MyMatrix TakeMatrixB(MyMatrix Dum){
	
	MyMatrix Temp(Dum.rownum-1,Dum.rownum-1);
		for(int i=1; i < Dum.rownum; i++)
		for(int j=1; j < Dum.colnum; j++)
		Temp.mat[Temp.Index(i,j)] = Dum.mat[Dum.Index(i+1,j+1)];
			
			return Temp;
}
}Eig1;



void eigvalvect(int num, float tolerance, MyMatrix S) // apply normalized power iteration method 
{
	
	int m = S.rownum;
	// create two zero vectors having dimension mx1.
	// m is row number of input matrix.
	MyMatrix Mat_new(m,1);
	MyMatrix Mat_bef(m,1);
	
// this for loop cretaes the starting vector for power iteration. Mat_bef = [1 0 0 0 ....]
	for(int i=0;i<m;i++)
		{
		if(i == 0)		
			Mat_bef.mat[i]=1;
		else
			Mat_bef.mat[i]=0;

	}
	
	// find vector norm at infinity.
	double old = Mat_bef.vect_norm_at_inf(Mat_bef);
	double norm= 0;
	
	while(1)
	{
		MyMatrix tmp(m,1);
		// generate next vector
		tmp = S * Mat_bef;
	// generate norm at infinity of next vector
	norm = tmp.vect_norm_at_inf(tmp);
	// normalize it
		Mat_new = tmp.Division(tmp, norm);
	// if the difference between the old and new vector norm is smaller than tolerance, break the loop
	// if it is bigger than the tolerance , store Mat_new into Mat_bef, store the new norm into old norm, and generate next vector until you reach the vector norm difference smaller than tolerance
		if(fabs(old - norm) < tolerance)
			break;
		Mat_bef = Mat_new;
		
		old = norm;
	}
	
	// Mat_new is my eigenvector and I use it in next steps. So store it in a new matrix called Eig1.
	// norm is my eigenvalue
	Eig1 = Mat_new; 
	// write the eigenvalue
	printf("Eigenvalue#%d: %.2lf\n",num,norm);
	
	// if num=1 so if it is the first eigenvalue print corresponding eigenvector.
	if(num-1 ==0)
		for(int i=0; i < Mat_new.rownum; i++)
			printf("%.2lf\n",Mat_new.mat[i]);	
}


int main(int argc, char* argv[]){
	
	// get command-line arguments for the parameters
	//  A.txt 0.000001 B.txt are my parameters.
char* a_mat = argv[1];
float tolerance = atof(argv[2]);
char* out_mat = argv[3];

    //open the txt file
    ifstream file_a (a_mat);

    //check the txt file whether it is opened or not.
    if(!file_a.is_open()){
        cout << "File not opened..." << endl;
        return 1;
    }

    //  Create an empty file for output operations. If a file with the same name already exists, its contents are discarded and the file is treated as a new empty file.
    freopen( out_mat, "w+", stdout);
    
    
    // define a matrix class
    MyMatrix D;
    // get the row number of the input matrix
    int line_number = D.number_of_rows(a_mat); 
    // create an array 
    double * matrix2 = new double[line_number*line_number];
    // store the input matrix in matrix2 array
     for (int i=0; i<line_number*line_number; i++){
        
            file_a >> matrix2[i];
    
    }
    
    // define the size of matrix. It's a square matrix.
    const int m(line_number),n(line_number);
	// define a new matrix called NewD with its dimension m,n.
	MyMatrix NewD(m,n); 
	// store matrix2 in my matrix NewD which is a element of class MyMatrix.
	NewD = NewD.Read(matrix2);
	
	delete [] matrix2;
	 	
	
	// this function finds the dominant eigenvalue and corresponding eigenvector.
    eigvalvect(1,tolerance,NewD);
	//  I print the dominant eigenvalue and corresponding eigenvector. Next step is deflation.
//cout << endl << "V" << endl << V <<endl;



// H * Eig1 = a * e1 
// H * NewD * H^-1 = [ eigenvalue1 b^T ; 0 B];
// The dominant eigenvalue of B is my next (second) eigenvalue of NewD.
// so find H.
// How?
// H = I - 2 * v * vT / (vT * v );
// v = Eig1 - alfa*e1;


// v = Eig1 - alfa*e1; this algorithm finds vector v.
// alfa is vector norm of Eig1 at 2.
double alfa = 0;
for(int i=0; i < Eig1.rownum; i++){
	alfa = alfa + Eig1.mat[i]*Eig1.mat[i];
}
alfa = sqrt(alfa);

if(Eig1.mat[0]>0){
	Eig1.mat[0] = Eig1.mat[0] + alfa ;
}
else
{
	Eig1.mat[0] = Eig1.mat[0] - alfa ;
}


// Eig 1 is now vector V.
 MyMatrix V = Eig1;
 


// next step is to find Matrix H.
MyMatrix H(m,n);

// this creates a square identity matrix for formula.
// H = I - 2 * v * vT / (vT * v );
H = H.Identity(H);


// 2/ (vt * v) is a number. vT is 1xm. v is mx1. vTv is 1x1.
	double vtv = 0;
		for(int i=0; i < V.rownum; i++){
		vtv = vtv + V.mat[i] * V.mat[i];
	}
		double two_over_vtv = 2 / vtv;
// two_over_vtv is my coefficient for vector v*vT.
		
// V is now v* vT.
V = V * V.Transpose();

// V is now  2 * v * vT / (vT * v ).
V = V.Mult(V,two_over_vtv);

// H is now  I - 2 * v * vT / (vT * v );
H = H-V;
// H matrix is done.
// my next step is to find H * NewD * H^-1


	
	MyMatrix	R = H * NewD;

// find determinant of H.
double x =  H.Determinant(H,tolerance);


// find H^-1.
//The first step is to create a "Matrix of Minors"
// This is inside Cofactor function.
// then find matrix of cofactors.
// This is also inside Cofactor function.
//Now "Transpose" all elements of matrix of cofactors.
// This is also inside Cofactor function.
// The output of Cofactor function is Transpose of matrix of cofactors.
// Multiply the output of cofactor function by determinant of H.
// The output 'Inverse' is the inverse of H.

	MyMatrix Inverse = H.Division(H.Cofactor(H,tolerance),x);
	
	// HaHinv is H*NewD*H^-1.
	MyMatrix HaHinv = R * Inverse ;
	
	
	// H * NewD * H^-1 = [ eigenvalue1 b^T ; 0 B];
// The dominant eigenvalue of B is my next (second) eigenvalue of NewD.
// we can work with B to find second eigenvalue.
// take B out of HaHinv.
	MyMatrix B =  B.TakeMatrixB(HaHinv);
	
// 2 is because of it's my second eigenvalue. The same algorithm ! Find the dominant eigenvalue of matrix B.
	eigvalvect(2,tolerance,B);
	
	
	return 0;
	
	
	

}
// AYDIN UZUN
// 2015401210
// 30.04.2017


