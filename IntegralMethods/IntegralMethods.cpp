#include <iostream>
using namespace std;

class Equation {
public:
	double func(double x);
};

class IntegralMethods :virtual Equation {
public:
	double integrateTrapeze(double a, double b, int precision);
	double integrateRectangle(double a, double b, int precision);
	double integrateSimpson(double a, double b, int n);
	double integrateGaussQuadratureTwo(double a, double b);
	double integrateGaussQuadratureFour(double a, double b);
};


double Equation::func(double x) {
	//return 3 * x * x * x;
	return 9 * cos(x);
	//return (tan(x) * cos(x)) / (x * x);
}


double IntegralMethods::integrateRectangle(double a, double b, int precision) {
	if (b < a) {
		double temp = a;
		a = b;
		b = temp;
	}

	double result = 0.0,
		dx = (b - a) / precision,
		at = a;
	for (int i = 0; i < precision; i++) {
		result += func(at);
		at += dx;
	}

	return result * dx;
}

double IntegralMethods::integrateTrapeze(double a, double b, int precision) {
	if (b < a) {
		double temp = a;
		a = b;
		b = temp;
	}

	double result = 0.0,
		dx = (b - a) / precision,
		at = a;
	for (int i = 0; i < precision; i++) {
		result += (func(at) + func(at + dx));
		at += dx;
	}
	return result * dx * 0.5;
}

double IntegralMethods::integrateSimpson(double a, double b, int n)
{
	if (b < a) {
		double temp = a;
		a = b;
		b = temp;
	}
	if (n == 0)	n = 1;

	double sum = 0.0,
		step = (b - a) / static_cast<double>(n),
		from = a,
		to = a + step;

	for (int i = 0; i < n; i++) {
		sum += (to - from) / 6.0 * (func(from) + 4.0 * func((from + to) / 2.0) + func(to));
		from = to;
		to += step;
	}
	return sum;
}

double IntegralMethods::integrateGaussQuadratureTwo(double a, double b)
{
	if (b < a) {
		double temp = a;
		a = b;
		b = temp;
	}

	double x[3] = { -0.774597, 0.0, 0.774597 },
		A[3] = { 5.0 / 9.0, 8.0 / 9.0, 5.0 / 9.0 };
	double avrg = (a + b) * 0.5,
		length = (b - a) * 0.5,
		sum = 0.0;

	for (int k = 0; k < 3; ++k) {
		double t = avrg + length * x[k];
		sum += A[k] * func(t);
	}

	return sum * length;
}

double IntegralMethods::integrateGaussQuadratureFour(double a, double b)
{
	if (b < a) {
		double temp = a;
		a = b;
		b = temp;
	}

	double x[5] = { -0.906180, -0.538469, 0.0, 0.538469 , 0.906180 },
		A[5] = { 0.236927, 0.478629, 0.568889, 0.478629, 0.236927 };
	double avrg = (a + b) * 0.5,
		length = (b - a) * 0.5,
		sum = 0.0;

	for (int k = 0; k < 5; ++k) {
		double t = avrg + length * x[k];
		sum += A[k] * func(t);
	}

	return sum * length;
}


int main()
{
	double a, b;
	int precision;
	//cout << "Funkcja: 3 * x * x * x" << endl;
	cout << "Funkcja: 9 * cos(x) " << endl;
	//cout << "Funkcja: (tan(x) * cos(x)) / (x * x) " << endl;

	cout << "Podaj przedzial calkowania:" << endl;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	cout << "Liczba przedzialow: ";
	cin >> precision;
	IntegralMethods integral;


	//cout << "Metoda prostokatow wynik: " << integral.integrateRectangle(a, b, precision) << endl;

	//cout << "Metoda trapezow wynik: " << integral.integrateTrapeze(a, b, precision) << endl;


	cout << "Metoda Simpsona wynik: " << integral.integrateSimpson(a, b, precision) << endl;

	cout << "Metoda Gaussa (kwadratura dwuwezlowa) wynik: " << integral.integrateGaussQuadratureTwo(a, b) << endl;
	cout << "Metoda Gaussa (kwadratura dwuwezlowa) wynik: " << integral.integrateGaussQuadratureFour(a, b) << endl;
}
