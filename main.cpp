#include "heirarchy.cpp"

//Write your code here
int main(){
	PhdStudent p1("Ali","Pakistani",23,"Amir ali kahn","MIT",12);
	string str = p1.getName();
	cout << str <<endl;
				//string name, string nation, int age, int maxScr, int wickets, float avg
	Cricketer c1("Irfan","Pakistani",18,122,90,5);
	c1.setNation("Negro");
	c1.getNation();
	cout<< c1.getNation() <<endl;

return 0;
}
