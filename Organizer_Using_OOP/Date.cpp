#include "Date.h"
Date::Date(){}
Date::Date(int d1, int m1, int y1)
{
    Day = d1;
    Month = m1;
    Year=y1;
}

void Date::setDate(int d2, int m2, int y2)
{

    Day = d2;
    Month = m2;
    Year=y2;
}

void Date::printDate()
{
    cout << ((Day<10)?"0":"") << Day<<" / ";
    cout<<((Month<10)?"0":"") << Month;
    cout << " / " << Year<<endl;
}
bool comparison(Date obj_a, Date obj_b){
	int a_day = obj_a.getDay();
	int a_month = obj_a.getMonth();
	int a_year = obj_a.getYear();
	int b_day = obj_b.getDay();
	int b_month = obj_b.getMonth();
	int b_year = obj_b.getYear();

	if (a_year<b_year){
		cout<<"Starting Date can't exceed the Ending Date."<<endl;
		return false;
	}
	else if(a_year<2012 || b_year<2012){
		cout<<"Event can't be created in the past."<<endl;
		return false;
	}
	else if(a_month <= 0 || a_month >12 || b_month <= 0 || b_month >12){
		cout<<"Months do not exist."<<endl;
		return false;
	}
	else if( (a_month==2 && a_day>29) || (b_month==2 && b_day>29)){
		cout<<"LOL. Febrauray month is only 28/29 days long."<<endl;
		return false;
	}
	else if(a_day<=0 || b_day<=0 || a_day>31 || b_day>32){
		cout<<"Please enter again."<<endl;
		return false;
	}
	else{
		return true;
	}
}

int Date::getDay(){
	return Day;
}
int Date::getMonth(){
	return Month;
}
int Date::getYear(){
	return Year;
}

bool operator < (Date obj_a, Date obj_b)
{
//	if(obj_a.Year




}
bool operator > (Date obj_a, Date obj_b)
{

}

bool operator == (Date obj_a, Date obj_b)
{

}
