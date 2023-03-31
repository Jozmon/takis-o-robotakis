#include <iostream>
using namespace std;


class robot {
	public:
	
	robot(string in_callsign,int in_battery, int in_overcharge);
	
	void moveforward();
	void moveleft();
	void moveright();
	void charge();
	
	void setcallsign(string in_callsign){
		callsign=in_callsign;
	};
	
	int getoverchargelimit(){
	return overcharge_limit;
	}
	
	string getcallsign(){
		return callsign;
	}
	
	void addbattery(int sbattery){
		int tempbattery;
		tempbattery = battery + sbattery;
		if (tempbattery < overcharge_limit){
		battery=battery+sbattery;
	}else{
		cout << "Cannot charge the battery above overcharge limit";
		}
	};
	
	void rembattery(int rbattery){
		battery=battery-rbattery;
	};
	
	int getbattery(){
	return battery;
	};
	
	private:
	
	string callsign;
	int battery;
	int overcharge_limit;
	
	
};

robot::robot(string in_callsign,int in_battery,int in_overcharge){
callsign=in_callsign;
battery=in_battery;
overcharge_limit=in_overcharge;
};

void robot::moveforward(){
rembattery(100);
};

void robot::moveright(){
rembattery(50);
};

void robot::moveleft(){
rembattery(50);
}

//void robot::charge(){
//addbattery(300);
//}
	

int main () {
	
	string new_callsign;
	string PROMPT_MSG;
	char PROMPT=1;
	
	//default callsign, battery level & battery overcharge limit
	robot takis("C8fb",500,1200);

	while ( PROMPT != 9 ){
		
	cout << "\n\n\n\n";
	cout << "======================================================\n";
	cout << "================Takis-O-Robotakis=====================\n";
	cout << "======================================================\n";

	cout << "\n\n\n\n";

	cout << "Press 1 to print his callsign\n";
	cout << "Press 2 to move forward\n";
	cout << "Press 3 to turn right\n";
	cout << "Press 4 to turn left\n";
	cout << "Press 5 charge takis 300 battery points\n";
	cout << "Press 6 to set his callsign\n\n";

	cout << "To exit press 9\n\n";

	cout << "Takis current battery level:" << takis.getbattery(); 
	
	cout << "\n\n";
	
	

	cout << PROMPT_MSG;
	PROMPT_MSG=" ";
	cout << "\n\n";
	
	cout << "Select one of the following actions:";
	cin >> PROMPT;

	switch (PROMPT){
		case 1:
			PROMPT_MSG="Hello My Friend,My callsign is:" + takis.getcallsign() + "\n";
			cout << takis.getcallsign();
			break;
			
		case 2:
			//does not allow the battery to get below 0
			if (takis.getbattery() > 0){
				takis.moveforward();
				PROMPT_MSG="Takis moved forward\n";
			}else{
				PROMPT_MSG="Takis cannot move! Battery level dropped to zero!";
			}
			
			break;
			
		case 3:
			//does not allow the battery to get below 0
			if (takis.getbattery() > 0){
			takis.moveright();
			PROMPT_MSG="Takis moved right\n";
			}else{
			 PROMPT_MSG="Takis cannot move! Battery level dropped to zero!";
			}
			break;
			
		case 4:
			//does not allow the battery to get below 0
			if (takis.getbattery() > 0){
			takis.moveleft();
			PROMPT_MSG="Takis moved left\n";

			}else{
			 PROMPT_MSG="Takis cannot move battery level dropped to zero!";
			}

			break;
			
		case 5:
		
			//takis overcharge protection
			int temp_battery;
			int temp_overcharge_limit;
			int charge_energy;
			int total_energy;
			
			charge_energy=300;
			
			temp_battery=takis.getbattery();
			charge_energy=300;
			//calculates total energy so limit wont ever be passed
			total_energy = charge_energy + temp_battery;
			
			//retrieves takis energy limit
			temp_overcharge_limit=takis.getoverchargelimit();
			
			//only allow value below the overcharge limit
			if ( total_energy < temp_overcharge_limit){
				takis.addbattery(charge_energy);
				PROMPT_MSG="Takis got charged 300 energy points\n";
			} else{
				PROMPT_MSG="Cannot charge takis byond his limit! If overcharged he is going to blow-up!\n";
			}
				break;
				
		case 6:

			cout << "Write takis new callsign:";
			cin  >> new_callsign;
			takis.setcallsign(new_callsign);
			break;
		
		default:
		
		PROMPT_MSG="Wrong option";
		
	}




};
	
	
return 0;
	
}
