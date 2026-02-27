#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here
bool ComplexNumber::operator==(const ComplexNumber &x){
	if( real == x.real && imag == x.imag) return true;
	else return false;
}

bool operator==(double n,const ComplexNumber &x){
	if( n == x.real && x.imag == 0.0) return true;
	else return false;
}

ComplexNumber operator+(double n, const ComplexNumber &x){
	return ComplexNumber(n + x.real , x.imag);
}

ComplexNumber operator-(double n, const ComplexNumber &x){
	return ComplexNumber(n - x.real, -x.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &x){
	return ComplexNumber((real * x.real) - (imag * x.imag), (real * x.imag) + (imag * x.real));}

ComplexNumber operator*(double n, const ComplexNumber &x){
	return ComplexNumber(n * x.real, n * x.imag);}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &x){
	double denominator = pow(x.real, 2) + pow(x.imag, 2); 
    return ComplexNumber(((real * x.real) + (imag * x.imag)) / denominator, 
                         ((imag * x.real) - (real * x.imag)) / denominator);
}

ComplexNumber operator/(double n, const ComplexNumber &x){
	double denominator = pow(x.real, 2) + pow(x.imag, 2);
    return ComplexNumber((n * x.real) / denominator, (-n * x.imag) / denominator);
}

double ComplexNumber::abs(){
	return sqrt(pow(real,2) + pow(imag,2));
}

double ComplexNumber::angle(){
	return atan2(imag, real) * 180 / M_PI ;
}

ostream & operator<<(ostream &os, const ComplexNumber &x){
	if(x.imag > 0  && x.real != 0) return os << x.real << '+' << x.imag <<'i';
	else if (x.real == 0 && x.imag != 0) return os << x.imag << 'i';
	else if( x.imag == 0 && x.real != 0) return os << x.real;
	else if (x.real == 0 && x.imag == 0) return os << 0;
	else return os << x.real << x.imag <<'i';
}

	int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





