#include <iostream>
using namespace std;


class robot {
	public:
	
	robot(int in_callsign,int in_battery);
	
	void setbattery(int sbattery){
		battery=sbattery;
	};
	
	void rembattery(int rbattery){
		battery=rbattery-battery;
	};
	
	int getbattery(){
	return battery;
	};
	
	private:
	
	string callsign;
	int battery;

	
	
};

robot::robot(string in_callsign,int battery){
callsign=in_callsign;
battery=in_battery;
};


int main () {

int PROMPT=0

robot takis(C8fb,500);

while ( PROMPT == 0 ){

cout << "======================================================\n";
cout << "================Takis-O-Robotakis=====================\n";

cout << "Press 1 to say hello\n";
cout << "Press 2 to turn left\n";
cout << "Press 3 to turn right\n";
cout << "Press 4 to move forward\n";

cout << "Takis current battery level:";

cout << "Hello My Friend,My callsign is";;

cin >> PROMPT;
};
	
	
return 0;
	
}
