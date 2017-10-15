#include<iostream>
#include<string>
using namespace std;

class F1Car{
	private:
			string name;
			string tyre;
			int fuel;
		//Declaration of "private" variables/methods of this class goes here.
	public:
			F1Car(){
			}
			F1Car(F1Car &car){
				name = car.name;
				tyre = car.tyre;
				fuel = car.fuel;
			}
			F1Car(string carName, string carTyre){
				name = carName;
				tyre = carTyre;
			}
			int addFuel(int litre);
			int getName();
		   //Declaration of "public" variables/methods of this class goes here.
};

//NOTE THE SEMICOLON AGAIN :P THIS INFACT IS THE MOST FREQUENT+ANNOYING SYNTAX ERROR OUT OF THE MANY WE GET IN 'OOP; :P
class Driver{
        private:
                        string name;
                        string country;
                        int wins;
                        F1Car var;
                //Declaration of "private" variables/methods of this class goes here.
        public:
                Driver(){
                }
                Driver(string Dname, string Dcountry, int Dwins){
                     	name = Dname;
                 	    country = Dcountry;
                        wins = Dwins;
                }
                Driver(F1Car&, string DFname, string DFtyre)
                {
					var = F1Car(DFname, DFtyre);
					//var.tyre = DFtyre;
					//var.fuel = DFfuel;
                }
                int getCar(F1Car var);
                int tWins();
                //Declaration of "public" variables/methods of this class goes here.
};
//NOTE THIS SEMICOLON AT THE END OF CLASS DECLARATION

