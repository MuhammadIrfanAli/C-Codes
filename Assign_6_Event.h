#include "InputValidate.h"
class Event{
	private:
			Time startTime;
			Time endTime;
			Date startDate;
			Date endDate;
			string eventLoc;
	public:
			Event();
			Event(Time time1, Time time2, Date date1, Date date2, string loc);
			void printEvent();
			Time getIT();
			Time getFT();
			Date getID();
			Date getFD();
			string getVenue();

};
