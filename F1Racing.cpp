
#include "F1Racing.h"
#include <stdlib.h>
int main(){
string d1;
cout<<"Please enter the driver's Name to check his current car: "<<endl;
cin>>d1;
string carName(Driver d1);


}
int Driver::tWins(){
	wins+=1;
	return wins;
}
//<-------------------------------------------->
int F1Car::addFuel(int num){
	fuel = fuel+num;
	return fuel;
}
//<-------------------------------------------->
string F1Car::carName(Driver d1){
	car = "FORMULA JUMBO JET."<<endl;
	//int b = atoi(name.c_str());
	return car;
}
/*<-------------------------------------------->
int Driver::getCar(F1Car var2){
//	return F1Car var2;
	return atoi(var2.name.c_str());
	return atoi(var2.tyre.c_str());
	//return var2.fuel;

}
*/
