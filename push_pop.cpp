#include<iostream>
using namespace std;
int const numArray=10;
int print=0;
bool push(int st[], int &size, int n );
void pop(int st[], int &size);
int main()
{
int lenArray;
int size=0;
int n;
	lenArray = 10;
	cout<<"Enter the number you want to push into the queue.!!";
	while (size<=10){
	cin >> n;
	int st[numArray];
	push(st, size,n);
	pop(st,size);
}
return 0;
}// main.

bool push(int st[], int &size, int n){
		for (int i=0; i<=size; i++){
				if (i==size){
				st[i]=n;
				print=1;
				}
				if (print==1){
				cout<<"Queue is :\n";
				for (int i=0; i<=size; i++){
				cout<<st[i]<<" ";
				}
				size= size++;
				cout<<"\nfinish";
				cout<<endl<<endl;
				print =0;
				return 1;
				}
		}//for
}// PUSH


void pop(int st[], int &size){
int popNum; int popcheck; int popVal;
		if (size!=0){
		cout<<"If you want to pop a value press 9 else press any other button.\n";
		cin >>popNum;
			if (popNum==9){
			cout<< "which value do you want to be popped out\n";
			cin>>popVal;
				for (int i=0; i<=size; i++){
					if (st[i]==popVal){
					st[i]=0;
					popcheck=1;
					}//if.
						if (popcheck==1){
                        	for (int i=0; i<=size; i++){
                        	cout<<st[i]<<" ";
                        	}
                        size = size--;
                        popcheck=0;
                        cout<< "value popped out.\n"; 
                		}
				}//for
			}//if
		}// if
		else {
		cout<<"No value to be pooped out.";
		}
}
