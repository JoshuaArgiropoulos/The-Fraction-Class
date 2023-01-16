#include <iostream>
using namespace std;

class Fraction {
    private:
        //Private variables 
        int n;
        int d;

    public:
        //Constructors functions
        Fraction();
        Fraction(int n);
        Fraction(int n, int d);

        //Accessors functions
        int numerator()const ;
        int denominator()const;

        Fraction operator+(Fraction Frac1);
        Fraction operator-(Fraction Frac1);
        Fraction operator*(Fraction Frac1);
        Fraction operator/(Fraction Frac1);
        Fraction operator-();
        Fraction operator++(int);
        Fraction operator++();
        Fraction operator+=(Fraction Frac1);
        bool operator==(Fraction Frac1);
        bool operator!=(Fraction Frac1);
        bool operator>(Fraction Frac1);
        bool operator>=(Fraction Frac1);
        bool operator<(Fraction Frac1);
        bool operator<=(Fraction Frac1);
        bool operator>(int num);

        friend istream &operator>>(istream &in, Fraction &Frac1);    
};

class FractionException {
    private:
        string message;

    public:
        FractionException(const string &message);
        string &what();
};
ostream &operator<<(ostream &out, const Fraction &f);
istream &operator>>(istream &in, Fraction &f);

bool operator<(int num, Fraction Frac1);
Fraction operator+(int num, Fraction Frac1);
Fraction operator-(int num, Fraction Frac1);
Fraction operator*(int num, Fraction Frac1);
Fraction operator/(int num, Fraction Frac1);


