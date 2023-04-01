#include <iostream>
using namespace std;

//######################################################################
//#####                    ROBOT CLASS                             #####
//######################################################################

class robot {
	public:
	
	//##Constructor
	robot(string in_callsign,int in_battery, int in_overcharge, int in_discharge_limit, bool in_autocharge);
	
	string setcallsign();
	string getcallsign();
	string move(int used_battery,string move_type);
	string moveforward();
	string moveleft();
	string moveright();
	string charge();
	string movebackward();
	
	int getoverchargelimit(){
	return overcharge_limit;
	}
	
	int getdischarge_limit(){
		return discharge_limit;
	}
	
	//get autocharge state
	bool getautocharge(){
		return autocharge;
	}
	
	//set autocharge state switch
	string switch_autocharge(){
		string a_msg;
		
		if (autocharge == true){
			autocharge=false;
			a_msg="Autocharge has been turn off";
		} else if (autocharge == false){
			autocharge=true;
			a_msg="Autocharge has been turn on";
		}
		
		return a_msg;
	}
	//adds to battery level in respect to overcharge limit
	void addbattery(int sbattery){
		int tempbattery;
		tempbattery = battery + sbattery;
		
		if (tempbattery < overcharge_limit){
		battery=battery+sbattery;
	}else{
		cout << "Cannot charge the battery above overcharge limit";
		}
	};
	
	//REMOVES BATTERY POINTS FROM BATTERY
	bool rembattery(int &rbattery,string &msg){
		
		int energy_needed;
		bool can_it_charge;
		energy_needed=battery - rbattery;

		
		//discharge protection
		if(energy_needed > discharge_limit){
			battery=energy_needed;
			can_it_charge=true;
		}else {

			if ( autocharge == true ){
				msg="Cannot discharge battery below " + to_string(discharge_limit);
				msg= msg + "\nAuto charging.\n";
				charge();
				can_it_charge=true;
			}
			else if( autocharge == false ){
				msg="\nCannot discharge battery below " + to_string(discharge_limit);
				can_it_charge=false;
			}
		}
		return can_it_charge;
	};
	
	int getbattery(){
	return battery;
	};
	
	private:
	
	string callsign;
	int battery;
	int overcharge_limit;
	int discharge_limit;
	//is takis going to auto charge?
	bool autocharge;
	
};

//#####################################
//##         CONSTRUCTOR

robot::robot(string in_callsign,int in_battery,int in_overcharge,int in_discharge_limit, bool in_autocharge){
callsign=in_callsign;
battery=in_battery;
overcharge_limit=in_overcharge;
discharge_limit=in_discharge_limit;
autocharge=in_autocharge;
};

//######################################################################
//#####                  ROBOT FUNCTIONS                           #####
//######################################################################




//#############################################
//#####            GETCALLSING            #####


string robot::getcallsign(){
	int energy_required;
	//int total_energy;
	string msg;
	
	energy_required=75;
	

	if ( rembattery(energy_required,msg) == true ){
		msg= msg + "Hello My Friend,My callsign is:" + callsign + "\n";
		
	}else if ( rembattery(energy_required,msg) == false ){
		msg= msg + "Takis cannot call his callsign.";
		
	}
	
	
	
	
	return msg;
	};


//#############################################
//#####            SETCALLSING            #####

string robot::setcallsign(){
		string msg;
		int energy_required;
		
		energy_required=100;

		if ( rembattery(energy_required,msg) == true ){			
			string in_callsign;
			cout << "Write takis new callsign:";
			cin  >> in_callsign;
			
			callsign=in_callsign;
			
			msg= msg + "Takis callsign has been set.";
		}else if ( rembattery(energy_required,msg) == false ) {

			msg= msg + "Call callsign requires " + to_string(energy_required) + " energy points\n";
			msg= msg + "Takis cannot set his callsign.";
		
		}
		return msg;
};


//#################################
//#####        MOVES


string robot::move(int used_battery,string move_type){
	//int total_battery;
	string msg;
	
	

	//does not allow the battery to get below 0
	if (rembattery(used_battery,msg) == true){
		msg= msg + "Takis moved " + move_type;
	}else if (rembattery(used_battery,msg) == false){

		msg= msg + "Moving " + move_type + " requires ";
		msg= msg + to_string(used_battery) + " battery points\n";
		msg= msg + "Takis cannot move.";
	}
	
	return msg;
};

