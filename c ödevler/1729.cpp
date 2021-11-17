#include<iostream>

using namespace std;

class Transportation{
	public:
		int weightOfCargo;
		int distanceToRoute;
		int initialFuelLoaded;
		virtual void checkAvailability() = 0;
		friend istream &operator>>( istream  &input, Transportation &T ) {
			cout << "\nEnter the weight of the cargo : ";
			input >> T.weightOfCargo;
			cout << "Enter the traves distance : ";
        	input >> T.distanceToRoute;
        	return input;            
      	} 
};

class Truck: public Transportation{
	int fuelConsuption;
	public:
		Truck(){
			cout << "A truck is on hold for current transportation" << endl;
			cout << "Enter the amount for initial fuel :";
			cin >> this->initialFuelLoaded;
			this->fuelConsuption = 30;
		}
		void checkAvailability(){
			
			int newFuelConsuption = this->fuelConsuption + this->weightOfCargo;
			int neededFuel = this->distanceToRoute / 100.0 * newFuelConsuption;
			
			try{
				if(neededFuel <= this->initialFuelLoaded){
					cout << "\nSufficient amount of fuel in the truck." << endl;
					cout << "Transportation ship can reach to destination in single trip.";
				} else{
					throw (neededFuel);
				}
			} catch(int neededFuel){
				cout << "\nTransportation Truck needs to refuel at the station.\nNeed to refuel : " << neededFuel - this->initialFuelLoaded << " L more.";
			}
		}
		
};

class Ship: public Transportation{
	int fuelConsuption;
	public:
		Ship(){
			cout << "A cargo ship ship is on hold for current transportation" << endl;
			cout << "Enter the amount for initial fuel : ";
			cin >> this->initialFuelLoaded;
			this->fuelConsuption = 60;
		}
		void checkAvailability(){
			
			int newFuelConsuption = this->fuelConsuption + this->weightOfCargo * 0.5;
			int neededFuel = (this->distanceToRoute / 100.0) * newFuelConsuption;
			try{
				if(neededFuel <= this->initialFuelLoaded){
					cout << "\nSufficient amount of fuel in the ship." << endl;
					cout << "Transportation ship can reach to destination in single trip.\n" << endl; 
				} else{
					throw (neededFuel);
				}
			} catch(int neededFuel){
				cout << "\nTransportation Ship needs to refuel at the station.\nAmount of fuel needed : " << neededFuel - this->initialFuelLoaded << " L more."  << endl;
				cout << endl;
			}
		}
		
		
};
int main(){
	
	cout << "Please enter required information for the transportation of goods.\n" << endl;
	
	Ship ship1;
	cin >> ship1;
	ship1.checkAvailability();
	
	Truck truck1;
	cin >> truck1;
	truck1.checkAvailability();
	
	return 0;
}
