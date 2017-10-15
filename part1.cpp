#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <sys/time.h>
#include "boiler.cpp"
//<--------------------------------------------------------------------------->
	//structure defined.
	struct Node{
		string url;
		string data;
		int rank;
		Node *next;

	};//struct
	Node *head = NULL;
	Node *head2 = NULL;
//<-------------------------------------------------------------------------->
	ifstream fin;
	ofstream fout;
//<-------------------------------------------------------------------------->
	//functions defined.
	void loadData();
	void addNewNode();
	void displayContent(Node * startPtr);
	void cal_rank(string inputString);
	void sortData();
	void subSort(Node * tempNode);
	void saveData();
	void reloadData(string inputStr);
	void delete_list(Node *& startPtr);
//<--------------------------------------------------------------------------->
	int main(){
	int num, choice; Node * startPtr;
	int call=0;
	string inputStr;
    while(1){
        cout<<endl<<endl;
        cout<<"\n*****TERRENIUM SEARCH ENGINE*****\n";
        cout<<"1) Search Data.\n";
        cout<<"2) Reload Data.\n";
        cout<<"3) Sava Data.\n";
        cout<<"4) Quit and Save Data.\n";
        cout<<"5) Quit Without Saving. \n";
        cout<<" Any other key to EXIT\n";
        cout<<"Choose your choice : ";
        cin >> choice;
        cin.ignore();
        switch(choice){
        //=======================================
            //Search the Data.
        //=======================================
            case 1 :
            if (call>=1){
            	delete_list(head2);
            }
            cout<<"Please enter the phrase/sentence/word for search purposes.\n";
            getline(cin, inputStr);
            startTimer();
            cout<<"\nShowing Results for **"<<inputStr<<"**\n"<<endl;
            loadData();
            cal_rank(inputStr);
          	sortData();
            displayContent(head2);
            delete_list(head);
            call++;
            cout<<"total time in MicroSec is "<<stopTimer()<<endl;
                 break;
        //=======================================
            //Reload Data:.
        //=======================================
           case 2 :
            reloadData(inputStr);
                 break;
        //=======================================
            //Save Data.
        //=======================================
            case 3 :
            saveData();
                 break;
        //=======================================
            //Quit and Save Data.
        //=======================================
            case 4 :
            saveData();
            cout<<"EXIT SUCCESSFUL"<<endl;
            return 0;
        //=======================================
            //Quit without Saving.
        //=======================================
            case 5 :
    		cout<<"EXIT AUTHORIZED."<<endl;
        //=======================================
  		//Default case quit!
        //=======================================
        default: return 0;
        }//switch.
    }//while.
return 0;

}//main.
//<-------------------------------------------------------------------------->
	//load data.

	void loadData(){
		string tempStr;
		fin.open ("data.txt");
		Node *tempNode = new Node; // new node made
		head = tempNode;
		tempNode->next = NULL;

		while ( !fin.eof() ){
			//for url;
			getline(fin, tempStr,'\n');
			if ( !tempStr.empty() ){ //if string is not empty, only then enter the data.
				tempNode->url=tempStr; // tempStr;
				//for data.
				getline(fin, tempStr, '\n');
				tempNode->data = tempStr;
				addNewNode(); //We need to increase no of nodes by 1.
				tempNode = tempNode->next;
			} //if....
		}//while.
		fin.close();
		} // load data function.

//<------------------------------------------------------------------------------>
	//AddnewNode.
	void addNewNode(){
		Node *tempNode, *tempNode2;
		tempNode =  new Node;
		tempNode2=head;
		if ( tempNode2->next == NULL ){ //in case only one elem is present then.
			tempNode2->next = tempNode;
			tempNode->next = NULL;
		} //if.
		else {
			while ( tempNode2->next!= NULL ){
				tempNode2 =tempNode2->next;
			}//while.
		tempNode2->next = tempNode;
		tempNode->next=NULL;
		} //else.
	}//addNewNode.

//<-------------------------------------------------------------------------------->
//display data in nodes

	void displayContent(Node * startPtr){
		Node *read;
		int found=0;
		read = startPtr;
		if (startPtr==NULL){
			cout<<"Linked List is empty."<<endl;
		}
		else{
			while (read->next!=NULL && read->rank >=1){
				cout<<"URL: " << read->url<<endl;
				cout<< "Data: "<< read->data<<"(rank: " << read->rank<<")"<<endl;
				cout<<endl;
				read = read->next;
				found=1;
			}//while.
			if (found==0){
				cout<<"NO RESULTS FOUND."<<endl;
			}
		}//else.
	}//void.

