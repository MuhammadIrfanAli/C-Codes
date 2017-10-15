#include <iostream>
using namespace std;


int main(){
int r, c;
int num=1;
	cout<<"No of rows."<<endl;
	cin>>r;
	cout<<"No of cols"<<endl;
	cin>>c;
	int array[100][100]={0};

	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
		array[i][j]=num;
		num++;
		}
	}
	// display
	for (int i=0; i<r;i++){
		for (int j=0; j<c;j++){
		cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}







} //main.
