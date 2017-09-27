#include "Control.h"
#include <iostream>
#include<iomanip>
#include<Windows.h>
#include "Client.h"
#include "Product.h"
#include <fstream>
#include "operation.h"
using namespace std;

char DUZCIZGI = 205;
char SOLUSTKOSE = 201;
char SAGUSTKOSE = 187;
char DIKEYCIZGI = 186;
char ASAGIAYRAC = 203;
char SOLALTKOSE = 200;
char SAGALTKOSE = 188;
char YUKARIAYRAC = 202;
char YATAYSAGAAYRAC = 204; //
char YATAYSOLAAYRAC = 185;
enum RENKLER
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHTGRAY = 7,
	DARKGRAY = 8,
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};
void renkAta(int yazirenk)
{
	int arkaplan = 0;

	int sonRenk;

	sonRenk = (16 * arkaplan) + yazirenk;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), sonRenk);
}
void karakterCikar(char karakter, RENKLER renk)
{
	renkAta(renk);
	cout << karakter;
	renkAta(WHITE);
}


void Control::tavanCiz(int genislik)
{
	renkAta(14);
	cout << SOLUSTKOSE;

	for (int i = 0; i < genislik; i++)
		cout << DUZCIZGI;

	cout << SAGUSTKOSE;

	cout << endl;
	renkAta(15);
}

void Control::zeminCiz(int genislik)
{
	renkAta(14);
	cout << SOLALTKOSE;

	for (int i = 0; i < genislik; i++)
		cout << DUZCIZGI;

	cout << SAGALTKOSE;

	cout << endl;
	renkAta(15);
}
void Control::araCiz(int genislik, string yazi)
{
	renkAta(14);
	cout << DIKEYCIZGI;
	renkAta(15);
	cout << std::left << setw(genislik) << yazi;
	renkAta(14);
	cout << DIKEYCIZGI;
	cout << endl;
	renkAta(15);
}

void Control::ayracCiz(int genislik)
{
	renkAta(14);
	cout << YATAYSAGAAYRAC;

	for (int i = 0; i < genislik; i++)
		cout << DUZCIZGI;

	cout << YATAYSOLAAYRAC;

	cout << endl;
	renkAta(15);
}
void Control::musteriListele()
{
	fstream kayit;

	kayit.open("Musteriler.txt", ios::in);

	if (kayit.is_open())
	{
		string isim, soyisim, tcno, telno, tarih;

		while (kayit >> tcno >> isim >> soyisim >> telno >> tarih)
		{

			araCiz(50, tcno + " " + isim + " " + soyisim + " " + telno + " " + tarih);
			ayracCiz(50);
		}

	}

	kayit.close();

}

void Control::musteriPaneli()
{
	tavanCiz(40);
	araCiz(40, "MUSTERI PANELI");
	ayracCiz(40);
	araCiz(40, "1.Urun Al");
	araCiz(40, "2.Islemleri Listele");
	araCiz(40, "3.Islem Sil");
	araCiz(40, "4.Geri");
	zeminCiz(40);

}

void Control::urunListele()
{
	fstream kayit;

	kayit.open("Urunler.txt", ios::in);

	if (kayit.is_open())
	{
		string urunkod, urunisim, fiyat;

		while (kayit >> urunisim >> urunkod >> fiyat)
		{
			araCiz(50, urunisim + " " + urunkod + " " + fiyat);
			ayracCiz(50);
		}
	}
	kayit.close();
}

void Control::yoneticiPaneli()
{
	tavanCiz(40);
	araCiz(40, "YONETICI PANELI");
	ayracCiz(40);
	araCiz(40, "1.Musteri Ekle");
	araCiz(40, "2.Musteri Listele");
	araCiz(40, "3.Musteri Sil");
	araCiz(40, "4.Urun Ekle");
	araCiz(40, "5.Urunleri Listele");
	araCiz(40, "6.Urun Sil");
	zeminCiz(40);
}

void Control::musteriElke()
{
	Client m1;

	fstream kayit;


	string gun = to_string(m1.tarihGetir().gunGetir());
	string ay = to_string(m1.tarihGetir().AyGetir());
	string yil = to_string(m1.tarihGetir().yilGetir());

	araCiz(40, "isim....:" + m1.isimGetir());
	araCiz(40, "Soyisim.:" + m1.soyisimGetir());
	araCiz(40, "TC......:" + m1.tcnoGetir());
	araCiz(40, "Tel.....:" + m1.telnoGetir());
	araCiz(40, "Dogumtarihi:" + gun + "/" + ay + "/" + yil);

	m1.kaydet();


	kayit.close();
}

void Control::musteriSil(string tcno)
{
	fstream temp;

	fstream dosya;

	string TC;

	string isim, soyisim, telno, tarih;

	dosya.open("Musteriler.txt", ios::in | ios::app);
	temp.open("temp.txt", ios::out | ios::app);

	if (dosya.is_open() == true)
	{
		while (dosya >> TC >> isim >> soyisim >> telno >> tarih)
		{

			if (TC != tcno)
			{
				temp << TC << " " << isim << " " << soyisim << " " << telno << " " << tarih << endl;
			}

		}
	}

	dosya.close();
	temp.close();

	remove("Musteriler.txt");
	rename("temp.txt", "Musteriler.txt");

}

void Control::urunEkle()
{
	Product u1;


	araCiz(40, "UrunAdi....:" + u1.urunAdiGetir());
	araCiz(40, "Urunkodu...:" + u1.urunKoduGetir());
	araCiz(40, "Fiyat......:" + u1.fiyatGetir());
	u1.kaydet();
}

