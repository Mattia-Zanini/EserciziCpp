// Lab 3 - Esercizio 4 Rev.0 - 

#include <iostream>


class MyVector {
private:
    double* elem;
    int sz;

public:

	class Invalid{};
	
	int size() const
	{ return sz; }

    MyVector(double*, int);

    // Overloading [] operator to access elements in array
    // style
    double& operator[](int);

    // Utility function to print contents
    void safe_get() const;
	
	void safe_set(double);
	
	~MyVector()
	{ delete[] elem; }
	
};


MyVector::MyVector(double* p = nullptr, int s = 0)
{
    sz = s;
    elem = p;
    if (s != 0) {
        elem = new double[s];
        for (int i=0; i < s; i++)
            elem[i] = p[i];
    }
	else std::cout << "ATTENZIONE! Lunghezza vettore = 0! Si prega di riavviare il programma!\n";
}


// Implementation of [] operator. This function must return
// a reference as array element can be put on left side
double& MyVector::operator[](int k)
{
    if (k >= sz) {
        std::cout << "ATTENZIONE! Superato il limite del vettore! Si prega di riavviare il programma!\n";
		throw Invalid{};

    }
	
	else if (k <= 0) {
        std::cout << "ATTENZIONE! Superato il limite del vettore! Si prega di riavviare il programma!\n";
		throw Invalid{};

    } 
	
	else std::cout << "Scrittura elemento vettore ento i limiti! Grazie!\n";
    return elem[k];
}


void MyVector::safe_get() const //
{
    for (int i = 0; i < sz; i++ )
        std::cout << elem[i] << " ";
		std::cout << std::endl;
}


void MyVector::safe_set(double u) {
	
	for (int i=0; i < sz; i++) {
		elem[i] = u;}
	
}

int main()
{
    double a[] = { 1.5, 2.5, 3.5, 4.5 };
	int h = sizeof(a)/sizeof(a[0]);
    MyVector vec1(a, h);
	vec1.safe_get();
    vec1[2] = 8.8; // Test overloading dentro il limite
    vec1.safe_set(9.9); // Test funzione safe set
	vec1.safe_get();
    vec1[10] = 8.5; // Test fuori limite
	
	return 0;
}
