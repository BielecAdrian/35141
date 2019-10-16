/*COPYRIGHT ADRIAN BIELEC, WSZELKIE PRAWA ZASTRZE¯ONE*/
/* Projekt z 01.04.2016 nic nie poprawia³em, uzna³em ¿e nie ma sensu zmieniaæ wszystkiego na nazwy angielskie. O tak o sobie wrzucam */

#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

void odwrocstring(string& doodwrocenia)
{
	string napis;
	for (int i = doodwrocenia.size() - 1; i >= 0; i--)
		napis += doodwrocenia[i];

	doodwrocenia = napis;
}
void wynikzwroc(int& wynikliczba, string & wynik)
{

	switch (wynikliczba)
	{
	case 10: wynik += "A"; break;
	case 11: wynik += "B"; break;
	case 12: wynik += "C"; break;
	case 13: wynik += "D"; break;
	case 14: wynik += "E"; break;
	case 15: wynik += "F"; break;
	default: wynik += to_string(wynikliczba); break;
	}

	wynikliczba = 0;
}
class Kalkulator
{
	enum System { Binarny, Oktalny, Decymalny, Heksadecymalny };
	//Œciagaweczka 0 - Bin, 1 - Okt, 2- Dec, 3- Heks



	void petla(string znaki, int& wynikliczba, string& wynik, System);

public:
	string nazwa[4], nazwa2[4]; // System z którego przeliczamy na który
	Kalkulator();
	string a;


	string wynik = "";
	string znaki = "";
	int wynikliczba = 0;
	System aktsys, tosystem;

	void zmiensystem(System& dozmiany, System doporownania);
	void wyswietlwynik()
	{
		cout << a;
	}
	void bintohex()
	{
		System* pomocniczy = new System;
		*pomocniczy = tosystem;
		tosystem = Heksadecymalny;
		wynik = "";

		petla(a, wynikliczba, wynik, tosystem);
		tosystem = *pomocniczy;
		delete pomocniczy;

	}
	void bintookt()
	{
		System* pomocniczy = new System;
		*pomocniczy = tosystem;
		tosystem = Oktalny;
		wynik = "";

		petla(a, wynikliczba, wynik, tosystem);
		tosystem = *pomocniczy;
		delete pomocniczy;

	}
	void bintodec();








	void hextobin();
	void okttobin();
	void dectobin();











};
void menu(Kalkulator & systemy)
{
	int wybor;
	system("CLS");
	cout << "Gratulacje wlaczyles menu" << endl;
	cout << "Jezeli chcesz zmienic system " << systemy.nazwa[systemy.aktsys] << " Wcisnij 0.\n";
	cout << "Jezeli chcesz zmienic system " << systemy.nazwa2[systemy.tosystem] << " Wcisnij 1.\n";
	cin >> wybor;
	if (wybor == 0)
		systemy.zmiensystem(systemy.aktsys, systemy.tosystem);
	else if (wybor == 1)
		systemy.zmiensystem(systemy.tosystem, systemy.aktsys);
	else
		cout << "Podales zla liczbe\n";
}
ostream & operator<< (ostream & wyjscie, Kalkulator & ex)
{
	wyjscie << ex.a;
	fstream plik;
	plik.open("save.txt", ios::out | ios::app);
	plik << ex.a << " <--Wyszlo\n";
	plik.close();

	return wyjscie;
}
istream& operator>> (istream & wejscie, Kalkulator & ex)
{
	wejscie >> ex.a;

	fstream plik;
	plik.open("save.txt", ios::out | ios::app);
	plik << "Na systemie " << ex.nazwa[ex.aktsys] << " na " << ex.nazwa2[ex.tosystem] << endl;
	plik << ex.a << " <--Weszlo\n";
	plik.close();


	if (ex.a[0] == 'q' || ex.a[0] == 'Q')
		menu(ex);
	//Œciagaweczka 0 - Bin, 1 - Okt, 2- Dec, 3- Heks
	else if (ex.aktsys == 0 && ex.tosystem == 1) // z binarnego na oktalny
	{
		ex.bintookt();

		ex.wyswietlwynik();
	}
	else if (ex.aktsys == 0 && ex.tosystem == 2) // z binarnego na decymalny
	{
		ex.bintodec();


	}
	else if (ex.aktsys == 0 && ex.tosystem == 3) // z binarnego na heksdecymalny
	{
		ex.bintohex();



	}





	//Œciagaweczka 0 - Bin, 1 - Okt, 2- Dec, 3- Heks
	else if (ex.aktsys == 1 && ex.tosystem == 0) // z oktalnego na binarny
	{
		ex.okttobin();

	}
	else if (ex.aktsys == 1 && ex.tosystem == 2) // z oktalnego na decymalny
	{
		ex.okttobin();
		ex.bintodec();



	}
	else if (ex.aktsys == 1 && ex.tosystem == 3) // z oktalnego na heksadecymalny
	{
		ex.okttobin();
		ex.bintohex();

	}







	//Œciagaweczka 0 - Bin, 1 - Okt, 2- Dec, 3- Heks
	else if (ex.aktsys == 2 && ex.tosystem == 0) // z decymalnego na binarny
		ex.dectobin();
	else if (ex.aktsys == 2 && ex.tosystem == 1) // z decymalnego na oktalny
	{
		ex.dectobin();
		ex.bintookt();
		cout << ex.a;
	}
	else if (ex.aktsys == 2 && ex.tosystem == 3) // z decymalnego na heksadecymalny
	{
		ex.dectobin();
		ex.bintohex();
	}











	//Œciagaweczka 0 - Bin, 1 - Okt, 2- Dec, 3- Heks
	else if (ex.aktsys == 3 && ex.tosystem == 0) // z heksadecymalnego na binarny
		ex.hextobin();
	else if (ex.aktsys == 3 && ex.tosystem == 1) // z heksdecymalnego na oktalny
	{
		ex.hextobin();

		ex.bintookt();
	}
	else if (ex.aktsys == 2 && ex.tosystem == 2) // z heksadecymalnego na decymalny
	{
		ex.hextobin();
		ex.bintodec();
	}
	return wejscie;
}

