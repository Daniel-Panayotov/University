// ��������, ����� �� ������� ������������ �� ����� �� ��������� - 
// ������ �����, � �� ��������� ������������ �� ������� �� ��������
// �� ������������� �������. ������� � ���������� �������� �� ��
// ������� �� ������ � �������� ������, ���� �� ��������� ������������.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void main()
{
	double x, y, z;

	cout << "Vavedete (x,y) koordinati na to4ka: ";
	cin >> x >> y;
	z = sqrt(x*x+y*y);

	cout << endl << "Format po podrazbirane";
	cout << endl << "Pri x = " << x << " i y = " << y;
	cout << endl << "Razstoianieto e = " << z << endl;

	cout << endl << "Nauchen format";
// ������������� setiosflags() ���������� ����� scientific � 1 �
// ������ ����������� �� ������� � ������ ������
	cout << setiosflags(ios::scientific);
	cout << endl << "Pri x = " << x << " i y = " << y;
	cout << endl << "Razstoianieto e = " << z << endl;

	cout << endl << "Format s fiksirana tochka";
// ������������� setiosflags() ���������� ����� fixed � 1 �
// ������ ������ � ��������� �����
	cout << setiosflags(ios::fixed);
	cout << endl << "Pri x = " << x << " i y = " << y;
	cout << endl << "Razstoianieto e = " << z << endl;

	cout << endl << "Format - tochnost i shirina na izhodnoto pole";
// ������������� setprecision() ������ ������� � ���� ����� ����
// ����������� ����� ��� ����������� � ��������� ����� ��� � 
// ���� ������� ������� �� ��������� ��� ������ ������
	cout << setprecision(3);
	cout << endl << "Pri x = " << setw(12) << x << " i y = " << setw(12) << y;
	cout << endl << "Razstoianieto e = " << setw(12) << z << endl;

// ������������� setw() �� ������� �� ����� ������������ �� ������� ������
// ����������� �� ������ � ������ �� �� ������ �� ����� ������� ��������
// �������� ��� ��������� �� �����

} //end main