//Made by Ihor Paprotskyi, SE, 2nd year
#include <iostream>
#include "Array.h"
#include "Complex.h"
using namespace std;

int main()
{
	cout<<"= = = = Testing double = = = ="<<endl;
	Array<5, double> aDouble;
	for (size_t i = 0; i < aDouble.size(); ++i)
		aDouble[i] = i*5;
	cout <<"Result: "<<aDouble << endl;

	Array<5, double> bDouble(aDouble);
	cout << endl;
	bDouble = bDouble;
	cout << endl;

	Array<5, double> cDouble;
	cDouble = aDouble;
	cout << endl;
	
	try
	{
		cout << "Trying to change not existing index of our array: " << endl;
		aDouble[6] = 0;
	}
	catch (const Array<5, double>::BadArray& b)
	{
		b.diagnose();
	}

	cout << "= = = = =Testing COMPLEX= = = = = = = = " << endl;
	try
	{
		Array<4, Complex> arrComplex;
		arrComplex[0] = Complex(1, 2);
		arrComplex[1] = Complex(2, 3);
		arrComplex[2] = Complex(3, 4);
		arrComplex[3] = Complex(5, 6);
		cout << arrComplex << endl;

		//testing operator[]
		Complex sum(0,0);
		for (size_t j = 0; j < arrComplex.size(); ++j)
		{
			sum += arrComplex[j];
		}
		cout << "Result of sum through all iterations: "<< sum <<endl;

		Array<3, Complex> mComplex;
		mComplex[0] = Complex(1, 2);
		mComplex[1] = Complex(2, 3);
		mComplex[2] = Complex(3, 4);

		cout<<"Let's move: "<<endl;
		Array <3, Complex> n = testMove(mComplex);
		cout << endl;
	}
	catch (const Array<5, double>::BadArray& b)
	{
		b.diagnose();
	}




	return 0;
}