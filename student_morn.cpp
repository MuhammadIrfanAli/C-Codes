#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#include <string>

struct student{
				string name;//char
				string rollNum;//int
				string grade;//int LetterGrade.
				string subject;
}; // struct .

struct student input[100];
int size=79;
ifstream fin;
ofstream fout;

//==================================================================
//Load Data from the given csv file into the program
//==================================================================
void load_data();
//======================================================================
//	Display whole data in the following format
//			Name 		Ahsan
//			RollNum		123456
//			CGPA		0.5
//			Class		CS200
//			ClassStanding	10	(After Evaluating in Hacker's Edition --- if you have not done hacker's then dont display any value)
//======================================================================
void display_all ();

//================================================================
//		Add a new student to your Data
//================================================================
void add_student();

//==============================================================
//	Search for a record by RollNumber
//==============================================================
void search_record ();

//======================================================================
//       Delete a record by Name
//	 It should show as output the content of deleted entries
//======================================================================
void delete_record ();


//==============================================================================
//	You need to find out the number of students on probation i.e CGPA < 2.0
//	in each class. Your output should be like this.
//		COURSE		STUDENTS ON PROBATION
//		CS200			X
//		MTH210			X
//==============================================================================
void studs_on_prob();

//=======================================================================
//		*********************************
//		*	HACKER'S PROBLEM	*
//		*********************************
//
//	In your .csv file, students are not assigned any classStanding,
//	but you are asked to keep track of their class standing.
//	You will do this by comparing their CGPAs. For a given class the
//	student with highest CGPA will have classStanding = 1 and so on.
//=======================================================================
void class_standing();

//==============================================================
//	Main function implements the menu
//==============================================================
int main(){
    int choice;

    while(1){
		cout<<endl<<endl;
        cout<<"\n*****Student Database*****\n";
        cout<<"1) Load Student Data\n";
        cout<<"2) Display All Records\n";
        cout<<"3) Add Student.\n";
        cout<<"4) Search Student via RollNumber\n";
        cout<<"5) Delete Record.\n";
        cout<<"6) Show count of students on PROBATION.\n";
        cout<<"7) Assign Class Standing to each student.\n";
        cout<<"	Any other key to EXIT\n";
        cout<<"Choose your choice : ";
        cin >> choice;
        switch(choice){
	    //=======================================
            //Load Data into the program.
	    //=======================================
            case 1 :
            load_data();
                 break;
	    //=======================================
            //Display All Records
	    //=======================================
            case 2 :
            display_all();
                 break;
	    //=======================================
            //New Record
	    //=======================================
            case 3 :
			add_student();
				break;
	    //=======================================
            //Search Student via rollNumber.
	    //=======================================
            case 4 :
		search_record();
		break;
	    //=======================================
            //Delete record of a student.
	    //=======================================
            case 5 :
		break;
	    //=======================================
	    //Show count of students on POBATION
	    //=======================================
            case 6 :
		break;
	    //=======================================
	    //Assign ClassStanding to each student
	    //=======================================
            case 7 :
		break;
   	    //=======================================
	    //Default case quit!
	    //=======================================
	    default: return 0;
        }
    }
return 0;
}

//<----------------------------------------------------------------------------------------->
void load_data(){
 		int i=0;
                string a;
                string temp_name, temp_grade, temp_subject, temp_rollNum;
                string name, rollNum, grade, subject; int temp;
                fin.open("MorningLab.csv");


                								while (!fin.eof()){
                                                        getline(fin, temp_rollNum, ',');
                                                        input[i].rollNum = temp_rollNum;

                                                        //for name.
                                                        getline(fin,temp_name , ',');
                                                        input[i].name = temp_name;

                                                        //for grade.
                                                        getline(fin, temp_grade,',');
                                                        input[i].grade = temp_grade;

                                                        //for subject
                                                        getline ( fin, temp_subject);
                                                        input[i].subject = temp_subject;
                                                        i+=1;
												}//while

}//function.
//<------------------------------------------------------------------------------------------>
void display_all(){
	int i=0; string a;
	while (i<=size){
	//name.
	a = input[i].name;
	cout<<"Name: "<<a<<endl;
	//roll Number.
	a = input[i].rollNum;
	cout<<"Roll Number: "<<a<<endl;
	//grade.
	a = input[i].grade;
	cout<<"Grade: "<<a<<endl;
	//subject.
	a = input[i].subject;
	cout<<"Subject: "<<a<<endl;
	cout<<"              <-------------------> \n";
	i+=1;

	}//while.

}//display all


//<--------------------------------------------------------------------------------------------->
void add_student(){
string name, rollNum, grade, subject;
		cout<<"Name: \n";cin>>name;
		cout<<"Roll Number \n"; cin>>rollNum;
		cout<<"Grade \n"; cin>>grade;
		cout<<"Subject \n"; cin>>subject;
		size = size+1;
		cout<<size<<endl;
		input[size].name = name;
		input[size].rollNum = rollNum;
		input[size].grade = grade;
		input[size].subject = subject;

}//add record.


//<------------------------------------------------------------------------------------------------>
void search_record(){
int i=0;
		string str1; string str2; int a; int line=1;
		cout<<"Enter Roll Number to compare \n";
		cin>>str1;
		while (i<=size){
		cout<<input[i].rollNum<<" ";
		a = str1.compare(input[i].rollNum);
				if (a=0){
					cout<<"Name: "<<input[i].name<<endl;;
					cout<<"Roll Number: "<<input[i].rollNum<<endl;
					cout<<"CGPA: "<<input[i].grade<<endl;;
					cout<<"Subject "<<input[i].subject<<endl;
					line = 0;
					break;
				}

i=i+1;
		}
		if (line==1){
		cout<<"Roll Number not found.!!\n";
}
}//search_records.