void Control::urunSil(string urunkod)
{
	fstream temp;

	fstream dosya;



	dosya.open("Urunler.txt", ios::in | ios::app);
	temp.open("temp.txt", ios::out | ios::app);

	if (dosya.is_open() == true)
	{
		string urunkod1, urunisim, fiyat;
		while (dosya >> urunisim >> urunkod1 >> fiyat)
		{

			if (urunkod1 != urunkod)
			{
				temp << urunisim << " " << urunkod1 << endl;
			}

		}
	}

	dosya.close();
	temp.close();

	remove("Urunler.txt");
	rename("temp.txt", "Urunler.txt");
}

void Control::islemListele(string tcno1)
{


	fstream kayit;

	kayit.open("Islemler.txt", ios::in);

	if (kayit.is_open() == true)
	{
		string islemkodu, urunkodu, tcno;

		while (kayit >> islemkodu >> urunkodu >> tcno)
		{
			if (tcno == tcno1)
			{

				araCiz(50, islemkodu + " " + urunkodu + " " + tcno);
				ayracCiz(50);
			}
		}


	}
	kayit.close();
}

void Control::islemSil(string tcno)
{
	fstream temp;

	fstream dosya;




	dosya.open("Islemler.txt", ios::in | ios::app);
	temp.open("temp.txt", ios::out | ios::app);

	if (dosya.is_open() == true)
	{
		string TC2, islem, urunkodu;
		while (dosya >> islem >> urunkodu >> TC2)
		{

			if (TC2 != tcno)
			{
				temp << islem << " " << urunkodu << " " << TC2 << endl;
			}

		}
	}

	dosya.close();
	temp.close();

	remove("Islemler.txt");
	rename("temp.txt", "Islemler.txt");
}


void Control::anaMenuCiz()
{
	tavanCiz(30);
	araCiz(30, "ANA KONTROL PANELI");
	ayracCiz(30);
	araCiz(30, "1.Musteri Paneli");
	araCiz(30, "2.Yonetici Paneli");
	araCiz(30, "3.Cikis");
	zeminCiz(30);
}

void Control::musteriMenuCiz()
{
	int  secim;
	string urunkodu, tcno;
	operation s1;
	//Musteri();

	tavanCiz(50);
	araCiz(50, "MUSTERILERIN LISTESI");
	ayracCiz(50);
	musteriListele();
	araCiz(50, "LISTE SONU");
	zeminCiz(50);
	cout << "Tc no gir...:";
	cin >> tcno;

	musteriPaneli();
	cout << "Secim...:";
	cin >> secim;
	if (secim == 1)
	{

		s1.tcNoAta(tcno);
		tavanCiz(50);
		araCiz(50, "URUNLER LISTESI");
		ayracCiz(50);
		urunListele();
		araCiz(50, "LISTE SONU");
		zeminCiz(50);
		cout << "Urun Kodu girin...:";
		cin >> urunkodu;
		s1.urunKoduAta(urunkodu);
		s1.kaydet();

	}
	if (secim == 2)
	{

		s1.tcNoAta(tcno);
		tavanCiz(50);
		araCiz(50, "ISLEMLER LISTESI");
		ayracCiz(50);
		islemListele(tcno);
		araCiz(50, "LISTE SONU");
		zeminCiz(50);
	}
	if (secim == 3)
	{
		string tc4;
		tavanCiz(50);
		araCiz(50, "ISLEMLER LISTESI");
		ayracCiz(50);
		araCiz(50, "LISTE SONU");
		zeminCiz(50);
		islemSil(tcno);
	}
	if (secim == 4)
	{



	}

}

void Control::yoneticiMenuCiz()
{
	int secim;
	yoneticiPaneli();
	cout << "Secim...:";
	cin >> secim;
	if (secim == 1)
	{
		tavanCiz(40);
		araCiz(40, "EKLENEN MUSTERI");
		ayracCiz(40);
		musteriElke();
		zeminCiz(40);
	}
	if (secim == 2)
	{
		tavanCiz(50);
		araCiz(50, "MUSTERILERIN LISTESI");
		ayracCiz(50);
		musteriListele();
		araCiz(50, "LISTE SONU");
		zeminCiz(50);

	}
	if (secim == 3)
	{
		tavanCiz(50);
		araCiz(50, "MUSTERILERIN LISTESI");
		ayracCiz(50);
		musteriListele();
		araCiz(50, "LISTE SONU");
		zeminCiz(50);

		string TC1;
		cout << "TC no gir...:";
		cin >> TC1;
		musteriSil(TC1);
		islemSil(TC1);
	}
	if (secim == 4)
	{
		tavanCiz(40);
		araCiz(40, "EKLENEN URUN");
		ayracCiz(40);
		urunEkle();
		zeminCiz(40);
	}
	if (secim == 5)
	{
		tavanCiz(50);
		araCiz(50, "URUNLER LISTESI");
		ayracCiz(50);
		urunListele();
		araCiz(50, "LISTE SONU");
		zeminCiz(50);
	}
	if (secim == 6)
	{
		tavanCiz(50);
		araCiz(50, "URUNLER LISTESI");
		ayracCiz(50);
		urunListele();
		araCiz(50, "LISTE SONU");
		zeminCiz(50);

		string urunkod;
		cout << "Urunkod gir...:";
		cin >> urunkod;
		urunSil(urunkod);
	}
}
