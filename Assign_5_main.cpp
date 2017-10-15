#include <iostream>
#include "header.cpp"

int main()
{
int valR,valC,value;
int choice, tempRow, tempCol;
	cout<<"Enter rows of matrix: "<<endl;
	cin>>tempRow;
	cout<<"Enter Cols of matrix: "<<endl;
	cin>>tempCol;
    Matrix* m1 = new Matrix(tempRow,tempCol);
	while(1){
		cout<<"Please Choose."<<endl;
		cout<<"1_ Display."<<endl;
		cout<<"2_ Load."<<endl;
		cout<<"3_ Set_Value."<<endl;
		cout<<"4_ Get_Value."<<endl;
		cout<<"5_ Matrix Addition."<<endl;
		cout<<"6_ Matrix Subtraction."<<endl;
		cout<<"7_ Matrix Multiplication."<<endl;
		cout<<"8_ Matrix Transpose"<<endl;
		cout<<"9_ Determinant"<<endl;
		cin>>choice;

    		if(choice==1){
    			//Display Matrix.
    			m1->display_matrix();
    			cout<<endl;
    		}
    		else if(choice==2){
    			// Load_Matrix
    			m1->load_matrix();
    			cout<<endl;
    		}
    		else if(choice==3){
    			// Set_value.
    			m1->set_value(valR,valC,value);
    			cout<<endl;
    		}
    		else if(choice==4){
    			// Get_Value.
    			cout<<endl;
    			int obtVal = m1->get_value(valR, valC);
    			cout<<"Desired Value is :"<<obtVal<<endl;
    		}
    		else if (choice==24){
    			cout<<endl;
    			int r = m1->get_num_rows();
    			cout<<r<<endl;
    		}
    		else if(choice==45){
    			cout<<endl;
    			int c = m1->get_num_cols();
    			cout<<c<<endl;
    		}
    		else if(choice==5){
    			cout<<endl;
    			// matrix addition.
    			cout<<"Enter number of rows of new Matrix: "<<endl;
    			cin>>tempRow;
    			cout<<"Enter number of Cols of new Matrix: "<<endl;
    			cin>>tempCol;
    			Matrix *m2 = new Matrix (tempRow, tempCol);
    			m2->load_matrix();
    			Matrix *m3 = m1->add(m2);
    			m3->display_matrix();
    		}
		    else if(choice==6){
		    	cout<<endl;
                // matrix addition.
                cout<<"Enter number of rows of new Matrix: "<<endl;
                cin>>tempRow;
                cout<<"Enter number of Cols of new Matrix: "<<endl;
                cin>>tempCol;
                Matrix *m2 = new Matrix (tempRow, tempCol);
                m2->load_matrix();
                Matrix *m3 = m1->subtract(m2);
                m3->display_matrix();
            }
            else if(choice==7){
            	cout<<endl;
		 		cout<<"Enter number of rows of new Matrix: "<<endl;
                cin>>tempRow;
                cout<<"Enter number of Cols of new Matrix: "<<endl;
                cin>>tempCol;
                Matrix *m2 = new Matrix (tempRow, tempCol);
                m2->load_matrix();
            	Matrix *m3 = m1->multiply(m2);
            	cout<<endl<<"MULTIPLICATION results: "<<endl;
            	m3->display_matrix();
            	cout<<endl;
            }
            else if(choice==8){
            	cout<<endl<<"TRANSPOSE of MATRIX is: "<<endl;
            	m1->transpose();
            	return 0;
            }
            else if(choice==9){
            	m1->determinant();
            }
	}//while.
return 0;
}//main.
//<---------------------------------------------->
