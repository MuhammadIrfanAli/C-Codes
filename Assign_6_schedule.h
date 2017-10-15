#include "Event.h"
#include <vector>


class Schedule {
	private:
	vector <Event> eventVec;
	public:
//	vector <Event> eventVec;
	Schedule();
	void printSchedule();
	void addSch(Event tempE);
	//static void addSch();
	//void add_schedule();

};
