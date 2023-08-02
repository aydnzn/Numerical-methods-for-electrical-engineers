#include <iostream>
#include <fstream>
#include <string>
#include <cmath> 
// abs() Compute absolute value (function ) in cmath library
using namespace std;
// function calculating the row number of input matrix, in our case A matrix and B matrix
// this is the algorithm we used in class
int number_of_rows(const char * filename) {
    ifstream dummy (filename);
    //Constructs an ifstream object that is not associated with any file.
    string line;
    
    int n = 0;

    // n is my row number and initialized 0 in the beginning
    // check in the beginning if the file is open or not
    if(dummy.is_open()){
        while(!dummy.eof()){
            getline(dummy,line);
            //Extracts characters stores them into str(here string "line") until the delimitation
            //character delim is found (or the newline character, '\n').
            n = n+1;
            // increase the row number by 1 when the newline character '\n' is reached.
        }
        // get out of while loop when you reach end of file
    }
    else
        cout << "Can not open the file.";
        
    dummy.seekg(0,ios::beg);
    // move the position to the beginning.
    return n;
}
// inverse function is going to be used for calculating the inverse matrix of 2x2 matrices.
// we need A^-1 in order to calculate the condition numbers
void inverse(float *matrix[]){
	
    float det ;
    det= ( (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    float dummy1 =  matrix[0][0];
    
    matrix[0][0]=matrix[1][1];
    matrix[1][1]=dummy1;
    matrix[0][1]=-matrix[0][1];
    matrix[1][0]=-matrix[1][0];
    
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            matrix [i][j]= matrix[i][j]/det;
        }
    }
}

// printing function
void print(float *matrix[], int size){

    for (int i=0; i<size; i++){
        for (int j=0; j<size+1; j++){
        	// I mostly print my cascade_matrix which is A together b. Therefore it is size+1.
            cout << matrix[i][j] << " , ";;
        }
        cout << endl;
    }
}

// This function does the elimination.
// It takes float matrix array, instantanous line, instantanous column, row_length and the maximum value of
//instantanous column
void elimination(float *matrix[],int line_number, int line, int column, float max){
    
	float k=0;
	// k is the coefficient used for making the element of matrix 0 which is below the pivot.
    for (int i=line+1; i<line_number; i++){
        // start with the next row. Check until the last row.
        // in the beginning my cursor is at matrix [0][0]. I want to make matrix [1][0] , matrix [2]
        //[0],matrix[3][0].....matrix[size][0] =0
        // this is the algorithm I used.
        //check every line and make the corresponding value zero.
        if (matrix[i][column] != 0){
        	
            k = (matrix[column][column]/matrix[i][column]);
            for (int j=0; j<=line_number+1; j++){
                if (k<0){
                    matrix[i][j]= (-1*matrix[line][j]+ (k* matrix[i][j]));
                }
                else{
                    matrix[i][j]= (matrix[line][j]- (k* matrix[i][j]));
                }
            }
        }
        
    // this function prints my cascade_matrix. This is just for checking.
	// Step by step seeing the cascade matrice should be useful for understanding the algorithm.
	// if you want to see how my matrices look like you can get rid of the slashes.
	// But it's up to you.
    // cout << "\n" ;
    // print(matrix,line_number);
    // cout << "\n" << "\n";
        
        
    }

    // let's make the max value 1.
    // this is going to be helpful when calculating the solution matrix.
    // now my matrix is of the form
    // A = [1 x x x x .....]
    //     [0 x x x x .....]
    //     [0 x x x x .... ]
    //     [0..............]
    // this is just the beginning.
    // after finishing my main while loop
    // my matrix is going to be look like this
    // A = [1 x x x x .....]
    //     [0 1 x x x .....]
    //     [0 0 1 x x .... ]
    //     [0 0 0 1 x......]
    //     [...............]
    if(max!=0){
    for (int j=0; j<line_number+1; j++){
        matrix[column][j]=matrix[column][j]/max;
    }
    }
}

void backward_elimination_and_output(float *matrix[], int line_number){
    float dummy=0;
    // create a solution row matrix called solmat.
    float solmat[line_number];
    //first member of this array is my Xn. It is the last row of my solution matrix.
    solmat[0]=matrix[line_number-1][line_number];
    // create output .txt file
    ofstream output ("output.txt");
    // this algorithm calculates the other rows of solution matrix. It stores the solution in mat.
    // I know already the Xn.And I know already the coefficients. So I can calculate X(n-1) and so on
    //until X(0). my X(n) is mat(0). So I should print and store the solmat backward.
    for(int i=1; i<line_number; i++){
        for(int j=1;j<i+1;j++){
            dummy=dummy+matrix[line_number-i-1][line_number-j]*solmat[j-1];
            solmat[i]=matrix[line_number-1-i][line_number]-dummy;
        }
        dummy = 0;
    }
    for (int i=line_number; i>0; i--){
        cout<< solmat[i-1]<<endl;
        output<<solmat[i-1]<<endl;
    }
    output.close();
}

