#include "Time.h"
Time::Time()
{} // constructor

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::setTime(int h, int m)
{

    hours = h;
    minutes = m;
}
void Time::printTime()
{
    cout << hours;
    cout << ":";
    cout<<((minutes<10)?"0":"") << minutes<<" hours"<<endl;;
}
bool comparison (Time obj_a, Time obj_b){
	int a_hours = obj_a.getH();
	int a_min = obj_a.getM();
	int b_hours = obj_b.getH();
	int b_min = obj_b.getM();
	if (a_hours>b_hours){
		cout<<"End time can't exceed the starting time."<<endl;
		return false;
	}
	else if(a_hours==b_hours && a_min<b_min){
		cout<<"End time can't exceed the starting time."<<endl;
		return false;
	}
	else{
		return true;
	}

}

bool operator < (Time obj_a, Time obj_b)
{

}

bool operator > (Time obj_a, Time obj_b)
{
     return false;
}

bool operator == (Time obj_a, Time obj_b)
{
     return false;
}
int Time::getH(){
	return hours;
}
int Time::getM(){
	return minutes;
}
