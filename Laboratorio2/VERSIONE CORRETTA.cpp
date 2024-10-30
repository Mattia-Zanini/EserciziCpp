// Lab 2: Esercizio (#13, pp. 340-341 testo) - Revisione n°4

#include <iostream>

class Rational 
{                           

public:
   
	class Invalid{};

	Rational(); // default constructor
   
	Rational(int); // costructor accepting int and representing it in rational form
	
	int n() const {return num;}
	int d() const {return den;}
   
	Rational(int num, int den); // constructor accepting two ints
   
	Rational operator=(const Rational &);
   
	Rational operator+(const Rational &);
   
	Rational operator-(const Rational &);
   
	Rational operator*(const Rational &);
   
	Rational operator/(const Rational &);
	
	bool operator==(const Rational &hh);
	
	std::ostream& operator<<(std::ostream& os);
   
	void print_to_double();
	

private:

	int num;

	int den;

};

Rational::Rational()
		: num {0}, den {1}
{
}

Rational::Rational(int n, int d) // Eccezione per denominatore nullo
		: num {n}, den {d}
{   
	if (den == 0) throw Invalid{};
}
	

Rational::Rational (int ww)
{
		num = ww;
		den = 1;
}


Rational Rational::operator=(const Rational& e)
{
       
		Rational t;
		
        num = e.num;
		den = e.den;
        
        return t;
}



Rational Rational::operator+(const Rational& a) 
{
	
		Rational t;

		t.num = a.num * den + a.den * num;
		t.den = a.den * den;
   
		return t;
}


Rational Rational::operator-(const Rational& s)
{
	
		Rational t;

		t.num = s.den * num - den * s.num;
		t.den = s.den * den;
   
		return t;
}


Rational Rational::operator*(const Rational& m)
{
	
		Rational t;

		t.num = m.num * num;
		t.den = m.den * den;
   
		return t;
}


Rational Rational:: operator/(const Rational& v) 
{
   
		Rational t;

		t.num = v.den * num;
		t.den = den * v.num;
   
		return t;
}


void Rational::print_to_double() 
{  
  
		std::cout << double(num) / double(den);
	  
}

bool Rational::operator == (const Rational &c)
{ 
		if (num*c.den == den*c.num) 
		
		return true; 
		
		return false; 
} 

std::ostream& operator<<(std::ostream& os, Rational uu)
{
	os << uu.n() << "/" << uu.d();
	return os;
}



int main() 
{	
	Rational x(3,4);
	
	Rational y(1,2);
	
	Rational z;
	
	Rational k; // Variabile per test assegnamento
	
	Rational vv = 100; // Variabile test costruttore int
	
	Rational vvv(3,4); // Variabile test uguaglianza / disuguaglianza.
	
	
	std::cout << "TEST COSTRUTTORE DA INTERO A RAZIONALE: \n";
	
	std::cout << vv;
	
	std::cout << "\n\n";
	
		
	std::cout << "I numeri razionali che rappresentano i fattori delle operazioni sono: \n"; // Iéntestazione test operazioni
	std::cout << x; std::cout << " e "; std::cout << y; std:: cout<< "\n";
	std::cout << "\n";
	
	
	std::cout << "TEST OVERLOADING ASSEGNAMENTO: \n";
	k = y; 
	
	std::cout << k;
	
	std::cout << "\n\n";
	

	std::cout << "SOMMA: \n";
	std::cout << x;
	
	std::cout << " + ";
	
	std::cout << y;
	
	z = x + y;
	
	std::cout << " = ";
	
	std::cout << z;
	
	std::cout << "\n";
	
	std::cout << z;
	
	std::cout << " = ";
	
	z.print_to_double();
	
	std::cout << "\n\n";
	
	
	std::cout << "SOTTRAZIONE: \n";
	std::cout << x;
	
	std::cout << " - ";
	
	std::cout << y;
	
	z = x - y;
	
	std::cout << " = ";
	
	std::cout << z;
	
	std::cout << "\n";
	
	std::cout << z;
	
	std::cout << " = ";
	
	z.print_to_double(); 
	
	std::cout << "\n\n";



	std::cout << "MOLTIPLICAZIONE: \n";
	std::cout << x;
	
	std::cout << " * "; 
	
	std::cout << y;
	
	z = x * y;
	
	std::cout << " = ";
	
	std::cout << z;
	
	std::cout << "\n";
	
	std::cout << z;
	
	std::cout << " = ";
	
	z.print_to_double(); 
	
	std::cout << "\n\n";
	
	
	
	std::cout << "DIVISIONE: \n";
	std::cout << x;
	
	std::cout << " / "; 
	
	std::cout << y;
	
	z = x / y;
	
	std::cout << " = ";
	
	std::cout << z;
	
	std::cout << "\n";
	
	std::cout << z;
	
	std::cout << " = "; 
	
	z.print_to_double();
	
	std::cout << "\n\n";
	
	
	
	std::cout << "SOMMA RATIONAL + INT: \n";
	std::cout << x;
	
	std::cout << " + ";
	
	std::cout << vv;
	
	z = x + vv;
	
	std::cout << " = ";
	
	std::cout << z;
	
	std::cout << "\n";
	
	std::cout << z;
	
	std::cout << " = ";
	
	z.print_to_double();
	
	std::cout << "\n\n";
	
	
	std::cout << "SOMMA int + rat: \n";
	std::cout << vv;
	
	std::cout << " + ";
	
	std::cout << x;
	
	z = vv + x;
	
	std::cout << " = ";
	
	std::cout << z;
	
	std::cout << "\n";
	
	std::cout << z;
	
	std::cout << " = ";
	
	z.print_to_double();
	
	std::cout << "\n\n";
	
	
	std::cout << "TEST DISUGUAGLIANZA: \n";
	std::cout << x; std::cout << " = "; std::cout << y; std::cout << " ?\n";
	
	if (x == y)
	{ std::cout << "I due numeri razionali sono uguali!\n"; }
	else
	{ std::cout << "I due numeri razionali NON sono uguali!\n"; };
	
	std::cout << "\n\n";
	
	std::cout << "TEST UGUAGLIANZA: \n";
	std::cout << x; std::cout << " = "; std::cout << vvv; std::cout << " ?\n";
	
	if (x == vvv)
	{ std::cout << "I due numeri razionali sono uguali!\n"; }
	else
	{ std::cout << "I due numeri razionali NON sono uguali!\n"; };
	
	std::cout << "\n\n";	
	
   return 0;
}
