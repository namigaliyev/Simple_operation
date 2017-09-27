#include "operation.h"
#include <iostream>
#include <fstream>

operation::operation()
{

	mIslemKodu = islemKoduUret();


}
void operation::kaydet()
{
	fstream kayit;

	kayit.open("Islemler.txt", ios::in | ios::out | ios::app);

	if (kayit.is_open() == true)
	{
		kayit << islemKoduGetir() << " " << urunKoduGetir()
			<< " " << tcNoGetir() << endl;


	}
	kayit.close();
}

string operation::islemKoduGetir()
{
	return mIslemKodu;
}
string operation::urunKoduGetir()
{
	return mUrunKodu;
}
void operation::tcNoAta(string tcno)
{
	mMusteriTcNo = tcno;
}
string operation::tcNoGetir()
{
	return mMusteriTcNo;
}

void operation::urunKoduAta(string kod)
{
	mUrunKodu = kod;
}

string operation::islemKoduUret()
{
	string islemkodu = "";
	for (int i = 0; i < 4; i++)
	{
		islemkodu += '1' + rand() % 9;
	}
	return islemkodu;

}