int main(){
    // open the txt files
    ifstream file_a ("A.txt");
    ifstream file_b ("B.txt");
    //check the txt files whether they are opened or not.
    if(!file_a.is_open()){
        cout << "File not opened..." << endl;
        return 1;
    }
    if (!file_b.is_open()){
        cout << "File not opened..." << endl;
        return 1;
    }
    //a is a mutable pointer to an immutable character/string (A.txt). You cannot change the contents of
    //the location(s) this pointer points to.
    const char * a="A.txt";
    // line number is my row number.
    int line_number = number_of_rows(a);
    // dynamic allocation of a 2x2 matrix
    // I am going to store my A.txt file in matrixa
    float ** matrixa = new float*[line_number];
    for(int i = 0; i < line_number; i++){
        matrixa[i] = new float[line_number];
    }
	// dynamic allocation of a 2x2 matrix
    // This is just for calculating the condition nunber of 2d matrices. I am going to store the absolute
    //value matrice in it.
    float ** matrix2da = new float*[line_number];
    for(int i = 0; i < line_number; i++){
        matrix2da[i] = new float[line_number];
    }
    // dynamic allocation of a 2x2 matrix
    // This is just for calculating the condition nunber of 2d matrices. I am going to store the inverse
    // matrice in it.
    float ** matrix2dinva = new float*[line_number];
    for(int i = 0; i < line_number; i++){
        matrix2dinva[i] = new float[line_number];
    }
    // read A.txt into matrixa
    for (int i=0; i<line_number; i++){
        for (int j=0; j<line_number; j++){
            file_a >> matrixa[i][j];
        }
    }
    //condition number calculation of 2d matrix
    if (line_number == 2){
        float det;
        det= ( (matrixa[0][0] * matrixa[1][1]) - (matrixa[1][0] * matrixa[0][1]));
        if(det ==0){
            cout << "A is a singular matrix. Can not solve the equation." ;
            return 1;
        }
        else{
            // I store the matrixa in matrix2da and then take its absolute values.
            //  I store the matrixa in matrix2dinva and then take inverse and then its absolute values.
            for (int i=0; i<line_number; i++){
                for (int j=0; j<line_number; j++){
                	// for absolute values
                    matrix2da[i][j]= matrixa[i][j];
                    // for inverse
                    matrix2dinva[i][j]= matrixa[i][j];
                    matrix2da[i][j]= abs(matrix2da[i][j]);
                }
            }
            inverse(matrix2dinva);
            for (int i=0; i<line_number; i++){
                for (int j=0; j<line_number; j++){
                    matrix2dinva[i][j]= abs(matrix2dinva[i][j]);
                }
            }
        //  Matrix norm corresponding to vector ? - norm is maximum absolute row sum
            float cond_at_inf = 0;
            for (int i=0; i<line_number; i++){
                float dummy = 0;
                for (int j=0; j<line_number; j++){
                    dummy= dummy + matrix2da[i][j];
                    }
                if(dummy>cond_at_inf){
                    cond_at_inf = dummy;
                }
            }
          // Matrix norm corresponding to vector 1-norm is maximum absolute column sum
            float cond_at_1 = 0;
            for (int i=0; i<line_number; i++){
                float dummy1 = 0;
                for (int j=0; j<line_number; j++){
                    dummy1= dummy1 + matrix2da[j][i];
                }
                if(dummy1>cond_at_1){
                    cond_at_1 = dummy1;
                }
            }
            //  Matrix norm corresponding to vector ? - norm is maximum absolute row sum
            float cond_inv_at_inf = 0;
            for (int i=0; i<line_number; i++){
                float dummy = 0;
                for (int j=0; j<line_number; j++){
                    dummy= dummy + matrix2dinva[i][j];
                }
                if(dummy>cond_inv_at_inf){
                    cond_inv_at_inf = dummy;
                }
            }
            // Matrix norm corresponding to vector 1-norm is maximum absolute column sum
            float cond_inv_at_1 = 0;
            for (int i=0; i<line_number; i++){
                float dummy1 = 0;
                for (int j=0; j<line_number; j++){
                    dummy1= dummy1 + matrix2dinva[j][i];
                }
                if(dummy1>cond_inv_at_1){
                    cond_inv_at_1 = dummy1;
                }
            }
            float condition_number_at_1;
            condition_number_at_1= cond_inv_at_1 * cond_at_1;
            float condition_number_at_inf;
            condition_number_at_inf= cond_inv_at_inf * cond_at_inf;

            cout << "The condition number at 1 is " << condition_number_at_1 << "\n";
            cout << "The condition number at infinity is " << condition_number_at_inf << "\n";
            cout << "\n";
        }
    }
    // dynamic allocation of matrix b
    // I am going to store my B.txt file in matrixb
    float * matrixb;
    matrixb = new float [line_number];
      // read B.txt into matrixb
    for(int i=0;i<line_number;i++){
        file_b >> matrixb[i];
    }
    // dynamic allocation of a new matrix named cascade_matrix in order to store A.txt and B.txt in a
    //single matrix. Last column of my cascade_matrix is goint to be B.txt.
    // It is a line line_numberxline_number+1 matrix
    float **cascade_matrix= new float *[line_number];
    for (int i=0; i<line_number; i++){
        cascade_matrix[i] = new float[line_number+1];
    }
    // store my matrixa and matrixb in cascade_matrix. Last column of cascade matrix is matrixb.
    for (int i=0; i<line_number; i++){
        for (int j=0; j<line_number; j++){
            cascade_matrix[i][j] = matrixa[i][j];
            cascade_matrix[j][line_number] = matrixb[j];
        }
    }
    int column=0;
    // indicate the instantaneous column number
    int line =0;
    // indicate the instantaneous row number
    float max;
    // maximum value
    int max_index=0;
    // maximum index


    // create two row arrays in which I am going to store the instantaneous row and maximum row.
    float max_row[1][line_number+1];
    float current_row[1][line_number+1];

    // this function prints my cascade_matrix. This is just for checking.
	// Step by step seeing the cascade matrice should be useful for understanding the algorithm.
	// if you want to see how my matrices look like you can get rid of the slashes.
	// But it's up to you.
    // cout << "base matrix";
    // cout << "\n" ;
    // print(cascade_matrix,line_number);
    // cout << "\n" << "\n";

    // All the story begins.
    while (line <line_number){
        // first I initialize the maximum value of the instantaneous column.
        // The initialization is always on the diagonal.
        max= cascade_matrix[line][line];
        
        //rearrangement of the matrix
        for ( int i=line; i<line_number; i++){
            // I am going to examine every column. I have to find the the row index with the maximum
            //value.
            if (abs(max) < abs(cascade_matrix[i][column])) {
                // I search for the maximum value row by row in the beginning for 1st column.
                // I store the index in max_index
                max = cascade_matrix[i][column];
                max_index=i;
            }
            else {
            }
        }
        // I found the index of row with max. value of n(here my n is column variable)th column.
        // Then I store the whole row with max. index in max_row row.
        for (int j=0; j<line_number+1; j++){
            max_row[0][j] = cascade_matrix[max_index][j];
        }
       // store the instantaneous row in current_row row.
        for (int j=0; j<=line_number+1; j++){
            current_row[0][j] = cascade_matrix[column][j];
        }
        //I am going to replace current row with max row
        for (int j=0; j<line_number+1; j++){
            cascade_matrix[line][j]=max_row[0][j];
            cascade_matrix[max_index][j]= current_row[0][j];
        }
        // Now I am done with the reordering of matrix.
		
        // cout << "reordering done";
        // cout << "\n";
        // cout << "reordering according to " << line+1<<	" th line";
        // cout << "\n";
        // print(cascade_matrix,line_number);
        // cout << "\n";

		//This function makes zero all the values in n(here variable column)th column under n(here variable line)th line.
        elimination(cascade_matrix,line_number,line,column,max);
	
    // this function prints my cascade_matrix. This is just for checking.
	// Step by step seeing the cascade matrice should be useful for understanding the algorithm.
	// if you want to see how my matrices look like you can get rid of the slashes.
	// But it's up to you.
    // cout << "\n" ;
    // print(cascade_matrix,line_number);
    // cout << "\n" << "\n";

    line=line+1;
	// increase instantaneous row number by one
    column=column+1;
	// increase instantaneous column number by one
	max_index = line;
	// initialize the max_index.
	}
	// reordering and elimination is done.
	
    //singularity check
    //  if A is a singular matrix after the elimination process at least its last row should be a zero
    // row. So I can check the singularity of the matrix.
    // If it is singular the equation can not be solved.
    if(cascade_matrix[line_number-1][line_number-1]==0){
        cout << "A is a singular matrix. Can not solve the equation." ;
        return 1;
    }
    else{
    }
	// cout << "The reordering and elimination is done. Backward elimination and solution process is starting." << endl;
    backward_elimination_and_output(cascade_matrix,line_number);

    //delete algorithm for dynamic allocated matrices !!!
    for(int i = 0; i < line_number; i++) {
        delete [] matrixa[i];
    }
    delete [] matrixa;
    delete[] matrixb;
    for(int i = 0; i < line_number; i++) {
        delete [] cascade_matrix[i];
    }
    delete [] cascade_matrix;
    for(int i = 0; i < line_number; i++) {
        delete [] matrix2da[i];
    }
    delete [] matrix2da;
    for(int i = 0; i < line_number; i++) {
        delete [] matrix2dinva[i];
    }
    delete [] matrix2dinva;
    return 0;
}
//AYDIN UZUN
//2015401210

