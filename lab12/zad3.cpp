#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct student {
	string imie;
	string nazwisko;
	int wiek;
	string indeks;
	student*next;

	student(string imie, string nazwisko, int wiek, string indeks) {
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->wiek = wiek;
		this->indeks = indeks;
		this->next = nullptr;
	}
};

void add_to_list(student*&head, string imie, string nazwisko, int wiek, string indeks) {
	if (head == nullptr)
		head = new student(imie, nazwisko, wiek, indeks);
	else {
		student*temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = new student(imie, nazwisko, wiek, indeks);
	}
}

void zapisz(student*&head) {
	student*temp = head;
	fstream plik;
	plik.open("dane.bin", ios::out | ios::binary);
	plik << "Imie: " << temp->imie << endl << "Nazwisko: " << temp->nazwisko << endl << "Wiek: " << temp->wiek << endl << "Numer indeksu: " << temp->indeks << endl;
	while (temp->next != nullptr) {
		temp = temp->next;
		plik << "Imie: " << temp->imie << endl << "Nazwisko: " << temp->nazwisko << endl << "Wiek: " << temp->wiek << endl << "Numer indeksu: " << temp->indeks << endl;
	}
	plik.close();
}

void odczytaj(student*&head) {
	int suma;
	if (head == nullptr) cout << "Lista pusta";
	else {
		student*temp = head;
		suma = 1;
		while (temp->next != nullptr) {
			temp = temp->next;
			suma = suma + 1;
		}
	}
	ifstream plik;
	string text;
	int koniec;
	plik.open("dane.bin", ios::in | ios::binary);
	if (plik.good()) {
		plik.seekg(0, ios::end);
		koniec = plik.tellg();
		plik.seekg(0);
		koniec = suma * 4;
		for (int i = 0; i < koniec; i++) {
			getline(plik, text);
			cout << text << endl;
		}
	}
	else cout << "Plik nie zostal poprawnie utworzony";
	plik.close();
}


void find(student*&head) {
	string indeks;
	cout << endl;
	cout << "Jaki indeks chcesz znalezc?";
	cin >> indeks;
	if (head == nullptr) {
		cout << "Lista jest pusta";
	}
	if (head->indeks == indeks && head != nullptr) {
		cout << "Imie: " << head->imie << endl;
		cout << "Nazwisko: " << head->nazwisko << endl;
		cout << "Wiek: " << head->wiek << endl;
		cout << "Numer indeksu: " << head->indeks << endl;
	}
	else while (head->next != nullptr) {
		if (head->next->indeks == indeks && head != nullptr) {
			cout << "Imie: " << head->imie << endl;
			cout << "Nazwisko: " << head->nazwisko << endl;
			cout << "Wiek: " << head->wiek << endl;
			cout << "Numer indeksu: " << head->indeks << endl;
		}
	}
}

void delete_from_list(student*&head, string indeks) {
	if (head == nullptr) {
		cout << "Lista pusta";
		return;
	}
	if (head->indeks == indeks) {
		student*temp = head;
		head = head->next;
		delete temp;
	}
	else {
		student*temp = head;
		while (temp->next != nullptr) {
			if (temp->next->indeks == indeks) {
				break;
			}
			temp = temp->next;
		}
		if (temp->next != nullptr) {
			student*temp1 = temp->next;
			temp->next = temp1->next;
			delete temp1;
		}
	}
}


int main() {
	string pytanie;
	int x;
	student*head = nullptr;
	do {
		cout << "1-Dodanie studenta na liste, 2-Wyszuaknie studenta po indeksie, 3-Zapis do pliku, 4-Odczyt z pliku, 5-Usuwanie studentow z listy, 6-Koniec pracy" << endl;
		cin >> x;
		switch (x) {
		case 1: {
					string imie, nazwisko, numer;
					int wiek;
					cout << "Prosze podac imie ";
					cin >> imie;
					cout << "Prosze podac nazwisko ";
					cin >> nazwisko;
					cout << "Prosze podac wiek ";
					cin >> wiek;
					cout << "Prosze podac numer indeksu ";
					cin >> numer;
					add_to_list(head, imie, nazwisko, wiek, numer);
		}break;
		case 2: find(head); break;
		case 3: zapisz(head); break;
		case 4: odczytaj(head); break;
		case 5: {
					string indeks;
					cout << "Podaj nuemr indeksu studenta ktorego chcesz usunac ";
					cin >> indeks;
					delete_from_list(head, indeks);
		} break;
		case 6:exit(1); break;
		}
		cout << "Czy chesz powtorzycz program?" << endl;
		cin >> pytanie;
	} while (pytanie != "n");

}
