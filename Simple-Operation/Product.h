#pragma once
#pragma once
#include<string>
using namespace std;

class Product
{
private:

	string	mUrunKodu;
	string	mUrunAdi;
	string	mFiyat;
public:
	Product();

	void	kaydet();

	string	urunAdiGetir();
	string	urunKoduGetir();
	string		fiyatGetir();

	void	urunAdiAta(string urunAdi);
	void	urunKoduAta(string urunkodu);

	void	fiyatAta(int fiyat);

	string	urunKoduUret();
	string  fiyatUret();
};

