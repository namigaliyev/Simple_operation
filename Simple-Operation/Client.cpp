#include "Client.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace  std;

string isimlerListesi[] = { "Ahmet","Osman","Ali","Mehmet","Veli","Sarp","Emrah","Eser","Erbil","Oguz","Can","Murat","Sinan","Mert","Mete","Sait","Ervah","Cihat","Orhan","Fatih","Ahu","Binnur","Bilge","Candan","Cahide","Demet","Deste","Gizem","Ece","Elanur","Fatma","Fidan","Gamze","Hale","Hilal","Irmak","Jale","Kader","Kamile","Lale" };
string soyisimlerListesi[] = { "KANDEMIR","ORHON","VURAL","YAVUZ","UZ","ERDEM","DEDE","UYANIK","ASLAN","ERKURAN","ER","DAL","KARAKUM","YILMAZ","TAHTACI","KAYA","ERGE","ONUK","TOPAL","BEDER" };

Client::Client()
{
	srand(time(0));
	int isimIndex = rand() % 40;
	int soyisimIndex = rand() % 20;

	mIsim = isimlerListesi[isimIndex];
	mSoyisim = soyisimlerListesi[soyisimIndex];

	mTcno = tcnouret();
	mTelno = telnoUret();
}
void Client::kaydet()
{
	fstream kayit;

	kayit.open("Musteriler.txt", ios::in | ios::out | ios::app);

	if (kayit.is_open() == true)
	{
		kayit << std::left << setw(6) << tcnoGetir() << " " << setw(6) << isimGetir() << " " << " " << setw(6) << soyisimGetir() << " "
			<< setw(10) << telnoGetir() << setw(5) << " " << tarihGetir().gunGetir() << "/"
			<< tarihGetir().AyGetir() << "/" << tarihGetir().yilGetir() << endl;
	}


	kayit.close();


}

string	Client::tcnoGetir()
{
	return mTcno;
}
string	Client::telnoGetir()
{

	return mTelno;
}
string	Client::isimGetir()
{
	/*int isimIndex = rand() % 40;
	mIsim = isimlerListesi[isimIndex];*/
	return mIsim;
}

std::string	Client::soyisimGetir()
{
	/*int soyisimIndex = rand() % 20;
	mSoyisim = soyisimlerListesi[soyisimIndex];*/
	return mSoyisim;
}
Date	Client::tarihGetir()
{
	return mDogumTarihi;
}

void Client::isimAta(std::string isim)
{
	mIsim = isim;
}
void Client::telnoAta(string telno)
{
	mTelno = telno;
}
void Client::tcnoAta(string tcno)
{
	mTcno = tcno;
}
void Client::soyisimAta(string soyisim)
{
	mSoyisim = soyisim;
}
void Client::tarihAta(Date tarih)
{
	mDogumTarihi = tarih;
}



string	Client::tcnouret()
{
	string tcno = "";

	for (int i = 0; i < 4; i++)
	{
		tcno += '1' + rand() % 9;
	}
	return tcno;
}

string	Client::telnoUret()
{
	string telno = "";
	for (int i = 0; i < 10; i++)
	{
		telno += '0' + rand() % 10;
	}
	return telno;
}