string robot::moveleft(){
	string msg;
	msg=move(50,"left");
	return msg;
};


string robot::moveright(){
	string msg;
	msg=move(50,"right");
	return msg;
};


string robot::moveforward(){
string msg;
msg=move(100,"forward");
return msg;
};

string robot::movebackward(){
string msg;
msg=move(100,"backwards");
return msg;
};



//#################################
//#####        CHARGING

string robot::charge(){
		
	//takis overcharge protection
	int temp_battery;
	int temp_overcharge_limit;
	int charge_energy;
	int total_energy;
	string msg;
	
	
	temp_battery=getbattery();
	charge_energy=300;
	//calculates total energy so limit wont ever be passed
	total_energy = charge_energy + temp_battery;
	
	//retrieves takis energy limit
	temp_overcharge_limit=getoverchargelimit();
	
	//only allow value below the overcharge limit
	if ( total_energy < temp_overcharge_limit){
		addbattery(charge_energy);
		msg="Takis got charged 300 energy points\n";
	} else{
		msg="Takis overcharge limit is:" + to_string(temp_overcharge_limit);
		msg= msg + "\n\n";
		msg= msg + "Cannot charge takis beyond his limit.\n";
		msg = msg + "If overcharged he is going to blow-up!\n";
	}
			
	
	return msg;
	
	

}


//######################################################################
//#####                     The Main Function                      #####
//######################################################################

int main () {
	
	//default callsign, battery level & battery overcharge limit
	robot takis("C8fb",500,1200,50,true);
	
	
	//#######################################################
	//#####                THE MAIN MENU                #####
	string PROMPT_MSG;
	int PROMPT=1;
	
	while ( PROMPT != 9 ){
		
	cout << "\n\n\n\n";
	cout << "===========================================================\n";
	cout << "====                 Takis-O-Robotakis                 ====\n";
	cout << "===========================================================\n";
	cout << "\n";
	cout << "By:Jozmon\n";
	
	cout << "\n\n\n\n";
	
	cout << "+---------+--------------------------+-----------------+\n";
	cout << "| Key     |  Action                  | Battery points  |\n";
	cout << "+---------+--------------------------+-----------------+\n";
	cout << "| Press 1 |  Print His Callsign      | 75              |\n";
	cout << "| Press 2 |  Set His Callsign        | 125             |\n";
	cout << "| Press 3 |  Move Forward            | 100             |\n";
	cout << "| Press 4 |  Move Backward           | 100             |\n";
	cout << "| Press 5 |  Turn Right              | 50              |\n";
	cout << "| Press 6 |  Turn Left               | 50              |\n";
	cout << "| Press 7 |  Charge Takis            | 300             |\n";
	cout << "| Press 8 |  Change Autocharge state | 300             |\n";
	cout << "+---------+----------------------+---------------------+\n";

	cout << "\n";
	cout << "Takis autocharge state is:" << takis.getautocharge();
	cout << "\n";
	cout << "Takis current battery level:" << takis.getbattery(); 
	cout << "\n\n";
	
	cout << "To take an action write one of the following numbers\n";
	cout << "on the prompt below and press enter\n\n";
	
	cout << "To exit press 9\n";


	
	cout << "\n\n";
	
	

	cout << PROMPT_MSG;
	PROMPT_MSG=" ";
	cout << "\n\n";
	
	cout << "Select one of the following actions:";
	cin >> PROMPT;

	switch (PROMPT){
		case 1:
			PROMPT_MSG=takis.getcallsign();
			break;
		case 2:
			PROMPT_MSG=takis.setcallsign();
			break;
			
		case 3:
			PROMPT_MSG=takis.moveforward();
			break;
		case 4:
			PROMPT_MSG=takis.movebackward();
			
		case 5:
			PROMPT_MSG=takis.moveright();
			break;
			
		case 6:
			PROMPT_MSG = takis.moveleft();
			break;
			
		case 7:
			PROMPT_MSG = takis.charge();
			break;
		case 8:
			PROMPT_MSG = takis.switch_autocharge();
			break;
				
		default:
		
		PROMPT_MSG="Wrong option";
		
	}




};
	
	
return 0;
	
}
