// Maria Vounatsou ct12015
#include <iostream>
using namespace std;

void showSimvola(int times, char symbol){
	
	int i;
	for (i=1;i<=times;i++) {
		cout << symbol;
	}
 	cout << endl;
}

void showSimvola(int fores) {
	
	int i;
	for (i=1;i<=fores;i++) {
		cout << "*";
	}
	cout << endl;
}

void showSimvola() {
	
	int i;
	for (i=1;i<=50;i++) {
		cout << "!";
	}
	cout << endl;
}

bool isDisekto(int y) {
	if (y%4 == 0 && y%100 != 0) {
		return true;
	}
	else if (y%400 == 0) {
		return true;
	}
	else {
		return false;
	}
	
}

int zeller(int day, int month, int year) {
	float a = 365*(year-1);
	float b1 = (year-1)/4;
	float b2 = -(year-1)/100;
	float b3 = (year-1)/400;
	float c = (367*month-362)/12;
	int d;
	
	if (month<=2) {
		d = 0;
	}
	else if (month>2 && isDisekto(year)) {
		d = -1;
	}
	else {
		d = -2;
	}
	
	int s = a + b1 + b2 + b3 + c + day + d;
	int x = s%7;
	
	return x;
		
	
}

void showDay(int day, int month, int year, int zellerNumber) {
	string j;
	if (zellerNumber == 0) {
		j = "Sunday";
	}
	else if (zellerNumber == 1) {
		j = "Monday";
	}
	else if (zellerNumber == 2) {
		j = "Tuesday";
	}
	else if (zellerNumber == 3) {
		j = "Wednesday";
	}
	else if (zellerNumber == 4) {
		j = "Thursday";
	}
	else if (zellerNumber == 5) {
		j = "Friday";
	}
	else if (zellerNumber == 6) {
		j = "Saturday";
	}
	else {
		cout << "error";
		return;
	}
	
	cout << "In " << day << "/" << month << "/" << year << " the day is " << j << endl;
}

void showArgies(int etos) {
	
	showSimvola(40,'=');
	cout << "Academic Year Hollidays: " << etos << endl;
	showSimvola(40,'=');
	int z = zeller(28,10,etos);
	showDay(28,10,etos,z);
	showDay(8,11,etos,zeller(8,11,etos));
	showDay(17,11,etos,zeller(17,11,etos));
	int	epomenoEtos = etos + 1;
	showDay(30,1,epomenoEtos,zeller(30,1,epomenoEtos));
	showDay(25,3,epomenoEtos,zeller(25,3,epomenoEtos));
	showDay(1,5,epomenoEtos,zeller(1,5,epomenoEtos));
	showSimvola(40,'#');
}

void showIdentity(string name, string id) {
	
	showSimvola(35,'-');
	cout << "Code : " << id << endl;
	cout << "Name : " << name << endl;
	showSimvola(35,'-');
}


int main() {
	
	int akadEtos;
	cout << "Give academic year" << endl;
	cin >> akadEtos; 
	while (akadEtos>=2000) {
		
		showArgies(akadEtos);
		cout << "Give academic year" << endl;
		cin >> akadEtos;
	}

	showIdentity("Maria Vounatsou","ct12015");
	
	showSimvola(45);
	showSimvola();

	return 0;
}
 
