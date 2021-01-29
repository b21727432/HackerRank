#include<iostream> 
using namespace std; 

class sinifD{
	
};
class sinifC : public sinifD{
	public:
		void yazdir(){
			cout << "i am class c" << endl;
		}
};
class sinifB : public sinifD{
	public:
		void yazdir(){
			cout << "i am class b" << endl;
		}
};
class sinifA : public sinifB, public sinifC{
	public:
		void yazdir(){
			cout << "ambigious solved. i am class a" << endl;
		}
};

int main(){
	sinifA temp;
	temp.yazdir();	
}
