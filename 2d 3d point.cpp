#include<iostream>
#include <cmath>
#include <string>

using namespace std;
class Nokta2B;
class Nokta3B;
class Nokta{
    public:
        virtual double operator-(Nokta2B &nokta2b) = 0;
        
        virtual bool operator==(Nokta2B &nokta2b) = 0;
        
        virtual void print() = 0;
        
        virtual Nokta2B & nearest2origin(Nokta2B &nokta2b) = 0;
};

class Nokta2B : public Nokta{
    public:
        Nokta2B(double x1, double y1){
            this->x = x1;
            this->y = y1;
        }
        double getx(){
            return this->x;
        }
        double gety(){
            return this->y;
        }
        double operator-(Nokta2B &nokta2b){
            return sqrt(pow(this->getx() - nokta2b.getx(), 2) + pow(this->gety() - nokta2b.gety(), 2)); 
        }
        bool operator==(Nokta2B &nokta2b){
            if(this->getx() == nokta2b.getx() && this->gety() == nokta2b.gety()){
                return true;
            } else{
                return false;
            }
        }
        Nokta2B & nearest2origin(Nokta2B &nokta2b){
            double orijin1 = abs(pow(this->getx(), 2) + pow(this->gety(), 2));
            double orijin2 = abs(pow(nokta2b.getx(), 2) + pow(nokta2b.gety(), 2));
            
            if(orijin1 > orijin2){
                return nokta2b;
            } else {
                return *this;
            }
        }
        void print(){
            cout << "[" << this->getx() << ", " << this->gety() << "]" << endl;
        }
    private:
        double x;
        double y;        
};

class Nokta3B : public Nokta2B{
    public:
        double z;
        Nokta3B(double x2, double y2, double z2) : Nokta2B(x2, y2){
            this->z = z2;
        }
        double operator-(Nokta3B &nokta3b){
            return sqrt(pow(this->getx() - nokta3b.getx(), 2) + pow(this->gety() - nokta3b.gety(), 2) + pow(this->z - nokta3b.z, 2)); 
        }
        bool operator==(Nokta3B &nokta3b){
            if(this->getx() == nokta3b.getx() && this->gety() == nokta3b.gety() && this->z == nokta3b.z){
                return true;
            } else{
                return false;
            }
        }
        Nokta3B & nearest2origin(Nokta3B &nokta3b){
            double orijin1 = abs(pow(this->getx(), 2) + pow(this->gety(), 2) + pow(this->z, 2));
            double orijin2 = abs(pow(nokta3b.getx(), 2) + pow(nokta3b.gety(), 2) + pow(nokta3b.z, 2));
            if(orijin1 > orijin2){
                return nokta3b;
            } else {
                return *this;
            }
        }
        void print(){
            cout << "[" << this->getx() << ", " << this->gety() << ", " << z << "]" << endl;
        }        
};



int main(int argc, char** argv){
    
    Nokta2B birinci2bnokta(atof(argv[1]), atof(argv[2]));
    Nokta3B birinci3bnokta(atof(argv[3]), atof(argv[4]), atof(argv[5]));
    
    double x1,y1,x2,y2,z2;
    
    cout << "2B nokta degerlerini giriniz x,y : ";
    cin >> x1 >> y1;
    cout << "3B nokta degerlerini giriniz x,y,z : ";
    cin >> x2 >> y2 >> z2;
    
    Nokta2B ikinci2bnokta(x1, y1);
    Nokta3B ikinci3bnokta(x2, y2, z2);
    
    cout << birinci2bnokta - ikinci2bnokta << "\n";
    cout << birinci3bnokta - ikinci3bnokta << "\n";
    
	if(birinci2bnokta == ikinci2bnokta){
		cout << "Birinci2bnokta ile Ikinci2bnokta birbirine esittir \n";
	}
	else{
		cout << "Birinci2bnokta ile Ikinci2bnokta birbirine esit degildir \n";
	}
	
	if(birinci3bnokta == ikinci3bnokta){
		cout << "Birinci3bnokta ile Ikinci3bnokta birbirine esittir \n"; 	
	}
	else{
		cout << "Birinci3bnokta ile Ikinci3bnokta birbirine esit degildir \n";
	}
	
	Nokta2B nokta2b = birinci2bnokta.nearest2origin(ikinci2bnokta);
	nokta2b.print();
	
	Nokta3B nokta3b = birinci3bnokta.nearest2origin(ikinci3bnokta);
	nokta3b.print();
	
    cout << "\n";
    birinci2bnokta.print();
    ikinci2bnokta.print();
    
    birinci3bnokta.print();
    ikinci3bnokta.print();
    
    
    Nokta *pointerClassArray2D[2];
    Nokta *pointerClassArray2D[2];

    pointerClassArray2D[0] = &birinci2bnokta;
    pointerClassArray2D[1] = &ikinci2bnokta;
    
    pointerClassArray3D[0] = &birinci3bnokta;
    pointerClassArray3D[1] = &ikinci3bnokta;
    
    for(int i = 0; i < 2; i++){
    	pointerClassArray2D[i].print();
	}
    
    
    return 0;
}
