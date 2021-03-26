package com.company;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
	    Etciller kurt = new Etciller("beta kurt");
		Etciller kurt2 = new Etciller("alfa kurt", 12);
		Etciller kurt3 = new Etciller("omega kurt", 12, "geyik");


	    Otcullar denizayisi = new Otcullar("denizayısı");
		Otcullar denizayisi2 = new Otcullar("denizayısı", 5);
		Otcullar denizayisi3 = new Otcullar("denizayısı", 6, "yosun");

		List<Etciller> etcillerList = new ArrayList<Etciller>();
		etcillerList.add(kurt);
		etcillerList.add(kurt2);
		etcillerList.add(kurt3);

		List<Otcullar> otcullarList = new ArrayList<Otcullar>();
		otcullarList.add(denizayisi);
		otcullarList.add(denizayisi2);
		otcullarList.add(denizayisi3);

		etcillerList.get(0).avlan();
		etcillerList.get(1).etYe();
		etcillerList.get(2).havasolu();
		etcillerList.get(1).havasolu();
		etcillerList.get(0).hareketet();
		etcillerList.get(2).konus();

		otcullarList.get(0).havasolu();
		otcullarList.get(1).havasolu();
		otcullarList.get(1).kac();
		otcullarList.get(2).otYe();
		otcullarList.get(2).yayil();
		otcullarList.get(0).ye();


    }
}
