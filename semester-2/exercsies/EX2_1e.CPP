// ��������, ����� �������� � ������������ ���������� �� �������� ������,
// ����������� � ��������� � ������� ����������� �� �� ������  � �������� <<

#include <iostream>

using std::cout;
using std::endl;

void main( )
{
	int		a=65;
	char	ch='a';
	float	b=8.45;
    const char	*str = "The results are:";

	cout << endl << "This is an example of output stream" << endl;

// �������� �� ��������� �� ����, ��� ����� ���� ���������� str	
	cout << endl << str << endl;

// �������� �� ����������� �� ������������ ch � �
	cout << endl << ch << "=" << a << endl;

// ������� �� ���������� �� ������������ b
	cout << endl << b << endl;

	float *ptrb = &b;
// �������� �� ��� 16-����� ������ - �� ������������ � � �� ������������ b
	cout << endl << &a << " , " << ptrb << endl;

// ������� �� ������� �� ��������� *str ��� �������� ���
// (������������ ������������� � ��� void)
	cout << endl << (void *)str << endl;

} // end main