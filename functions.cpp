#include <iostream>
#include "f_lib.hpp"
#include <math.h>

Complex::Complex() {
	real = 0;
	imag = 0;
}

Complex::Complex(double input){
	real = input;
	imag = 0;
}

Complex::Complex(double input1, double input2){
	real = input1;
	imag = input2;
}

Complex::~Complex(){
}

void Complex::print(){
	std::cout << real << " "  <<  imag << std::endl;
}

Complex Complex::add (Complex input){
	input.real = real + input.real;
	input.imag = imag + input.imag;

	return input;
}

Complex Complex::sub(Complex input){
	input.real = real - input.real;
	input.imag = imag - input.imag;

	return input;
}

Complex Complex::mult(Complex input){

	Complex temp = {(real * input.real) + (imag * input.imag * -1), (imag * input.real) + (real * input.imag)};

	return temp;
}

Complex Complex::div(Complex input){

	double denom = input.magnitude() * input.magnitude();
	Complex temp = {(real * input.real) + (imag * input.imag), (imag * input.real) + (real * input.imag * -1)};
	
	if (denom !=0){
		temp.real /=denom;
		temp.imag /=denom;
	} else {
		std::cout << "division failed";
		temp = {0,0};
	}

	return temp;
}

Complex Complex::conj(Complex input){
	input.imag *=-1;
	return input;
}

Complex Complex::operator+(Complex input){
	input.real = real + input.real;
	input.imag = imag + input.imag;

	return input;
}

Complex Complex::operator-(Complex input){
	input.real = real - input.real;
	input.imag = imag - input.imag;

	return input;
}

Complex Complex::operator*(Complex input){
	Complex temp;
	temp = {(real * input.real) + (imag * input.imag * -1), (imag * input.real) + (real * input.imag)};

	return temp;
}

Complex Complex::operator/(Complex input){
	double denom = input.magnitude() * input.magnitude();
	Complex temp = {(real * input.real) + (imag * input.imag), (imag * input.real) + (real * input.imag * -1)};
	
	if (denom !=0){
		temp.real /=denom;
		temp.imag /=denom;
	} else {
		std::cout << "division failed";
		temp = {0,0};
	}

	return temp;
}

Complex Complex::operator=(Complex input){
	real = input.real;
	imag = input.imag;

	return *this;
}

std::ostream &operator<< (std::ostream &output, const Complex &para) {
	output << para.real << " " << para.imag;

	return output;
}

std::istream& operator>> (std::istream &input, const Complex &para){
	input >> para.real >> para.imag;
	
	return input;
}

double Complex::magnitude(){
	return sqrt((real * real) + (imag * imag));
}

double Complex::phase(){
	double ph = atan(imag/real);
	ph = ph* (180/M_PI);
	return (ph<0) ? -ph : ph;
}
