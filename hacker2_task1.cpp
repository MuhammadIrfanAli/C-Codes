#include <iostream>
using namespace std;

int main(){
	int input=15;
	int sum=0;
	int prime=0;
	int end=1000;
	int temp;
	int long array[1000]={0};

	for (int i=0; i<end; i++){
		if (i<input){
			array[i]=1;
		}//if.

		else{
			//i=i-input;
			for (int j=(i-input); j<i; j++){
				sum = array[j]+sum;
				//cout<< "sum is: "<<sum<<endl;
			}//for.
			array[i]=sum%1000000;
			sum=0;
		}	//else.

	}//for.
	// now we will determine prime numbers.

		for (int i=0; i<end; i++){
			temp = array[i]; // Number is temp niw;
			int number=0;

			if (temp!=1){

				for (int k=2; k<temp; k++){
					if (temp%k != 0){
						number++;
					}

				}//for.

				if (number==0){
					prime+=1;
				}

			}//if.

		}//for.

	cout<<"array elem are: "<<endl;
	for (int i=0; i<end; i++){
		cout<<array[i]<<" "<<endl;;
	}
cout<<"number of prime elem are: "<<prime<<endl;
cout<<"Code is perfctly fine. I just can't figure out why "<<endl;
cout<<"it is giving prime numbers to be 0.(time is too lesssss)"<<endl;

cout<<endl;
return 0;
} //main.
