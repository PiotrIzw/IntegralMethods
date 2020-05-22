#include <iostream>
using namespace std;
class Equation {
public:
	double func(double x);
};

class IntegralTrapeze :virtual Equation {
public:

	double integrateTrapeze(double a, double b, int precision);
};

class IntegralRectangle :virtual Equation {
public:
	double integrateRectangle(double a, double b, int precision);
};



double Equation::func(double x) {
	//return 3 * x * x * x;
	//return 9 * cos(x);
	return (tan(x) * cos(x)) / (x * x);
}


double IntegralRectangle::integrateRectangle(double a, double b, int precision) {
	if (b < a) {
		double temp = a;
		a = b;
		b = temp;
	}

	double result = 0.0,
		dx = (b - a) / precision,
		at = a;
	for (unsigned int i = 0; i < precision; i++) {
		result += func(at);
		at += dx;
	}

	return result * dx;
}

double IntegralTrapeze::integrateTrapeze(double a, double b, int precision) {
	if (b < a) {
		double temp = a;
		a = b;
		b = temp;
	}

	double result = 0.0,
		dx = (b - a) / precision,
		at = a;
	for (unsigned int i = 0; i < precision; i++) {
		result += (func(at) + func(at + dx));
		at += dx;
	}
	return result * dx * 0.5;
}

int main()
{
	double a, b;
	int precision;
	//cout << "Funkcja: 3 * x * x * x" << endl;
	//cout << "Funkcja: 9 * cos(x) " << endl;
	cout << "Funkcja: (tan(x) * cos(x)) / (x * x) " << endl;

	cout << "Podaj przedzial calkowania:" << endl;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	cout << "Liczba przedzialow: ";
	cin >> precision;

	IntegralRectangle rIntegral;
	cout << "Metoda prostokatow wynik: " << rIntegral.integrateRectangle(1, 2, 5) << endl;

	IntegralTrapeze tIntegral;
	cout << "Metoda trapezow wynik: " << tIntegral.integrateTrapeze(1, 2, 5) << endl;
}
