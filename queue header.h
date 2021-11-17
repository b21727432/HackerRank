class Kuyruk{
	public:
		int boyut;
		int elemanlar[100];
		Kuyruk(){
			boyut = 0;
		}
		friend Kuyruk operator<<(Kuyruk const &q1);
		
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
		
		bool operator== (const Kuyruk &q1, const Kuyruk &q2);
		
		Kuyruk operator+(Kuyruk const &q1, Kuyruk const &q2){
			for(int i = 0; i < q2.boyut; i++){
				q1.ekle(q2.elemanlar[i]);
			}
			return q1;
		}
};
