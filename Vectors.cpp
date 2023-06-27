#include<iostream>
#include<math.h>
using namespace std;
class VectorType
{
	double* x;
	double* y;
	double* z;
public:
	VectorType(double a = 0, double b = 0, double c = 0) {
		x = new double;
		y = new double;
		z = new double;
		*x = a;
		*y = b;
		*z = c;
	}
	friend double operator*(VectorType, VectorType);
	double length();
	friend double Angle(VectorType, VectorType);
	VectorType(const VectorType& a) {
		x = new double;
		y = new double;
		z = new double;
		*x = *a.x;
		*y = *a.y;
		*z = *a.z;
	}
	friend bool operator==(VectorType, VectorType);
	friend bool operator!=(VectorType, VectorType);
	friend ostream& operator<<(ostream&, VectorType&);
	friend istream& operator>>(istream&, VectorType&);
	VectorType operator+(const VectorType);
	VectorType operator-(const VectorType);
	VectorType operator=(const VectorType& a) {
		x = new double;
		y = new double;
		z = new double;
		*x = *a.x;
		*y = *a.y;
		*z = *a.z;
		return*this;
	}
	VectorType operator--();
	VectorType operator++();
	VectorType operator--(int);
	VectorType operator++(int);
	~VectorType() {
		/*cout << "Destructors called for " << *x << " " << *y << " " << *z << endl;*/
		delete x;
		delete y;
		delete z;
	}
};
VectorType VectorType::operator--(int a) {
	VectorType temp = *this;
	(*(x))--;
	(*(y))--;
	(*(z))--;
	return temp;
}
VectorType VectorType::operator++(int a) {
	VectorType temp = *this;
	(*(x))++;
	(*(y))++;
	(*(z))++;
	return temp;
}
VectorType VectorType::operator--() {
	--(*(x));
	--(*(y));
	--(*(z));
	return *this;
}
VectorType VectorType::operator++() {
	++(*(x));
	++(*(y));
	++(*(z));
	return *this;
}
VectorType VectorType::operator-(VectorType a) {
	VectorType temp;
	(*temp.x) = *(x)-*(a.x);
	(*temp.y) = *(y)-*(a.y);
	(*temp.z) = *(z)-*(a.z);
	return temp;
}
VectorType VectorType::operator+(VectorType a) {
	VectorType temp;
	(*temp.x) = *(x)+*(a.x);
	(*temp.y) = *(y)+*(a.y);
	(*temp.z) = *(z)+*(a.z);
	return temp;
}
ostream& operator<<(ostream& a, VectorType& b) {
	a << "The x dimension: " << *(b.x) << endl;
	a << "The y dimension: " << *(b.y) << endl;
	a << "The z dimension: " << *(b.z) << endl;
	return a;
}
istream& operator>>(istream& a, VectorType& b) {
	cout << "Enter the x dimension: ";
	a >> *(b.x);
	cout << "Enter the y dimension: ";
	a >> *(b.y);
	cout << "Enter the z dimension: ";
	a >> *(b.z);
	return a;
}
bool operator==(VectorType a, VectorType b) {
	return((*(a.x) == *(b.x)) && (*(a.y) == *(b.y)) && (*(a.z) == *(b.z)));
}
bool operator!=(VectorType a, VectorType b) {
	return((*(a.x) != *(b.x)) || (*(a.y) != *(b.y)) || (*(a.z) != *(b.z)));
}
double Angle(VectorType a, VectorType b) {
	return((180 / 3.142) * (acos((a * b) / (a.length() * b.length()))));
}
double VectorType::length() {
	return(sqrt(pow(*(x), 2) + pow(*(y), 2) + pow(*(z), 2)));
}
double operator*(VectorType a, VectorType b) {
	return((*(a.x)) * (*(b.x)) + (*(a.y)) * (*(b.y)) + (*(a.z)) * (*(b.z)));
}
int main() {
	VectorType a;
	VectorType b;
	VectorType c;
	cout << "Enter the dimensions of FIRST VECTOR\n" << endl;
	cin >> a;
	cout << endl;
	cout << "Enter the dimensions of SECOND VECTOR\n" << endl;
	cin >> b;
	cout << endl;
	cout << "Length of FIRST VECTOR: ";
	cout << a.length() << endl;
	cout << "Length of SECOND VECTOR: ";
	cout << b.length() << endl;
	cout << endl;
	cout << "Angle between BOTH vectors is: ";
	cout << Angle(a, b) << endl;
	cout << endl;
	cout << "ADDITION of vectors\n";
	c = a + b;
	cout << c << endl;
	cout << "SUBSTRACTION of vectors\n";
	c = a - b;
	cout << c << endl;
	cout << "VECTOR PRODUCT: " << a * b;
	cout << endl;
}