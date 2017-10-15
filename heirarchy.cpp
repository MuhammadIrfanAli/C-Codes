#include "heirarchy.h"




HumanBeing::HumanBeing(string name , string nation , int age):
	name(name),nation(nation),age(age){
	//name=name1; nation=nation1; age=age1;
		//Constructor of  Human Being
}

void HumanBeing::setName(string name){
	//Set the name of Human Being to name
}



Cricketer::Cricketer(string name, string nation, int age, int maxScr1, int wickets1, float avg1):
	HumanBeing(name, nation ,age)
{
	maxScr=maxScr1; wickets=wickets1; avg=avg1;
}
float Cricketer::getAverage(){
	// Return the average associated with this cricketer
}

void Cricketer::setMaxScore(int max){
	//Set the maximum runs scored by the cricketer to max
}


PhdStudent::PhdStudent(string name, string nation, int age, string advisor1, string univ1,int numpubls1):
	HumanBeing(name, nation, age)
	{
		advisor=advisor1; univ=univ1; numpubls=numpubls1;
	}
string PhdStudent::getInstitute(){
	//Return the institute name
}

void PhdStudent::setNumPubls(int n){
	//Set the number of publications from a PhdStudent to be equal to n;
}
string HumanBeing::getName(){
	return name;
}
string PhdStudent::getName(){
	string tempN = HumanBeing::getName();
	string tempN2 = "DR.";
	string tempN3 = tempN2+tempN;
	return tempN3;
}
void HumanBeing::setAge(int temp){
	age = temp;
}
void HumanBeing::setNation(string temp){

}
string HumanBeing::getNation(){
		return nation;
}
