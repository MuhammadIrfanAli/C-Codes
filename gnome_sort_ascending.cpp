#include <iostream>
using namespace std;

int main(){
int temp;
int array[10]={0,34,1,7,89,45,23,78,98,24};

	for (int x=0; x<10; x++){ // helps loop run as many times as their are elements in array.


		for (int y=0; y<10-1; y++){ // 

			if (array[y]>array[y+1]){ // picks an int and compares it with the next int in the array. Process happens n-1 times.
			temp = array[y+1];
			array[y+1] = array[y];
			array[y] = temp;
			//These three lines help swap the integers. i-e if ith int is greater then ith+1, then ith+1 int would take
			//place of ith int and vice versa.
			}
// but still not the code is arranged so we have to iterate again.
//therefore, first loop is running nth times.

		}//for.

	}//for.
for (int i=0; i<10; i++){
cout<<array[i]<<" ";
//prints out the elements.
}
cout<<endl;
}//main.