//<--------------------------------------------------------------------------------->
// Now we will calculate the rank of our linked lists.
    void cal_rank(string inputStr){

    int stop=0;
    Node * tempNode = head;
    fin.open("lowRank.txt");
    string tempStr, tempStr2, tempStr3,tempWord, tempWord2;
    vector <string> inputVec;
    vector <string> lowVec;
    vector <string> dataVec;
    istringstream iss(inputStr);
    // read from the istringstream until failure
    while (getline(iss,tempStr,' '))
        inputVec.push_back(tempStr);
	// store low rank words in a vector.
		while (!fin.eof()){
			getline(fin, tempWord2);
			lowVec.push_back(tempWord2);
		}//while.

   	while (tempNode->next!=NULL){

   		istringstream idd(tempNode->data); //whole data stored for a node in idd.

   		while ( getline(idd, tempWord2, ' ') ){
   			dataVec.push_back(tempWord2);}
   		tempNode->rank = 0;
			for (int i=0; i<inputVec.size(); i++){
				stop=0;
   					for (int j=0; j<dataVec.size(); j++){
   						if ( inputVec[i].compare(dataVec[j])==0 ){ // inputword==dataword.
   							for (int k=0; k < lowVec.size(); k++){
   								if (lowVec[k].compare(inputVec[i])==0 ){//&& lowVec[k].compare(dataVec[j])==0  ){
   									stop=1;
   									tempNode->rank+=1;
   									break;
   								}//if.
   							}//k for.
   							if (stop!=1){
   								tempNode->rank +=1;
   							}//if...
   						}//if..

   						if (stop==1){
   							break; // in case low Rank elem being found.
   						}//if.
   				}// j for...
		 	}//i for...
	dataVec.clear();
	idd.str(" ");
	tempNode = tempNode->next;
}//while.
	inputVec.clear();
	dataVec.clear();
	fin.close();
} // rank func.
//<------------------------------------------------------------------------------------>
void sortData(){
	Node * tempNode=head;
	while(tempNode!=NULL){
		subSort(tempNode);
		Node * nex=tempNode->next;
		delete tempNode;
        tempNode=nex;
	}//while.
} //func List....!
//<----------------------------------------------------------------------->
    void subSort(Node * tempNode){
	Node * tempNode2=new Node ;
	Node * c=head2;
	Node * perv=NULL;
	if(c==NULL){
	    // head2=tempNode2->NULL;
		tempNode2->next=NULL;
		tempNode2->url=tempNode->url;
		tempNode2->data = tempNode->data;
		tempNode2->rank=tempNode->rank;
		head2=tempNode2; // only where do not replace head2 by c.
	}//if.
	else{
		while( (c!=NULL) && (c->rank > tempNode->rank) ){
			perv=c;
			c=c->next;
		}//while.
		if(c==head2){
			tempNode2->next=head2;
			tempNode2->url=tempNode->url;
			tempNode2->data=tempNode->data;
			tempNode2->rank = tempNode->rank;
			head2=tempNode2;
		}//if.
		else{
				tempNode2->next=c;
				perv->next=tempNode2;
				tempNode2->url=tempNode->url;
				tempNode2->data=tempNode->data;
				tempNode2->rank = tempNode->rank;
		}//else.
	}//else.

}//void.
//<------------------------------------------------------------------------------>
//Now delete the prevoius linked lists.
void delete_list(Node *& startPtr){
     Node * tempNode = startPtr->next;
while(tempNode!=NULL) // as I am considering tail->next = NULL
{
    startPtr->next = tempNode->next;
    tempNode->next = NULL;
    delete (tempNode);
    tempNode = startPtr->next;
}//while.
startPtr=NULL;
}// delete function.
//<-------------------------------------------------------------------------------------->
// save file.
	void saveData(){
	Node * tempNode = head2;
	string tempStr;
	ofstream fout;
	string fileName;
	cout<<"Please enter the name of the file: "<<endl;
	cout<<"NOTE: use .txt format at the end.(if desired.)"<<endl;
	cin>>fileName;
	fout.open(fileName.c_str(), ios::out | ios::app);
		while (tempNode!=NULL && tempNode->rank > 0){
           	fout << tempNode->url << endl;
           	fout << tempNode->data << endl;
       	 	tempNode = tempNode->next;
            }
    cout<<"data successfully saved.\n";
    fout.close();
	}//save func..
//<--------------------------------------------------------------------------------------->
// Reload Data...
void reloadData(string inputStr){
	delete_list(head2);
	loadData();
	cal_rank(inputStr);
	sortData();
	displayContent(head2);
	cout<<"data has been reloaded."<<endl;
} //reload.
//<---------------------------------------------------------------------------------------->
