#pragma once
#pragma once
#include<string>
#include "Date.h"
using namespace std;




class Client
{
private:
	string mIsim;
	string mSoyisim;
	string mTcno;
	string mTelno;
	Date  mDogumTarihi;

public:

	string	tcnouret();
	string	telnoUret();
	Client();
	void kaydet();
	string	tcnoGetir();
	string	telnoGetir();
	string	isimGetir();
	string	soyisimGetir();
	Date	tarihGetir();

	void isimAta(string isim);
	void telnoAta(string telno);
	void tcnoAta(string tcno);
	void soyisimAta(string soyisim);
	void tarihAta(Date tarih);
};


