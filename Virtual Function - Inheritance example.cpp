#include <iostream>

using namespace std;
class YasGoster{
    public:
        virtual int Yas() = 0;
};
class Insan:public YasGoster{
    protected:
        string TcNo;
        int yas;
    public:        
        Insan(){
            yas = 21;
        }
        int Yas(){
            cout << "Benim yasim " << yas << endl;
            return yas;
        }
        Insan(string tcNumarasi){
            TcNo = tcNumarasi;
        }
};
class Ogrenci:public Insan{
    private:
        string OgrNo;
    public:
        Ogrenci(){
        }
        void setOgrNo(string ogrenciNo){
            OgrNo = ogrenciNo;
        }
        string getOgrNo(){
            return OgrNo;
        }
        void kendiniTanit(string OgrNosu, int Yasi, string TcNosu){
        	OgrNo = OgrNosu;
        	yas = Yasi;
        	TcNo = TcNosu;
            cout << "Ogr No = " << OgrNo << endl;
            cout << Yas() << endl;
            cout << "Tc Numarasi = " << TcNo << endl;
        }
};
int main()
{
    Ogrenci ogr;
    
    
    ogr.setOgrNo("30718082");
    cout<< "ogr no = " << ogr.getOgrNo() << endl;
    ogr.kendiniTanit("30718082", 21, "32191788290");
    return 0;
}
