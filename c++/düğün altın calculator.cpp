#include<iostream>

#include<fstream>
using namespace std;

int main(){
	
	ifstream infile("hediye.txt");
	string mytext;
	
	string parse1;
	string parse2;
	string parse3;
	int adet;
	
	int ceyrek = 0;
	int tam = 0;
	int yarim = 0;
	
	double fiyat ;
	cout << "Tam ziynet altini fiyatini giriniz : ";
	cin >> fiyat;
	
	while(infile >> parse1 >> parse2 >> adet >> parse3){
		if(parse3 == "YARIM"){
			yarim = yarim + adet;
		}
		else if(parse3 == "TAM"){
			tam = tam + adet;
		}
		else if(parse3 == "CEYREK"){
			ceyrek = ceyrek + adet;
		}
	}
	infile.close();
	
	ofstream outfile("tlMiktar.txt");
	
	outfile << "TOPLAM " << tam << " ADET TAM = " << tam*fiyat <<" TL"<< endl;
	outfile << "TOPLAM " << yarim << " ADET YARIM = " << yarim*(fiyat/2.0) <<" TL"<< endl;
	outfile << "TOPLAM " << ceyrek << " ADET CEYREK = " << ceyrek*(fiyat/4.0) <<" TL"<< endl;
	outfile << "-----------------------------------------------------------------"<< endl;
	outfile << "TOPLAM = " << tam*fiyat + yarim*(fiyat/2.0) + ceyrek*(fiyat/4.0) <<endl;
	
	
	outfile.close();
	cout << "-------------------------------------" << endl;
	cout << "Tlmiktar.txt olusturuldu.";
	
	return 0;
}
