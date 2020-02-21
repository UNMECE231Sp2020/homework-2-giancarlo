#include <iostream>
class Complex {
	private:		
		double real;
		double imag;

	public:
	//Cons and Des	
		Complex();
		Complex(double input);
		Complex(double input1, double input2);
		~Complex();
	//Functions
		void print();
		Complex add(Complex input);
		Complex sub(Complex input);
		Complex mult(Complex input);
		Complex div(Complex input);
		Complex conj(Complex input);
		Complex operator+(Complex input);
		Complex operator-(Complex input);
		Complex operator*(Complex input);
		Complex operator/(Complex input);
		Complex operator=(Complex input);
		friend std::ostream& operator<<(std::ostream &output, const Complex &para);
		friend std::istream& operator>>(std::istream &input, const Complex &para);
		double magnitude();
		double phase();
};	
