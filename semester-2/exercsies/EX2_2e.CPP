// Програма, която да извежда названията на три цвята на екрана, 
// форматирани по различен начин. Да се използват манипулатори за ограничаване 
// полето на въвеждане на текст, с което се избягват грешките, 
// свързани с въвеждане на по-голям от предвидения брой символи.

#include <iostream>
#include <iomanip>		// декларации на манипулаторите
#include <cstring>

#define MAXLEN 20

using namespace std;

void main()
{
	const char *color[3] = {"red", "green", "blue"};

	cout << "Bez formatirane (po podrazbirane):" << endl;
	for (int i=0; i<3; i++)
		cout << *(color+i);
	cout << endl;

	cout << endl << "Vseki cviat v pole s shirina 10 simvola, na 1 red:" << endl;
// Всеки цвят в поле с ширина 10 символа, на 1 ред
// Използване на манипулатора setw() за задаване ширината на поле за извеждане
	for (int i=0; i<3; i++)
		cout << setw(10) << *(color+i) << endl;
	cout << endl;

	cout << "Left side adjustment:" << endl;
// Подравняване вляво
// Манипулаторът setioflags() с аргумент флага left води до 
// установяване на флага в 1 и задава подравняване вляво
	cout << setiosflags(ios::left);
	for (int i=0; i<3; i++)
		cout << setw(10) << *(color+i) << endl;
	cout << endl;

	cout << "Right side adjustment:" << endl;
// Подравняване вдясно
// Манипулаторът setioflags() с аргумент флага right води до 
// установяване на флага в 1 и задава подравняване вдясно
	cout << setiosflags(ios::right);
	for (int i=0; i<3; i++)
		cout << setw(10) << *(color+i) << endl;
	cout << endl;

	cout << "Zapalvane na praznite pozicii sas simvol *:" << endl;
// Запълване на празните позиции със символ *
// Манипулаторът setfill() задава запълване с посочен символ на 
// празните позиции в полето за извеждане
	for (int i=0; i<3; i++)
		cout << setw(10) << setfill('*') << *(color+i) << endl;
	cout << endl;

	char text[MAXLEN];
	int len;
	for (int i=0; i<3; i++)
	{
		cout << endl << "Vavete text: ";
		
		// Използване на манипулатора setw() с входен поток
		cin >> setw(MAXLEN) >> text;
// Ако дължината на текста значително превишава заделената памет,
// "излишната" част от текста се запазва в буфера на потока cin и се
// използва автоматично при следващата операция вмъкване в cin.
		len = strlen(text);
		cout << "Vavedeniat text e: " << text << endl;

		// Манипулатор dec
		// с дължина като десетично число
		cout << "s dalzina kato desetichno chislo " << dec << len << endl;

		// Манипулатор oct
		// с дължина като осмично число
		cout << "s dalzina kato osmichno chislo " << oct << len << endl;

		// Манипулатор hex
		// с дължина като 16-тично число
		cout << "s dalzina kato 16-tichno chislo " << hex << len << endl;

		cout << dec;	// Връщане към десетична бройна система
	}// end for

} // end main