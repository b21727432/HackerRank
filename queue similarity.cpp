#include <iostream>
using namespace std;


class Kuyruk{
	public:
		int boyut;
		int elemanlar[100];
		Kuyruk(){
			boyut = 0;
		}
		
		friend ostream& operator<<(ostream &os, const Kuyruk& q);
		
		void ekle(int p){
			if(boyut == 100){
				cout << "Kuyruk dolu" << endl;
			} else{
				elemanlar[boyut] = p;
				boyut++;
			}
		}
		void cikar(){
			for (int i = 0; i < boyut; ++i)
    			elemanlar[i] = elemanlar[i + 1];
    		this->boyut--;
		}
		int getBoyut(){
			return boyut;	
		}
		int getSon(){
			return elemanlar[boyut];
		}
		int getSiradaki(){
			return elemanlar[0];
		}
		bool operator== (const Kuyruk &q1){
			if(this->boyut == q1.boyut){
				for(int i = 0; i < this->boyut; i++){
					if(this->elemanlar[i] != q1.elemanlar[i]){
						return false;
					}
				}
				return true;
			}
		}
		
		Kuyruk operator+(Kuyruk const &q1){
			Kuyruk c;
			for(int i = 0; i < this->boyut; i++){
				c.ekle(this->elemanlar[i]);
			}
			for(int i = 0; i < q1.boyut; i++){
				c.ekle(q1.elemanlar[i]);
			}
			return c;
		}
		void torpil(int verilen, int istenen){
			
			
			/*int temp = this->elemanlar[istenen];
			this->elemanlar[istenen] = this->elemanlar[verilen];
			this->elemanlar[verilen] = temp;*/
			//this->elemanlar[this->boyut] = this->elemanlar[this->boyut - 1];
			verilen--;
			istenen--;
			int temp = this->elemanlar[verilen];
			for (int i = verilen; i > istenen; i--)
    			elemanlar[i] = elemanlar[i - 1];
    		this->elemanlar[istenen] = temp;
		}
		void torpil(int verilen){
			
			int temp = this->elemanlar[0];
			this->elemanlar[0] = this->elemanlar[verilen];
			this->elemanlar[verilen] = temp;
			
			
			/*this->elemanlar[this->boyut] = this->elemanlar[this->boyut - 1];
			for (int i = this->boyut - 1; i > 0; i--)
    			elemanlar[i] = elemanlar[i + 1];
    		this->elemanlar[0] = verilen;*/
		}
};
ostream& operator<<(ostream &os, const Kuyruk& q1){
	if(q1.boyut == 0){
		os << "Kuyruk Bos" << endl;
	} else{
		for(int i = 0; i < q1.boyut; i++){
    		os << q1.elemanlar[i] << " ";
		}
			os << endl;
	}
    return os;
}



int main()
{
Kuyruk a,b,c;
cout << a; // a kuyruðunu yaz
for (int i=28;i<32;i++)
{
a.ekle(i * 10); // i sayisinin 10 katini a ya ekle
b.ekle(i * 10); // i sayisinin 10 katini b ye ekle
}
cout<<"a nin boyutu="<<a.getBoyut()<<endl;
cout<<"Kuyruk a=" << a;//a yi yaz
cout<<"Kuyruk b=" << b;//b yi yaz
cout<<"Siradaki a="<<a.getSiradaki()<<endl;//siradakini yaz
a.ekle(1245);//a nin sonuna 1245 ekle
cout << a; // a yi yaz
a.cikar(); //a nin basindakini cikart
cout<<"Siradaki a="<<a.getSiradaki()<<endl;//siradakini yaz
a.torpil(3, 2); //a nin 3. Sirasindaki numarayi 2. yap
cout<<"Kuyruk a=" << a;//a yi yaz
if (a == b)//kuyruklar birbirine eþit mi
cout<<"iki kuyruk esit degil"<<endl;
else
cout<<"iki kuyruk esit degil"<<endl;
c = a + b;// a ile b yi birleþtirip c ye aktar
cout<<"c=" << c;//c yi yaz
return 0;
}
