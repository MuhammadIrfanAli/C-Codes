#include<iostream>
#include<string>
using namespace std;

//	CLASS DECLARATIONS

class HumanBeing{
	private:
		string name;
		string nation;
		int age;
	public:
		void setAge(int age1);
		void setNation(string nation1);
		string getName();
		string getNation();
		HumanBeing(string name,string nation,int age);
		void setName(string n);
};

class Cricketer:public HumanBeing{
	private:
		float avg;
		int maxScr;
		int wickets;
	public:
		Cricketer(string name, string nation, int age, int maxScr, int wickets, float avg);
//			 HumanBeing(string name, string nation, int age;
		float getAverage();
		void setMaxScore(int);
};

class PhdStudent:public HumanBeing{
	private:
		string advisor;
		string univ;
		int numpubls;
	public:
		//PhdStudent();
		PhdStudent(string name, string nation, int age, string advisor, string univ,int numPubls);
		string getInstitute();
		void setNumPubls(int);
		string getName();
		//string setNation(string temp);
};
