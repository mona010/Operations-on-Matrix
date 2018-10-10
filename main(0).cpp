// Course:   CS213 - Programming II  - 2018
// Title:    Assignment I - Task 1 - Problem 0
// Program:  CS213-2018-A1-T1-P0
// Purpose:  Using structures and 2D-arrays with Matrices.
// Author-1: Mariam Makram William.        ID: 20170283
// Author-2: Menna Allah Mostafa Mohamed. ID: 20170298
// Author-3: Mona Mohamed Fathy.           ID: 20170300
// Date:    23 September, 2018
// Version: 1.0

#include <iostream>
#include <cassert>

using namespace std;

struct matrix{
    int **data;
    int row, colm;
};

istream& operator>> (istream& is, matrix m1)
{
    cout << "enter the row: " << endl;
    is >> m1.row;
    cout << "enter the colm: " << endl;
    is >> m1.colm;
    m1.data = new int* [m1.row * m1.colm];
    cout << "Enter matrix elements: " << endl;
    for(int i = 0; i < m1.row; ++i){
        for(int j=0;j<m1.colm;j++){
            is >> m1.data[i][j];
           // m1.data[i]=new int[m1.colm];
        }
    }
}

//___________________________________________
// This function creates a matrix.
void createMatrix (int row, int colm, int *num, matrix& mat){
    mat.row = row;
    mat.colm = colm;
    mat.data = new int* [row];

    for (int i = 0; i < row; i++){
            mat.data[i] = new int [colm];
    }
    for (int i = 0; i < row; i++){
            for (int j = 0; j < colm; j++){
                    mat.data[i][j] = num[i * colm + j];
            }
    }
}
//_________________________________________________

// Output operator overloading.
ostream&  operator<< (ostream& out, matrix m){
    for(int i=0; i < m.row; i++){
        for(int j=0; j < m.colm; j++){
            out << m.data[i][j] << "\t" ;
        }
        out << endl;
    }
   return out;
}
//__________________________________________________

// Overloading + Operator.
matrix operator+ (matrix ma1, matrix ma2){
    matrix ma;
    int arr[ma1.row * ma1.colm];
    createMatrix (ma1.row, ma1.colm, arr, ma);
    for (int i=0; i < ma1.row; i++){
        for (int j=0; j < ma1.colm; j++){
            ma.data[i][j] = ma1.data[i][j] + ma2.data[i][j];
        }
    }
    return ma;
}
//__________________________________________________

// Overloading - Operator
matrix operator- (matrix ma1, matrix ma2){
    matrix ma;
    int arr[ma1.row * ma1.colm];
    createMatrix (ma1.row, ma1.colm, arr, ma);
    for (int i=0; i < ma1.row; i++){
        for (int j=0; j < ma1.colm; j++){
            ma.data[i][j] = ma1.data[i][j] - ma2.data[i][j];
        }
    }
    return ma;
}
//__________________________________________________

// Overloading * Operator. to multiply two matrices.
matrix operator* (matrix ma1, matrix ma2){
    matrix ma;
    int arr[ma1.row * ma2.colm];
    createMatrix (ma1.row, ma2.colm, arr, ma);

    for(int i=0; i < ma1.row; i++){
        for(int j=0; j < ma2.colm; j++){
            ma.data[i][j] = 0;
        }
    }
    for(int i=0; i < ma1.row; i++){
        for(int j=0; j < ma2.colm; j++){
            for(int k=0; k < ma1.colm; k++){
                ma.data [i][j] += ma1.data[i][k] * ma2.data[k][j];
            }
        }
    }
    return ma;
}
//__________________________________________________

// Overloading + operator to add a number to entire matrix.
matrix operator+ (matrix ma1, int scalar){
    matrix ma;
    int arr[ma1.row * ma1.colm];
    createMatrix (ma1.row, ma1.colm, arr, ma);
    for (int i=0; i < ma1.row; i++){
        for (int j=0; j <ma1.colm; j++){
            ma.data[i][j] = ma1.data[i][j] + scalar;
        }
    }
    return ma;
}
//____________________________________________________

// Overloading - operator to subtract a number from entire matrix.
matrix operator- (matrix ma1, int scalar){
    matrix ma;
    int arr[ma1.row * ma1.colm] ;
    createMatrix (ma1.row, ma1.colm, arr, ma);
    for (int i=0; i < ma1.row; i++){
        for (int j=0; j < ma1.colm; j++){
            ma.data[i][j] = ma1.data[i][j] - scalar;
        }
    }
    return ma;
}
//____________________________________________________

// Overloading * operator to multiply a number by entire matrix.
matrix operator* (matrix ma1 ,int scalar){
    matrix ma;
    int arr[ma1.row * ma1.colm];
    createMatrix (ma1.row, ma1.colm, arr, ma);
    for (int i=0; i < ma1.row; i++){
        for (int j=0; j < ma1.colm; j++){
            ma.data[i][j] = ma1.data[i][j] * scalar;
        }
    }
    return ma;
}
//_____________________________________________________

