// Програма, която дефинира и инициализира променливи от различни типове,
// включително и указатели и извежда стойностите им на екрана  с операция <<

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

// Извеждат се символите от низа, към който сочи указателят str	
	cout << endl << str << endl;

// Извеждат се стойностите на променливите ch и а
	cout << endl << ch << "=" << a << endl;

// Извежда се стойността на променливата b
	cout << endl << b << endl;

	float *ptrb = &b;
// Извеждат се два 16-тични адреса - на променливата а и на променливата b
	cout << endl << &a << " , " << ptrb << endl;

// Извежда се адресът на указателя *str към символен низ
// (задължително преобразуване в тип void)
	cout << endl << (void *)str << endl;

} // end main