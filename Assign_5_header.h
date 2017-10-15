
#include<iostream>
using namespace std;

class Matrix
{
	private:
		int ** arr;						//pointer to the two 2d array
		int row, col;					// number of rows and columns of the matrix 

	public:
		Matrix(int row,int col);		// constructor intialize a m x n with all zeroes
		~Matrix();				        // destructor ; delete the matrix
		void load_matrix();			    // fill the matrix by taking user input 
		void display_matrix();			// display the matrix
		int get_value(int tempNum1, int tempNum2);
						// get function; returns the value at index i,j of the matrix
		bool set_value(int tempI, int tempJ, int tempNum);		// set function; sets index i,j of the matrix
		int get_num_rows();				// get_num_rows function to return the total number of rows in a matrix
		int get_num_cols();				// get_num_cols function to return the total number of columns in the matrix
		Matrix* add(Matrix* m2);		// function to add two matrices

		Matrix* subtract(Matrix* m2);		// function to subtract two  matrices

		void transpose();			// function to find the transpose of the matrix

		Matrix* multiply(Matrix* m2);		// function to multiply the matrix with another matrix

		int determinant();			// function to find the detrminant of the determinant
		int func(int temp1, int temp2, int tempI, int tempJ);					// of the matrix
		/*
		Hacker's task
		*/
		Matrix inverse();

}; 
