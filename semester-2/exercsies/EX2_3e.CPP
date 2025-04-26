// Програма, която да въвежда координатите на точка от равнината - 
// реални числа, и да изчислява разстоянието от точката до началото
// на координатната система. Данните и полученият резултат да се
// изведат на екрана в различен формат, като се използват манипулатори.

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
// Манипулаторът setiosflags() установява флага scientific в 1 и
// задава представяне на числата в научен формат
	cout << setiosflags(ios::scientific);
	cout << endl << "Pri x = " << x << " i y = " << y;
	cout << endl << "Razstoianieto e = " << z << endl;

	cout << endl << "Format s fiksirana tochka";
// Манипулаторът setiosflags() установява флага fixed в 1 и
// задава формат с фиксирана точка
	cout << setiosflags(ios::fixed);
	cout << endl << "Pri x = " << x << " i y = " << y;
	cout << endl << "Razstoianieto e = " << z << endl;

	cout << endl << "Format - tochnost i shirina na izhodnoto pole";
// Манипулаторът setprecision() задава точност в брой знаци след
// десетичната точка при представяне с фиксирана точка или в 
// брой значещи разряди на мантисата при научен формат
	cout << setprecision(3);
	cout << endl << "Pri x = " << setw(12) << x << " i y = " << setw(12) << y;
	cout << endl << "Razstoianieto e = " << setw(12) << z << endl;

// Манипулаторът setw() за разлика от други манипулатори не променя трайно
// състоянието на потока и трябва да се указва за всяка отделна операция
// вмъкване или извличане за поток

} //end main