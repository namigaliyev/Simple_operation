#include "Product.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

string urunListesi[] = { "Ekran_karti","Ses_Karti","Islemci","Klavye","Fare","Monitor","Ram","Sabit_Disk",
"Hoparlor","SSD_Disk","Notebook","Kasa","Flash_Disk","Tablet","Cep_Telefonu","Kulaklik","Yazici","Scanner",
"Optik_Okuyucu","Tv_Karti" };

Product::Product()
{
	int urunIndex = rand() % 20 + 1;
	mUrunAdi = urunListesi[urunIndex];

	mUrunKodu = urunKoduUret();
	mFiyat = fiyatUret();
}

void Product::kaydet()
{
	fstream kayit;

	kayit.open("Urunler.txt", ios::in | ios::out | ios::ate);

	if (kayit.is_open() == true)
	{
		kayit << std::left << setw(6) << urunKoduGetir() << " " << setw(6) << urunAdiGetir() << " "
			<< setw(6) << fiyatGetir() << endl;

	}
	kayit.close();
}

string Product::urunAdiGetir()
{

	return string(mUrunAdi);
}

string Product::urunKoduGetir()
{

	return mUrunKodu;
}

string Product::fiyatGetir()
{


	return mFiyat;
}

void Product::urunAdiAta(string urunAdi)
{
}

void Product::urunKoduAta(string urunkodu)
{
}

void Product::fiyatAta(int fiyat)
{
}

string Product::urunKoduUret()
{

	string urunkodu = "";
	for (int i = 0; i < 4; i++)
	{
		urunkodu += '0' + rand() % 10;
	}
	return urunkodu;
}

string Product::fiyatUret()
{
	string fiyat = "";
	for (int i = 0; i < 3; i++)
	{
		fiyat += '0' + rand() % 10;
	}
	return fiyat;
}
