#include <iostream>
using namespace std;

int main(){
int size;
int temp; int stopper;
int array[13] = {8,6,7,3,0,9,34,6,23,78,98,45,100};
//size = (sizeof(array)/4); //btw this works, I have not used it for simplification purposes.
size=13;
cout<<"Sorted array in ascending order is: \n";

	for (int i=0; i<size; i++){
	// if one element has been compared then I have to put i=0;
	// so that It runs again and checks all the values.
		if (stopper!=0){ 
		i=0;
		stopper=0;
		}
		if (array[i+1]<array[i]){ //simply checking if next int is smaller than the previous one.
		temp = array[i];
		array[i] = array[i+1];
		array[i+1] = temp;
		// these lines swap the functions.
		stopper=1;
		}
//Important point is in Gnome sort, in one iteraton you can't sort all the int.
// int are sorted out until it gets bigger value next to it.
// then it will not care whether int present next to next integers are smaller or not like {0,3,5,8,9,4,3,2}./
// so we have to run this loop N^2 times to sort it.
//stopper here is for that function.


        for (int i=0; i<size; i++){
        cout<<array[i]<<" ";
        }
cout<<endl;

return 0;
} // main