Kalkulator::Kalkulator()
{
	aktsys = Oktalny;
	tosystem = Binarny;
	//Muszê tablicê zape³niaæ tak poniewa¿ VS nie akceptuje zapisania tablicy w jednym wierszu
	nazwa[0] = "Binarny";
	nazwa[1] = "Oktalny";
	nazwa[2] = "Decymalny";
	nazwa[3] = "Heksadecymalny";
	nazwa2[0] = "Binarny";
	nazwa2[1] = "Oktalny";
	nazwa2[2] = "Decymalny";
	nazwa2[3] = "Heksadecymalny";

}


int main()
{
	Kalkulator glowny;
	int wynik;
	for (;;) {
		cout << "***********Witam w kalkulatorze programistycznym Adriana Bielca***********";



		//To bêdzie pêtla g³ówna 
		system("CLS");

		for (;;)
		{
			cout << "AKTUALNY SYSTEM TO " << glowny.nazwa[glowny.aktsys] << " NA " << glowny.nazwa2[glowny.tosystem] << endl;
			cout << "Jezeli chcesz zmienic system liczbowy napisz znak Q\n";
			cout << "Jezeli chcesz dzialac w tym systemie wpisz liczbe ktora ma byc przeliczona na dany system\n";
			cin >> glowny;
			system("CLS");
			cout << glowny << endl;

		}



	}

	Sleep(100000);





	return 0;
}
void Kalkulator::petla(string znaki, int& wynikliczba, string & wynik, System najaki) // r= d³ugoœæ stringa, string tekst binarny, wynikliczba jest to stosowane do tego ¿e gdy bêdzie wynik < od 10 wpisana zostanie liczba nie litera, wynik jak nazwa mówi zawieraæ bêdzie heksadecymalny wynik np A1;	
{
	int q;
	switch (najaki)
	{
	case Heksadecymalny: q = 4; break;
	case Oktalny: q = 3; break;
	}
	bool czyzrobione = false;


	while (czyzrobione == false) {
		if (znaki.size() % q == 0)
		{

			for (int i = znaki.size() - 1; i >= 0; i--)
			{

				if (znaki[i] == '1') {

					if (q == 4) {
						switch (i % 4)
						{
						case 0: {wynikliczba += 8; wynikzwroc(wynikliczba, wynik); } break;
						case 1: wynikliczba += 4; break;
						case 2:wynikliczba += 2; break;
						case 3:	wynikliczba += 1; break;
						default: cout << "COS NIE TAK"; break;
						}
					}
					else if (q == 3)
					{
						switch (i % 3)
						{
						case 0: {wynikliczba += 4; wynikzwroc(wynikliczba, wynik); } break;
						case 1: wynikliczba += 2; break;
						case 2:wynikliczba += 1; break;
						default: cout << "COS NIE TAK"; break;
						}
					}
				}
				else if (znaki[i] == '0' && i % q == 0)
				{

					wynikzwroc(wynikliczba, wynik);


				}
				if (i > 0)
				{
					czyzrobione = true;
				}


			}




		}
		else if (znaki.size() % q != 0)
		{
			odwrocstring(znaki);
			while (znaki.size() % q != 0) {
				znaki += "0";

			}
			odwrocstring(znaki);
		}
	}
	odwrocstring(wynik);
	a = wynik;
	wynik = "";
}
void Kalkulator::bintodec()
{

	long long int wyniks = 0;

	odwrocstring(a);
	for (int i = 0; i <= a.length() - 1; i++)
	{
		if (a[i] == '1')
			wyniks += pow(2, i);
	}
	a = to_string(wyniks);
	wynik = "";
}
void Kalkulator::hextobin()
{
	odwrocstring(a);

	for (int i = a.size() - 1; i >= 0; i--)
	{
		switch (a[i])
		{
		case '0':wynik += "0000"; break;
		case '1':wynik += "0001"; break;
		case '2':wynik += "0010"; break;
		case '3':wynik += "0011"; break;
		case '4':wynik += "0100"; break;
		case '5':wynik += "0101"; break;
		case '6':wynik += "0110"; break;
		case '7':wynik += "0111"; break;
		case '8':wynik += "1000"; break;
		case '9':wynik += "1001"; break;
		case 'A':wynik += "1010"; break;
		case 'B':wynik += "1011"; break;
		case 'C':wynik += "1100"; break;
		case 'D':wynik += "1101"; break;
		case 'E':wynik += "1110"; break;
		case 'F':wynik += "1111"; break;
		case 'a':wynik += "1010"; break;
		case 'b':wynik += "1011"; break;
		case 'c':wynik += "1100"; break;
		case 'd':wynik += "1101"; break;
		case 'e':wynik += "1110"; break;
		case 'f':wynik += "1111"; break;


		}
	}
	a = wynik;
	wynik = "";

}
void Kalkulator::okttobin()
{
	odwrocstring(a);

	for (int i = a.size() - 1; i >= 0; i--)
	{
		switch (a[i])
		{
		case '0':wynik += "000"; break;
		case '1':wynik += "001"; break;
		case '2':wynik += "010"; break;
		case '3':wynik += "011"; break;
		case '4':wynik += "100"; break;
		case '5':wynik += "101"; break;
		case '6':wynik += "110"; break;
		case '7':wynik += "111"; break;



		}
	}

	a = wynik;
	wynik = "";


}
void Kalkulator::dectobin()
{
	int liczba = stoi(a);


	while (liczba != 0)
	{
		wynik += to_string(liczba % 2);
		if (liczba != 1)
			liczba /= 2;
		else
			liczba = 0;
	}
	odwrocstring(wynik);
	a = wynik;
	wynik = "";
}
void Kalkulator::zmiensystem(System & dozmiany, System doporownania)
{
	int wybor;

	cout << "Na jaki system chcesz zmienic?\n";
	cout << "0. Binarny\n";
	cout << "1. Oktalny\n";
	cout << "2. Decymalny\n";
	cout << "3. Heskadecymalny\n";
	cin >> wybor;
	switch (wybor)
	{
	case 0: {if (Binarny != doporownania) dozmiany = Binarny;
			else
		cout << "Dwa systemy nie moga byc takie same\n"; }break;
	case 1: {if (Oktalny != doporownania) dozmiany = Oktalny;
			else
		cout << "Dwa systemy nie moga byc takie same\n"; }break;
	case 2: {if (Decymalny != doporownania)dozmiany = Decymalny;
			else
		cout << "Dwa systemy nie moga byc takie same\n"; } break;
	case 3: {if (Heksadecymalny != doporownania)dozmiany = Heksadecymalny;
			else
		cout << "Dwa systemy nie moga byc takie same\n"; } break;
	default: cout << "Nie ma takiego wyboru\n"; break;
	}
}