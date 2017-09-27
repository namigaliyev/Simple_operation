#pragma once
#pragma once
#include <string>

using namespace std;
class operation
{
private:
	string  mIslemKodu;
	string	mUrunKodu;
	string  mMusteriTcNo;

public:
	operation();

	string	urunKoduGetir();

	string	tcNoGetir();

	string	islemKoduGetir();

	void	urunKoduAta(string kod);

	void	tcNoAta(string tcno);

	void	kaydet();

	string islemKoduUret();


};

#pragma once

