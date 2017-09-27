#pragma once

#include<string>
using namespace std;
class Control
{
private:
	string Tcno;
public:


	void tavanCiz(int genislik);

	void zeminCiz(int genislik);

	void araCiz(int genislik, string yazi);

	void ayracCiz(int genislik);

	void  anaMenuCiz();

	void musteriMenuCiz();

	void yoneticiMenuCiz();

	void musteriListele();

	void musteriPaneli();

	void urunListele();

	void yoneticiPaneli();

	void musteriElke();

	void musteriSil(string tcno);

	void urunEkle();

	void urunSil(string urunkod);

	void islemListele(string tcno1);

	void islemSil(string tcno);




	/*
	*	istenilen fonksiyonlar eklenebilir.
	*
	*/
};