// Overloading += Operator to add two matrices and store in the first matrix.
matrix operator+= (matrix ma1, matrix ma2){
    for (int i=0; i < ma1.row; i++){
        for (int j=0; j<ma1.colm; j++){
            ma1.data[i][j] +=  ma2.data[i][j];
        }
    }
    return ma1;
}
//_____________________________________________________

// Overloading -= Operator to subtract two matrices and store in the first matrix.
matrix operator-= (matrix ma1 ,matrix ma2){
    for (int i=0; i < ma1.row; i++){
        for (int j=0; j < ma1.colm; j++){
            ma1.data[i][j] -= ma2.data[i][j];
        }
    }
    return ma1;
}
//______________________________________________________

// Overloading += Operator to add a scalar to matrix and store in the same matrix.
matrix operator+= (matrix ma1 ,int scalar){
    cout << "Enter the number you want to add the matrix with: ";
    cin >> scalar;
    for (int i=0; i < ma1.row; i++){
        for (int j=0 ; j < ma1.colm; j++){
            ma1.data[i][j] +=  scalar;
        }
    }
    return ma1;
}
//________________________________________________________

// Overloading -= Operator to subtract a scalar from matrix and store in the same matrix.
matrix operator-= (matrix ma1, int scalar){
    cout << "Enter the number you want to add the matrix with: ";
    cin >> scalar;
    for (int i=0; i < ma1.row; i++){
        for (int j=0; j < ma1.colm; j++){
            ma1.data[i][j] -= scalar;
        }
    }
    return ma1;
}
//_________________________________________________________

// Overloading ++ Operator to increase all matrix elements by 1.
matrix operator++ (matrix ma1){
    for (int i=0; i < ma1.row; i++){
        for (int j=0; j < ma1.colm; j++){
            ma1.data[i][j]++;
        }
    }
    return ma1;

}
//___________________________________________________________

// Overloading -- Operator to decrease all matrix elements by 1.
matrix operator-- (matrix ma1){
    for (int i=0; i < ma1.row; i++){
        for (int j=0; j<ma1.colm; j++){
            ma1.data[i][j]--;
        }
    }
    return ma1;
}
//___________________________________________________________

// Overloading == Operator to compare the similarity of two matrices.
bool operator== (matrix mat1,matrix mat2){
	if(mat1.row==mat2.row && mat1.colm==mat2.colm){
        for(int i=0;i<mat1.row;i++){
		   for(int j=0;j<mat1.colm;j++){
			  if(mat1.data[i][j]!=mat2.data[i][j])
				  return false;
		   }
	   }
	   return true;
	}
   return false;
}
 //__________________________________________________________

 // Overloadin != operator to compare the similarity of two matrices.
bool operator!= (matrix mat1,matrix mat2){
	if(mat1.row==mat2.row && mat1.colm==mat2.colm){
	   for(int i=0;i<mat1.row;i++){
		   for(int j=0;j<mat1.colm;j++){
			  if(mat1.data[i][j]!=mat2.data[i][j])
				  return true;
		   }
	   }
	   return false;
	}
   return true;
}
//____________________________________________________

// Function to test if the matrix is a square matrix or not.
bool square(matrix mat){
	if(mat.row == mat.colm)
		return true;
	else
		return false;
}
//____________________________________________________

// Function to test if the matrix is symmetric or not.
bool symatric(matrix mat){
     if(mat.row==mat.colm){
		 for(int i=0;i<mat.row;i++){
		     for(int j=0;j<mat.colm;j++){
			    if(mat.data[i][j]!=mat.data[j][i])
				    return false;
		     }
	     }
		 return true;
	 }
	 return false;
}
//___________________________________________________

// Function to test if the matrix is an identity matrix or not.
bool identit (matrix mat){
	 if(mat.row == mat.colm){
		 for(int i=0; i < mat.row; i++){
		     for(int j=0; j < mat.colm; j++){
				 if(i == j && mat.data[i][j] == 1)
					 continue;
				 else if(i != j && mat.data[i][j] == 0)
					 continue;
				 else
					 return false;
			 }
		 }
		 return true;
	 }
	 return false;
}
//____________________________________________________

// Function to transpose matrix.
matrix transpose (matrix mat){
    if(mat.row != mat.colm){
        int data4[mat.row * mat.colm];
        matrix d;
        createMatrix (mat.colm, mat.row, data4, d);
	    for (int i = 0; i < mat.colm; i++){
            for(int j=0;j<mat.row;j++)
               d.data[i][j] = mat.data[j][i];
        }
		return d;
    }

	else if(mat.row == mat.colm){
        int data4[mat.row * mat.colm];
        matrix d;
        createMatrix ( mat.row,mat.colm,data4,d);
        for (int i=0; i < mat.row; i++){
            for(int j=0; j < mat.colm; j++)
               d.data[i][j] = mat.data[j][i];
        }
		return d;
	}
}
//____________________________________________________

