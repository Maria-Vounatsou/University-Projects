#include <iostream>
using namespace std;

class apothiki {
protected:
	int uparxwnLadi;
public:
	string katigoriaLadiou;
	
	float timiLitrou;
	
	float oksitita;
	
	int xwritikotita;
	
	
	apothiki() {
		uparxwnLadi = 0;
		timiLitrou = 0;
		oksitita = 1.0;
		xwritikotita = 4000;	
	};
	
	apothiki(string eidosLadiou, int xwros ) {
		katigoriaLadiou = eidosLadiou;
		xwritikotita = xwros;
		uparxwnLadi = 0;
		timiLitrou = 0;
		oksitita = 1;
	};
	
	apothiki(string eidosLadiou, int xwros, float timi) {
		katigoriaLadiou = eidosLadiou;
		xwritikotita = xwros;
		uparxwnLadi = 0;
		timiLitrou = timi;
		oksitita = 1;
	};
	
	~apothiki() {
		cout << "Dystyxos h apothiki mas afise xronoys kai xathikan " << uparxwnLadi << " litra " << katigoriaLadiou << " elaioladoy." << endl;
	};
	
	float axia() {
		float x;
		x = timiLitrou * uparxwnLadi;
		return x;
	};
	
	void katastasi() {
		cout << "Eidos : " << katigoriaLadiou << endl;
		cout << "MAX : " << xwritikotita << endl;
		cout << "===============================" << endl;
		cout << "Timi : " << timiLitrou << endl;
		cout << "Posotita : " << uparxwnLadi << endl;
		cout << "Oxytita : " << oksitita << endl;
		cout << "===============================" << endl;
		cout << "Axia : " << axia() << endl;
		cout <<  "*******************************" << endl;
	};
	
	void prosthiki(int litra) {
		if (litra + uparxwnLadi <= xwritikotita) {
			uparxwnLadi = litra + uparxwnLadi;
		}
		else {
			cout << "Den ypaxrxei arketos xoros gia " << litra << " litra" << endl;
		}
	};
	
	void aferesi(int litra) {
		if (litra > uparxwnLadi) {
			cout << "Den ypaxrxoyn " << litra << " litra " << katigoriaLadiou << " stin apothiki." << endl << endl;
		}
		else {
			uparxwnLadi =  uparxwnLadi - litra;
		}
	};
	
	apothiki operator+(apothiki A) {
		string eidosLadiou;
		int xwros;
		float timi;
		float oksea;
		int posotita;
		
		eidosLadiou = katigoriaLadiou + "-" + A.katigoriaLadiou;
		xwros = xwritikotita + A.xwritikotita;
		timi = (timiLitrou + A.timiLitrou) / 2;
		oksea = (oksitita + A.oksitita) /2;
		posotita = uparxwnLadi + A.uparxwnLadi;
		
		apothiki Ap(eidosLadiou, xwros, timi);
		Ap.oksitita = oksea;
		Ap.uparxwnLadi = posotita;
		
		 return Ap;
	};
	
	bool operator>(apothiki A) {
		if (axia() > A.axia()) {
			return true;
		}
		else {
			return false;
		}
	};
	
	void operator<<(int poso) {
		prosthiki(poso);
	};
	
	void operator>>(int poso) {
		aferesi(poso);
	};
	
	void operator++(int a) {
		oksitita = oksitita + 0.1;
	};	
};


class dexameni : public apothiki {
public: 
	string topothesia;
	
	dexameni() {
		topothesia = "Mytilini";
		katigoriaLadiou = "Biologiko";
		xwritikotita = 500;
		timiLitrou = 5.55;
	};
	
	void katastasi() {
		cout << "Eidos : " << katigoriaLadiou << endl;
		cout << "MAX : " << xwritikotita << endl;
		cout << "===============================" << endl;
		cout << "Timi : " << timiLitrou << endl;
		cout << "Posotita : " << uparxwnLadi << endl;
		cout << "Oxytita : " << oksitita << endl;
		cout << "===============================" << endl;
		cout << "Axia : " << axia() << endl;
		cout << "Topothesia : " << topothesia << endl;
		cout <<  "*******************************" << endl;
	};
	
};


apothiki storageCreator() {
	string eidosLadiou;
	int xwritikotita;
	float timiLitrou;
	
	cout << "Dwse eidos ladiou, xwritikotita kai timi litrou." << endl;
	cin >> eidosLadiou >> xwritikotita >> timiLitrou;
	
	apothiki A0(eidosLadiou, xwritikotita, timiLitrou);
	A0.oksitita = 0.6;
	
	return A0;
};



int main(){
	
	apothiki A1, A2;
	A1.katigoriaLadiou = "Biomixaniko";
	A1.timiLitrou = 2.5;
	A1.oksitita = 8.5;
	
	A2.katigoriaLadiou = "Extra patrheno";
	A2.timiLitrou = 4.6;
	A2.oksitita = 0.5;
	
	A1.katastasi();
	A2.katastasi();
	
	A1.prosthiki(500);
	A2.prosthiki(200);
	A1.prosthiki(100);
	A2.aferesi(50);
	A2.prosthiki(1000);
	A1.aferesi(700);
	
	A1.katastasi();
	A2.katastasi();
	
	apothiki A3("Biologiko", 6000);
	apothiki A4("Rafine", 3000, 1.83);
	
	A3.katastasi();
	A4.katastasi();
	
	apothiki kentriki;
	kentriki = storageCreator();
	kentriki.katastasi();
	
	apothiki A5;
	A5 = A3 + A4;
	A5.katastasi();
	
	if (A3 > A2) {
		A3.katastasi();
	}
	else {
		A2.katastasi();
	}
	
	A4 << 200;
	A4.katastasi();
	A4 >> 50;
	A4.katastasi();
	A4++;
	A4++;
	A4.katastasi();
	
	dexameni d1;
	d1.katastasi();
	
	return 0;
}
















