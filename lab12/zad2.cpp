#include<iostream>
#include<string>
#include<fstream>
using namespace std;

string imie[3] = { "Adam", "Kamil", "Piotr" };
string nazwisko[3] = { "Malysz", "Stoch", "Zyla"};
string urodziny[3] = { "11.11.1111", "22.22.2222", "33.33.3333"};
int numer[3] = { 111111, 222222, 333333,};

struct osoba {
	string imie;
	string nazwisko;
	int wiek;
	string plec;

	osoba() {};
	osoba(string imie, string nazwisko, int wiek, string plec) {
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->wiek = wiek;
		this->plec = plec;
	}
};

struct student {
	string imie;
	string nazwisko;
	string urodziny;
	int indeks;

	student() {};
	student(string imie, string nazwisko, string urodziny, int indeks) {
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->urodziny = urodziny;
		this->indeks = indeks;
	}
};

int main() {
	int n;
	fstream pliko, pliks;
	cout << "Ile danych chesz podac=";
	cin >> n;
	osoba*tabo = new osoba[n];
	for (int i = 0; i < n; i++) {
		tabo[i].imie = imie[rand() % 2 + 1];
		tabo[i].nazwisko = nazwisko[rand() % 2 + 1];
		tabo[i].wiek = rand() % 100 + 1;
		tabo[i].plec = "mezczyzna";
	}
	student*tabs = new student[n];
	for (int i = 0; i < n; i++) {
		tabs[i].imie = imie[rand() % 2 + 1];
		tabs[i].nazwisko = nazwisko[rand() % 2 + 1];
		tabs[i].urodziny = urodziny[rand() % 2 + 1];
		tabs[i].indeks = numer[rand() % 2 + 1];
	}
	pliko.open("osoba.txt", ios::out);
	pliks.open("student.txt", ios::out);
	for (int i = 0; i < n; i++) {
		pliko << "Imie:" << tabo[i].imie << endl;
		pliko << "Nazwisko:" << tabo[i].nazwisko << endl;
		pliko << "Wiek:" << tabo[i].wiek << endl;
		pliko << "Plec:" << tabo[i].plec << endl;
	}
	for (int i = 0; i < n; i++) {
		pliks << "Imie:" << tabs[i].imie << endl;
		pliks << "Nazwisko:" << tabs[i].nazwisko << endl;
		pliks << "Data urodzenia:" << tabs[i].urodziny << endl;
		pliks << "Numer indeksu:" << tabs[i].indeks << endl;
	}
	pliks.close();
	pliko.close();
	pliko.open("osoba.txt", ios::in);
	pliks.open("student.txt", ios::in);
	for (int i = 0; i < n; i++) {
		pliko >> tabs[i].imie;
		pliko >> tabs[i].nazwisko;
		pliko >> tabs[i].urodziny;
		pliko >> tabs[i].indeks;
	}
	for (int i = 0; i < n; i++) {
		pliks >> tabo[i].imie;
		pliks >> tabo[i].nazwisko;
		pliks >> tabo[i].wiek;
		pliks >> tabo[i].plec;
	}
	cout << "student:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Imie:" << tabs[i].imie << endl;
		cout << "Nazwisko:" << tabs[i].nazwisko << endl;         
		cout << "Data urodzenia:" << tabs[i].urodziny << endl;
		cout << "Numer indeksu:" << tabs[i].indeks << endl;
	}
	cout << endl;
	cout << "osoba" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Imie:" << tabo[i].imie << endl;
		cout << "Nazwisko:" << tabo[i].nazwisko << endl;
		cout << "Wiek:" << tabo[i].wiek << endl;
		cout << "Plec:" << tabo[i].plec << endl;
	}
	delete[] tabo;
	delete[] tabs;
}