int main(){
    while (true){
        int choice, scalar;
        int data1 [] = {1,2,3,4,5,6,7,8};
        int data2 [] = {13,233,3,4,5,6};
        int data3 [] = {10,100,10,100,10,100,10,100};

        matrix mat1, mat2, mat3;
        createMatrix (4, 2, data1, mat1);
        createMatrix (2, 3, data2, mat2);
        createMatrix (4, 2, data3, mat3);

        menu:
            cout << "Choose the property you want to do: " << endl
                 << "   1- Add two matrices." << endl
                 << "   2- Subtract two matrices." << endl
                 << "   3- Multiply two matrices." << endl
                 << "   4- Add a value to a matrix." << endl
                 << "   5- Subtract a value from a matrix." << endl
                 << "   6- Multiply matrix by a value." << endl
                 << "   7- Add 1 to each element in the matrix." << endl
                 << "   8- Subtract 1 from each element in the matrix." << endl
                 << "   9- Check if two matrices are identical." << endl
                 << "  10- Check if two matrices are not identical." << endl
                 << "  11- Check if it is a square matrix." << endl
                 << "  12- Check if it is a square & symmetric matrix." << endl
                 << "  13- Check if it is a square & identity matrix." << endl
                 << "  14- Transpose matrix." << endl
                 << "  15- Enter a matrix. " << endl
                 << "   0- Exit." << endl;

            cout << "I choose: ";
            cin >> choice;

            switch (choice){
                case 0: {
                    return 0;
                    break;
                }
                case 1: {  // Add two matrices.
                    cout << " First Matrix: "  << endl << mat1 << endl;
                    cout << " Second Matrix: " << endl << mat3 << endl;

                    if (mat1.row != mat3.row || mat1.colm != mat3.colm) {
                        cout << "Process is invalid. " << endl << endl;
                    }
                    else {
                    cout << "Two matrices after addition: " << endl;
                    cout << (mat1 + mat3) << endl << endl;
                    }
                    goto menu;
                }
                case 2: { // Subtract two matrices.
                    cout << " First Matrix: "  << endl << mat1 << endl;
                    cout << " Second Matrix: " << endl << mat3 << endl;

                    if (mat1.row != mat3.row || mat1.colm != mat3.colm) {
                        cout << "Process is invalid. " << endl << endl;
                    }
                    else {
                        cout << (mat1 - mat3) << endl << endl;
                    }
                    goto menu;
                }
                case 3: { // Multiply two matrices.
                    cout << " First Matrix: "  << endl << mat1 << endl;
                    cout << " Second Matrix: " << endl << mat2 << endl;

                    if (mat1.colm == mat2.row){
                            cout << "Two matrices after multiplying: " << endl;
                            cout << (mat1 * mat2) << endl << endl;
                            goto menu;
                    }
                    else {
                        cout << "Two matrices can not multiplied." << endl << endl;
                        goto menu;
                    }
                }
                case 4: { // Add a value to a matrix.
                    cout << " Matrix: "  << endl << mat1 << endl;
                    cout << endl << "Enter the value you want to add: ";
                    cin  >> scalar;

                    cout << (mat1 + scalar) << endl << endl;
                    goto menu;
                }
                case 5: { // Subtract a value from a matrix.
                    cout << " Matrix: "  << endl << mat1 << endl;
                    cout << endl << "Enter the value you want to subtract: ";
                    cin  >> scalar;

                    cout << endl << "The matrix: " << endl
                         << (mat1 - scalar) << endl << endl;
                    goto menu;
                }
                case 6: { //  Multiply matrix by a value.
                    cout << " Matrix: "  << endl << mat1 << endl;
                    cout << endl << "Enter the value you want to multiply by: ";
                    cin  >> scalar;
                    cout << endl << "The matrix: " << endl
                         << (mat1 * scalar) << endl << endl;
                    goto menu;
                }
                case 7: { // Add 1 to each element in the matrix.
                    cout << endl << " Matrix: "  << endl << mat1 << endl << endl;
                    cout << "The new matrix: " << endl;
                    cout << (++mat1) << endl << endl;
                    goto menu;
                }
                case 8: { // Subtract 1 from each element in the matrix.
                    cout << endl << " Matrix: "  << endl << mat1 << endl;
                    cout << "The new matrix: " << endl;
                    cout << (--mat1) << endl << endl;
                    goto menu;
                }
                case 9: { // Check if two matrices are identical.
                    cout << " First Matrix: "  << endl << mat1 << endl;
                    cout << " Second Matrix: " << endl << mat2 << endl;
                    if (mat1 == mat2) {
                        cout << "The two matrices are Identical." << endl << endl;
                    }
                    else {
                        cout << "The two matrices are not same." << endl << endl;
                    }
                    goto menu;
                }
                case 10: { // Check if two matrices are not identical.
                    cout << " First Matrix: "  << endl << mat1 << endl;
                    cout << " Second Matrix: " << endl << mat2 << endl;
                    if (mat1 != mat2) {
                        cout << "The two matrices are not same." << endl << endl;
                    }
                    else {
                        cout << "The two matrices are Identical." << endl << endl;
                    }
                    goto menu;
                }
                case 11: { // Check if it is a square matrix.
                    cout << endl << " Matrix: "  << endl << mat3 << endl;
                    if (square(mat3) == 1) {
                        cout << "It is a square matrix." << endl << endl;
                    }
                    else {
                        cout << "It is not a square matrix." << endl << endl;
                    }
                    goto menu;
                }
                case 12: { // Check if it is a square & symmetric matrix.
                    cout << endl << " Matrix: "  << endl << mat3 << endl;
                    if (symatric(mat3) == 1) {
                        cout << "The matrix is Symmetric." << endl << endl;
                    }
                    else {
                        cout << "The matrix is not symmetric." << endl << endl;
                    }
                    goto menu;
                }
                case 13: { // Check if it is a square & identity matrix.
                    cout << endl << " Matrix: "  << endl << mat3 << endl;
                    if (identit(mat3) == 1) {
                        cout << "The matrix is Identity matrix." << endl << endl;
                    }
                    else {
                        cout << "The matrix is not an Identity matrix." << endl << endl;
                    }
                    goto menu;
                }
                case 14: { // Transpose matrix.
                    cout << endl << " Matrix: "  << endl << mat1 << endl;
                    cout << endl << "The matrix after Transpose: " << endl;
                    cout << transpose(mat1) << endl << endl;
                }
                case 15: {
                   matrix matX;
                   cin >> matX;
                   cout << "Your matrix is: " << endl;
                   cout << matX << endl << endl;
                   goto menu;
                }



/*


     // matrix mat1, mat2;
	  //cout<<"enter the data of the first matrix:"<<endl;

	  //cin>>mat1;
//cout<<"enter the data of scecond materix:"<<endl;
	  //cin>>mat2;
	  if(mat1==mat2)
		  cout<<"true the 2 matrix identical";
	  else
		  cout<<"false the 2 matrix not identical "<<endl;
	  cout<<endl;
	  if(mat1!=mat2==1)
		  cout<<"true the 2 matrix are not  same";
	  else
		  cout<<"false the 2 matrix are  same"<<endl;
	}
	else if(x==2)
	{

      int data3 [] = {2,3,4,5,3,8};

        matrix  mat3;
       createMatrix (2, 3, data3, mat3);
	    // cout<<"enter the data of the matrix:"<<endl;
		// cin>>mat3;
	     if(square(mat3)==1)
		     cout<<"true"<<"  "<<"the matrix is square"<<endl;
	     else
		     cout<<"false"<<" "<<"the matrix is not square"<<endl;
	     cout<<endl;
	     if(symatric(mat3)==1)
		     cout<<"true"<<"  "<<"the matrix is symatric"<<endl;
	     else
		     cout<<"false"<<" "<<"the matrix is not symatric"<<endl;
	     cout<<endl;
         if(identit(mat3)==1)
		     cout<<"true"<<"  "<<"the matrix is identity"<<endl;
	     else
		     cout<<"false"<<" "<<"the matrix is not identity"<<endl;
         cout<<"-------------------------------------------";
         cout<<endl;
         cout<<"the matrix after transposing is:"<<endl;
         cout<<transpose(mat3);
     }
  else if (x==3){
  int data1 [] = {1,2,3,4,5,6};
  int data2 [] = {13,233,3,4,5,6};

  matrix mat1, mat2;
  createMatrix (2, 3, data1, mat1);
  createMatrix (2, 3, data2, mat2);
  cout << "the sum is : " << mat1 + mat2 << endl ;
  cout << "the sum is : " << mat1 - mat2 << endl ;
  cout << "the sum is : " << mat1 * mat2 << endl ;
  cout << endl  << mat1* 5 ;
    cout << endl  << mat1- 5 ;
    cout << endl  << mat1+ 5 ;
    cout << "the sum is : " << (mat1+=mat2) << endl ;
  cout << "the sum is : " << (mat1 -= mat2)  << endl ;
  cout << "the sum is : " << (mat1 += 5)<< endl ;
  cout << endl  << (mat1 -= 5);
    cout << endl  << ++mat1 ;
    cout << endl  << --mat1 ;
     }

*/
}

}
}



