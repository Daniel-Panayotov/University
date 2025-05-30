// ��������, ����� �� ������� ���������� �� ��� ����� �� ������, 
// ����������� �� �������� �����. �� �� ��������� ������������ �� ������������ 
// ������ �� ��������� �� �����, � ����� �� �������� ��������, 
// �������� � ��������� �� ��-����� �� ����������� ���� �������.

#include <iostream>
#include <iomanip>		// ���������� �� ��������������
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
// ����� ���� � ���� � ������ 10 �������, �� 1 ���
// ���������� �� ������������ setw() �� �������� �������� �� ���� �� ���������
	for (int i=0; i<3; i++)
		cout << setw(10) << *(color+i) << endl;
	cout << endl;

	cout << "Left side adjustment:" << endl;
// ������������ �����
// ������������� setioflags() � �������� ����� left ���� �� 
// ������������ �� ����� � 1 � ������ ������������ �����
	cout << setiosflags(ios::left);
	for (int i=0; i<3; i++)
		cout << setw(10) << *(color+i) << endl;
	cout << endl;

	cout << "Right side adjustment:" << endl;
// ������������ ������
// ������������� setioflags() � �������� ����� right ���� �� 
// ������������ �� ����� � 1 � ������ ������������ ������
	cout << setiosflags(ios::right);
	for (int i=0; i<3; i++)
		cout << setw(10) << *(color+i) << endl;
	cout << endl;

	cout << "Zapalvane na praznite pozicii sas simvol *:" << endl;
// ��������� �� �������� ������� ��� ������ *
// ������������� setfill() ������ ��������� � ������� ������ �� 
// �������� ������� � ������ �� ���������
	for (int i=0; i<3; i++)
		cout << setw(10) << setfill('*') << *(color+i) << endl;
	cout << endl;

	char text[MAXLEN];
	int len;
	for (int i=0; i<3; i++)
	{
		cout << endl << "Vavete text: ";
		
		// ���������� �� ������������ setw() � ������ �����
		cin >> setw(MAXLEN) >> text;
// ��� ��������� �� ������ ���������� ��������� ���������� �����,
// "���������" ���� �� ������ �� ������� � ������ �� ������ cin � ��
// �������� ����������� ��� ���������� �������� �������� � cin.
		len = strlen(text);
		cout << "Vavedeniat text e: " << text << endl;

		// ����������� dec
		// � ������� ���� ��������� �����
		cout << "s dalzina kato desetichno chislo " << dec << len << endl;

		// ����������� oct
		// � ������� ���� ������� �����
		cout << "s dalzina kato osmichno chislo " << oct << len << endl;

		// ����������� hex
		// � ������� ���� 16-����� �����
		cout << "s dalzina kato 16-tichno chislo " << hex << len << endl;

		cout << dec;	// ������� ��� ��������� ������ �������
	}// end for

} // end main