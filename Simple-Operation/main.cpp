#include <iostream>
#include <string>
#include "Control.h"
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
	srand(time(0));
	int secim;
	Control k1;

	while (true)
	{
		system("cls");
		k1.anaMenuCiz();
		cout << "Secim...:";
		cin >> secim;
		if (secim == 1)
		{
			k1.musteriMenuCiz();
		}
		if (secim == 2)
		{
			k1.yoneticiMenuCiz();
		}
		if (secim == 3)
		{
			break;
		}
		system("pause");

	}

	return 0;
}