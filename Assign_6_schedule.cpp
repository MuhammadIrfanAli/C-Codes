#include "schedule.h"

Schedule::Schedule(){}

void Schedule::addSch(Event tempE){
	cout<<"size is: ";
	cout<< eventVec.size()<<endl;
	eventVec.push_back(tempE);
	cout<<"Event Push backed."<<endl;
}

void Schedule::printSchedule(){

	for (int i=0; i<eventVec.size(); i++){
		eventVec[i].printEvent();
	}

}
