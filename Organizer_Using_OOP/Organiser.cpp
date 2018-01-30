#include "Organiser.h"

Organiser::~Organiser()
{
                       ofstream fout;
                       fout.open("MyOrganiser.csv");
                       if(fout.fail( ) )
                       {
                          cout << "Error. Could not save to file.\n\n\n";
                       }
                       else
                       {

                       }
}
Organiser::Organiser()
{
                      ifstream fin;
                      fin.open("MyOrganiser.csv");
                      if(fin.fail( ) )
                      {
                          cout << "Your Organiser is currently empty.\n\n\n";
                      }
                      else
                      {

                      }
}

void Organiser::DoPrintCommand()
{
//	for (int i=0; i<eventVec.size(); i++){
//		eventVec[i].printEvent();
//	}
	 Schedule print;
	 print.printSchedule();
}

void Organiser::DoCancelCommand()
{


}
void Organiser::DoAddCommand()
{

		Time startT = InputValidate::ReadTime("Please Enter the start time of the event: *hint-> ");
		Time endT = InputValidate::ReadTime("Please Enter the ending time of the event: *hint-> ");
		//bool truth = Time::comparison(startT,endT);
		//if (truth){
		Date startD = InputValidate::ReadDate("Please Enter the start Date of the event: *hint-> ");
		Date endD = InputValidate::ReadDate("Please Enter the end Date of the event: *hint-> ");
		string inputLoc = InputValidate::ReadLine("Please write the venue of the event.");
		Event e1(startT, endT, startD, endD, inputLoc);
		Schedule my_sch;
		my_sch.addSch(e1);
		my_sch.printSchedule();
	//}
}

void Organiser::DoFindCommand()
{

}

void Organiser::CommandLoop()
{
  cout << "******************************************" << endl;
  cout << "****** Welcome to the C++ ORGANIZER ******" << endl;
  cout << "**** The key to your organized future ****" << endl;
  cout << "******************************************" << endl;
  cout << endl;

  string userInput;
  char userChoice;
  while((userChoice != 'q') && (userChoice != 'Q'))
    {
      while((userInput = InputValidate::ReadLine("Enter Choice or ? for help: ")) == "");
      userChoice = userInput.at(0);
      switch(userChoice)
	{
	case 'f':
	case 'F':
	  DoFindCommand();
	  break;
	case 'a':
	case 'A':
	  DoAddCommand();
	  break;
	case 'p':
	case 'P':
	  DoPrintCommand();
	  break;
	case 'c':
	case 'C':
	  DoCancelCommand();
	  break;
	case 'h':
	case 'H':
	case '?':
	  DoHelpCommand();
	  break;
	case 'q':
	case 'Q':
	  break;
	default:
	  cout << "**** Invalid command, try again ****" << endl << endl;
	}
    }
  cout << "Goodbye!" << endl << endl;
}

void Organiser::DoHelpCommand()
{
  cout << "Valid commands are:" << endl;
  cout <<	"    P/Print          print schedule for day" << endl;
  cout <<	"    A/Add            add a new event" << endl;
  cout <<	"    C/Cancel         cancel an already scheduled event" << endl;
  cout <<	"    F/Find           find events by phrase" << endl;
  cout <<	"    Q/Quit           quit" << endl;
  cout << "    H/Help           this help menu" << endl;
  cout << endl;
}
