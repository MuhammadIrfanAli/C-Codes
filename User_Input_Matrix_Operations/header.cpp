#include "header.h"

//Constructor
	Matrix::Matrix(int row, int col):
	row(row), col(col){
	arr  = new int*[row];
	for (int i=0; i<row; i++){
		arr[i] = new int[col]();
	}
}// function Constructor
//<------------------------------>
//Destructor...!!!
	Matrix::~Matrix(){
	delete [] arr;
	}
//<------------------------------>
void Matrix::display_matrix(){
if (arr!=NULL){
	cout<<endl<<endl;
    for (int i=0;i<row;i++){
        for (int j=0; j<col;j++){
            cout<<arr[i][j]<<" ";
        }
    cout<<endl<<endl;
    }
}//if
  else {
  cout<<"Empty Matrix, "<<endl;
  }
}// display_matrix.
//<-------------------------------->
// Load Matrix.
void Matrix::load_matrix(){
int temp;
	cout<<"Please enter the elements: "<<endl;
		for (int i=0; i<row;i++){
			for (int j=0;j<col;j++){
				cout<<"@ Row "<< i+1 <<" and col " << j+1 <<endl;
				cin>>temp;
				arr[i][j]=temp;
			}//for.
		}//for.
	cout<<endl;
	cout<<"Formation of Matrix successful"<<endl;

}//load_Matrix
//<------------------------------------>
// Set value.
bool Matrix::set_value(int i, int j, int num){
	cout<<"Enter Row num @ which you want to insert value."<<endl;
	cin>>i;
	cout<<"Enter Col num @ which you want to insert value."<<endl;
	cin>>j;
	cout<<"Enter Value."<<endl;
	cin>>num;
	if (i>0 && i<=row && j>0 && j<=col){
		arr[i-1][j-1]=num;
		cout<<"Value Inserted."<<endl;
		return 1;
	}
	else{
	cout<<"Error Occurred."<<endl;
	return 0;
	}
}//Set_Value
//<--------------------------------------->
// Get_Value.
int Matrix::get_value(int i, int j){
	cout<<"Enter row num to get_Value"<<endl;
	cin>>i;
	cout<<"Enter Col num to get  Value "<<endl;
	cin>>j;
	int temp;
	if (i>0 && i<=row && j>0 && j<=col){
		temp = arr[i-1][j-1];
		return temp;
	}
	else{
		cout<<"Error Occurred"<<endl;
		return 0;
	}

}// Get_Value
//<--------------------------------------->
// get Num of rows and Cols.
int Matrix::get_num_rows(){
	return row;
}
//<--------------------------------------->
int Matrix::get_num_cols(){
	return col;
}
//<--------------------------------------->
// Addition and Subtraction.
Matrix* Matrix::add(Matrix* m2){
	int r2 = m2->get_num_rows();
	int c2 = m2->get_num_cols();
	// Matrix Compatible or not.
	if(row==r2 && col==c2){
		Matrix *m3 = new Matrix(r2,c2);
		for (int i=0; i<r2; i++){
			for (int j=0; j<c2; j++){
				m3->arr[i][j]= arr[i][j]+m2->arr[i][j];
			}//for.
		}//for.
		return m3;
	}//if.
	else {
		cout<<"Matrix Addition is not possible."<<endl;
	} //else.
}// addition...
//<------------------------------------------>
// Addition and Subtraction.
Matrix* Matrix::subtract(Matrix* m2){
        int r2 = m2->get_num_rows();
        int c2 = m2->get_num_cols();
        // Matrix Compatible or not.
        if(row==r2 && col==c2){
                Matrix *m3 = new Matrix(r2,c2);
                for (int i=0; i<r2; i++){
                        for (int j=0; j<c2; j++){
                                m3->arr[i][j]= arr[i][j]-m2->arr[i][j];
                        }//for.
                }//for.
                return m3;
        }//if.
        else {
                cout<<"Matrix Subtraction is not possible."<<endl;
        } //else.
}// addition...
//<------------------------------------------>
// Matrix multiplication.
Matrix* Matrix::multiply(Matrix *m2){
	int sum=0;
	int r2= m2->get_num_rows();
	int c2= m2->get_num_cols();
	if (col==r2){
		Matrix *m3=new Matrix(row,c2);
		for (int i=0;i<row;i++){
			for (int k=0;k<c2;k++){
				for (int j=0;j<col;j++){
					sum =sum + arr[i][j]*m2->arr[j][k];
				}//j for.
			m3->arr[i][k]=sum;
			sum=0;
			}// for k loop.
		}// i for.
		return m3;
	}//if.
	else{
		cout<<"Matrix Multiplication not possible."<<endl;
	}
}
//<------------------------------------------>
// TRANSPOSE.
void Matrix::transpose(){
	Matrix *tempM1= new Matrix(row,col);
//	int r2 = get_num_rows();
//	int c2 = get_num_cols();

		for (int i=0;i<row;i++){
			for (int j=0;j<col;j++){
				tempM1->arr[i][j]=arr[i][j];
			}
		}//i for.
		delete [] arr;
	Matrix *m1= new Matrix(col,row);
		for (int i=0;i<col;i++){
			for (int j=0;j<row;j++){
			m1->arr[i][j] = tempM1->arr[j][i];
			}//for j.
		}// for i.
		delete []tempM1->arr;
		m1->display_matrix();
	}
//<------------------------------------------->
// Find Determinant.
int Matrix::determinant(){
int i,j, det;
int const_r = row;
if (row==col){ // if square matrix.
		for (int k=0;k<const_r;k++){
			i=0;
			j=k;
			int det = Matrix::func(row,col,i,j);
		}
		cout<< det <<endl;
	}//if.
	else{
		cout<<"Determinant does not exist."<<endl;
	}//else.
}//func.
//<------------------------------------------->
// func.
int Matrix::func(int r, int c, int i, int j){
int count_r=0; int count_c=0;
int r1=r-1; int c1=c-1;
	if (r!=1){
	//   Let US make a new Matrix.
		int const_r2=r; int stop=0;
		cout<<"Const_r2 value is: "<<r<<endl;
		Matrix *tempM = new Matrix(r1,c1); // form a new Matrix having dim less than parent matrix.
		int not_r=i; int not_c=j; // These values should never be picked for a new Matrix.
		for (int l=0;l<const_r2;l++){
			cout<<"l value is: "<<l<<endl;
			if (l!=not_r){ // If prohibited value not found at r.
				for (int m=0;m<const_r2;m++){
					if (m!=not_c){ // if prohibited value not found at c.
						tempM->arr[count_r][count_c] = arr[l][m];
						cout<< "count_r is: "<<count_r<<endl;
						cout<<"count_c is: "<<count_c<<endl;
						 if (count_c==const_r2){
						 	count_c=0;
						 }
						count_c++; //
						stop=1;
					}
				}// for m

				if (stop==1){
					count_r++;
				}
				if (count_r==const_r2){
					count_r=0;
				}
					cout<<"stop==1 count_r cval :" << count_r<<endl;
				stop=0;
			}//if.
		}// for l.
	//	Matrix Formed.
		cout<<"Matrix is: "<<endl;
		tempM->display_matrix();
		cout<<"This is in progress. I am trying to redude the matrix."<<endl;
		return 0;

//		return arr[i][j]*func(r-1,c-1,i+1%const_r,(j+1)%const_r);
	}
//	else if(r==2){
//		i=0; j=0;
//	    return (tempM->arr[i][j]*tempM->arr[i+1][j+1]) - (tempM->arr[i][j+1]*tempM->arr[i+1][j]);

//	} // else if.

}//func.
