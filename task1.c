#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <sys/time.h>



//=========================================================================================
//		CODE FOR TIME EVALUATION --- DON'T DWELL INTO IT :P
//=========================================================================================
struct timeval t1, t2;
struct timezone tz;

void startTimer()
{
	gettimeofday(&t1, &tz);
}

int stopTimer()
{
	gettimeofday(&t2, &tz);
	return 1000000*(t2.tv_sec - t1.tv_sec) + t2.tv_usec - t1.tv_usec;
}


//==============================================================
//	Defining the nodes and the head of the Linked list
//==============================================================
struct node                                                
{                                                               
	int key;		//stores key in the node
	node *next;             // the reference to the next node
}; 
node * head = NULL;
node * tail = NULL;

//=============================================================================
//	DEFINING THE LINKED LIST FUNCTION TO ADD A NODE TO THE LIST
//=============================================================================
void add_node_at_end (int val) 
{ 
	node *temp, *temp2; 
 	temp = new node; 
	temp->key = val;
 	temp->next = NULL; 
 
 	if (head == NULL) 
	{
  		head = temp; 
		tail = temp;
 	}
	else 
 	{ 
		tail->next = temp;
		tail = temp;
 	} 
} 


//=================================================================================================================
//		DECLARING ARRAY -- ITS GLOBAL VARIABLES AND 
//			THE addToArray FUNCTION. HERE YOU NEED TO IMPLEMENT 
//			THE resize() FUNCTION SUCH THAT IF THE ARRAY SIZE HAS
//			REACHED THE CAPACITY OF ARRAY AND THE USER WANTS TO
//			ADD MORE DATA TO IT THEN YOU DYNAMICALLY ALLOCATE A NEW ARRAY 
//			OF LARGER SIZE (new size must be the presentCapacity + initialCapacity),
// 			COPY ALL ELEMENTS OF THE PREVIOUS ARRAY INTO IT AND THEN ADD THE USER'S DESIRED ENTRY
//==================================================================================================================

int presentCapacity = 40;
int initialCapacity = 40;
int curSize = 0;

int* array = new int[initialCapacity];

void resize(int n);
void addToArray(int n)
{
	if(curSize == presentCapacity)
	{
		resize(n);
	}
	if (curSize < presentCapacity){
		array[curSize] = n;
		curSize++;
	}else{
		cout<<"ERROR: Array Capacity exceeded!!!"<<endl;
	}
}//function.

void resize(int n){
	//=====================================================================
	int num;
	int tempSize;
	tempSize = presentCapacity;
	int* newArray = new int[presentCapacity];
		for(int i=0; i<presentCapacity; i++){

		newArray[i] = array[i];
		}//for.
		presentCapacity = presentCapacity+initialCapacity;
		array[presentCapacity];
		//cout<<"enter your enrty"<<endl;
		//cin>>num;
		newArray[tempSize];
		newArray[tempSize] = n;
		//cout<<"Elements being copied."<<endl;

			for (int i=0; i<=tempSize;i++){
			array[i] = newArray[i];
			}//for.

	//=====================================================================
}

int main(){

	int n = 100000;
	startTimer();
	for (int i=0; i< n ; i++)
		add_node_at_end(i);

	cout<< "For linked list it took "<<stopTimer()<<" microseconds"<<endl;

	startTimer();
	for (int i=0; i< n ; i++)
		addToArray(i);

	cout<< "For Arrays it took "<<stopTimer()<<" microseconds"<<endl; 
}
