#include <iostream>
using namespace std;
#include <cstdlib>


//==============================================================
//	Defining the nodes and the head of the Linked list
//==============================================================
struct node                                 
{                                           
	int key;		//stores key in the node
	node *next;             // the reference to the next node
}; 
node * head = NULL;
//==============================================================
//	Add Node at the end of the linked list
//	Assumes that the Linked list has been created and
//	global pointer 'head' points to the first element
//==============================================================

void pdcQueue(int m,int n){
	int array[m];
	int i=0;int len=m;
	node *temp;
	node *temp2;
	temp=head;
	temp2=head;
	while (temp!=NULL){
	array[i]=temp->key;
	temp = temp->next;
	i++;
	}
	cout<<"i is: "<<i<<" and m is: " << m<<endl;
	while (m!=1){
	for (int i=1; i<=n; i++){
		while (temp2->next!=NULL){
			temp2 = temp2->next;
		}//while.
			head = temp->next;
			temp = temp2->next;
			temp->next = NULL;
			
	}//for.


		head = temp2->next;
		delete temp2;
		m--;
	}//outer while
		for (int i=1;i<=len;i++ ){
			if (temp->key==array[i]){
				cout<<"last person served is: "<<m<< " \n";
			}
		}	

}
//<---------------------------------------------------->
int findLength(){
	node *temp;
	temp=head;
	int count=0;
	while (temp!=NULL){
		if (head==NULL){
		cout<<"No elem present in the list"<<endl;
		break;
		}
		else {
		count++;
		}//else.
		temp= temp->next;
	}//while.
 		return count;

}//dunction
//<--------------------------------------------->

void add_node_at_end (int val) 
{ 
	//------------------------------------------------ 
	// Temporary pointers 
	//------------------------------------------------ 
	node *temp, *temp2; 
	//------------------------------------------------ 
 	// Reserve space for new node and fill it with data 
	//------------------------------------------------ 
 	temp = new node; 
	temp->key = val;
	//------------------------------------------------ 
	//	Initialize next pointer to NULL
	//------------------------------------------------ 
 	temp->next = NULL; 
 
	//------------------------------------------------ 
 	// If the list is NULL, point head to new node 
	//------------------------------------------------ 
 	if (head == NULL) 
	{
  		head = temp; 
 	}
	//------------------------------------------------ 
	//	We know list is not empty, use pointer chain
	//	to traverse the list till the last node
	//	Last node will have NULL as next pointer
	//	attach new node to the last node 
	//------------------------------------------------ 
	else 
 	{ 
 	 	temp2 = head;
  		while (temp2->next != NULL) 
  			temp2 = temp2->next; 
  		temp2->next = temp; 

 	} 
} 
//==============================================================
//	display a phone record given a pointer to a struct
//==============================================================
void display(node * x)
{
         cout<<"==================================="<<endl;
         cout<<"           Key: "<< x->key <<endl;
         cout<<"==================================="<<endl;
}
//==============================================================
//	Display the complete Linked List
//	Traverses through the list and uses display
//	function to print each record
//==============================================================
void display_list () 
{
	node *temp2; 
	temp2 = head;
        if (head == NULL)
		cout<<"List is Empty...cannot display"<<endl;
	while (temp2 != NULL)
	{
			display(temp2);
 			temp2 = temp2->next;
	}
}

//==============================================================
//       Delete a record by Name
//==============================================================
void delete_record (int val) 
{ 
        node *temp1;
        node *temp2;

        temp2 = head;
        //-------------------------------------------------------------
        //      If head is NULL, list is empty, nothing to delete
        //-------------------------------------------------------------
        
        if (head == NULL){
        cout<<"The list is empty."<<endl;
        }
        
        while (temp2!=NULL){

        	if (temp2->key == val){
        		//for head match..
        		if (head==temp2){
        		head = temp2->next;
        		cout<<"Value deleted at head position."<<endl;
        		delete temp2;
        		break;
        		}//if.
        			//you don't find at the last position..
        		else if (temp2->next==NULL){
        			temp1->next=NULL;
        			delete temp2;
        			//delete temp1;
        			cout<<"value deledted at the end of linked list"<<endl;
        			break;
      
        		}//elseif.
        		
        		else{
        			temp1->next = temp2->next;
        			delete temp2;
        			//delete temp1;
        			cout<<"value deleted in the mid."<<endl;
        			break;
        		}//else.
        	
        	
        	}
        	temp1 = temp2;
        	temp2 = temp2->next;
   
       }//while. 
   
        	//-------------------------------------------------------------
		//	If removing first element of List
		//	Re-assign the head pointer
		//	delete the previous head
        	//-------------------------------------------------------------
        		//-------------------------------------------------------------
			//	Since deletion in the middle requires two consecutive nodes
			//	Traverse through the list using two consecutive pointers
			//	temp1 and temp2 till temp2 matches the search criteria
			//	temp2 node now needs to be bypassed in order to delete it
			//	This means that temp1 will now point to
			//	where temp2 was pointing, which is temp2->next
			//	Run the loop till you reach the end of the Linked list
        		//-------------------------------------------------------------

			// FILL code here
}

int findElem(int elem){
	int count=1; int done=0;
	node *temp;
	//temp = new node;
	temp = head;
	while (temp!=NULL){
		if (temp->key==elem){
			return count;
			done=1;
			break;
		}//if.
		temp = temp->next;
	count++;
	}//while
	if (done==0){
	cout<<"elementr not found"<<endl;
	}


}//function.

//<----------------------------------------------->
int main(){
int num,val,elem,count,m,n;
	while (1){
	cout<<"To add data, Enter 0"<<endl;
	cout<<"To display data, Enter 1"<<endl;
	cout<<"For deletion, enter 2"<<endl;
	cout<<"To find element, Enter 3"<<endl;
	cout<<"To find lentgh, enter 4"<<endl;
	cout<<"For PdcQueue, enter 5"<<endl;
	cin>>num;

	if (num==0){
		cout<<"Enter number you want to add"<<endl;
		cin>>val;
		add_node_at_end(val);
	}
	else if (num==1){
		display_list();
	}
	else if (num==2){
		cout<<"Enter the number you want to delete."<<endl;
		cin>>val;
		delete_record(val);
	}
	else if(num==3){
		cout<<"Enter the element present in the list."<<endl;
		cin>>elem;
		count = findElem(elem);
		cout<<"Element is at "<<count<<" position"<<endl;
	}
	else if (num==4){
		count = findLength();
		cout<<"lentgh is "<<count<<endl;
	}
	else if (num==5){
		count = findLength();
		m=count;
		cout<<"Please Define n"<<endl;
		cin>>n;
		pdcQueue(m,n);
	}
	else {
		cout<<"The programme will terminate"<<endl;
	}
}//while
}//main.
