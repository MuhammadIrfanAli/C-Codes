#include "Event.h"

	Event::Event(){
	}

	Event::Event(Time t1, Time t2, Date d1, Date d2, string l){
		startTime = t1;
		endTime = t2;
		startDate = d1;
		endDate = d2;
		eventLoc = l;
	}
	void Event::printEvent(){
		Time sT = this->getIT();
		Time eT = this->getFT();
		Date sD = this->getID();
		Date eD = this->getFD();
		string ven = this->getVenue();
		cout<<endl<<"start Time: ";
		sT.printTime();
		cout<<endl<<"Ending time: ";
		eT.printTime();
		cout<<endl<<"Start Date: ";
		sD.printDate();
		cout<<endl<<"End Date: ";
		eD.printDate();
		cout<<endl<<"Description: ";
		cout<<ven<<endl;
	}
	Time Event::getIT(){
		return startTime;
	}
	Time Event::getFT(){
		return endTime;
	}
	Date Event::getID(){
		return startDate;
	}
	Date Event::getFD(){
		return endDate;
	}
	string Event::getVenue(){
		return eventLoc;
	}
//<------------------------------------------------------->*/
